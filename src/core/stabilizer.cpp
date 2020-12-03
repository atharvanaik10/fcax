//
// Created by Atharva Naik on 2/12/20.
//
#include "core/stabilizer.h"

namespace fcax {

std::vector<cv::Mat>& operator>>(std::vector<cv::Mat> &frames,
                                 Stabilizer& stabilizer) {
  for(cv::Mat frame:frames) {
    cv::Mat grayed;
    //convert frames to grayscale (color is not needed to analyze movement)
    cvtColor(frame, grayed, cv::COLOR_BGR2GRAY);
    stabilizer.frames_.push_back(grayed);
  }
  return frames;
}

std::vector<cv::Mat> Stabilizer::Stabilize() {
  std::vector<cv::Mat> transforms;
  CalculateTransforms(transforms);
  std::cout<<"Calculated transforms"<<std::endl;

  std::vector<std::vector<double>> path = GetPathFromTransforms(transforms);
  std::cout<<"Calculated path transforms"<<std::endl;

  std::vector<std::vector<double>> smooth_path = Smoothen(path,
                                                          kSmoothingRadius);
  std::cout<<"Calculated smooth path"<<std::endl;

  std::vector<cv::Mat> smooth_transforms;
  std::cout<<"Calculated smooth transforms"<<std::endl;

  for(size_t i = 0; i < transforms.size(); i++) {
    double residual_x = smooth_path[i][0] - path[i][0];
    double residual_y = smooth_path[i][1] - path[i][1];
    double residual_angle = smooth_path[i][2] - path[i][2];


    smooth_transforms.push_back(GetTranformationMatrix(
        transforms[i].at<double>(0,2) + residual_x,
        transforms[i].at<double>(1,2) + residual_y,
        atan2(transforms[i].at<double>(1,0),
            transforms[i].at<double>(0,0)) + residual_angle));
  }

  return smooth_transforms;
}

cv::Mat Stabilizer::GetTranformationMatrix(double d_x, double d_y, double d_a) {
  //create empty matrix with type double
  cv::Mat matrix(2,3,CV_64F);
  //fill in matrix
  matrix.at<double>(0,0) = cos(d_a);
  matrix.at<double>(0,1) = -sin(d_a);
  matrix.at<double>(1,0) = sin(d_a);
  matrix.at<double>(1,1) = cos(d_a);
  matrix.at<double>(0,2) = d_x;
  matrix.at<double>(1,2) = d_y;
  return matrix;
}

void Stabilizer::CalculateTransforms(std::vector<cv::Mat> &transforms) {
  for(int i = 1; i < frames_.size(); i++) {
    std::vector<cv::Point2f> prev_feature_points;
    std::vector<cv::Point2f> curr_feature_points;

    cv::goodFeaturesToTrack(
        //image (grayscale)
        frames_[i-1],
        //vector to store feature points
        prev_feature_points,
        200,
        0.01,
        30);

    std::vector<uchar> status;
    std::vector<float> err;
    cv::calcOpticalFlowPyrLK(frames_[i-1],frames_[i],
                             prev_feature_points,curr_feature_points,
                             status,err);

    for(size_t k = 0; k < status.size(); k++) {
      if(!status[k]) {
        //source: https://stackoverflow.com/questions/875103/how-do-i-erase-an-element-from-stdvector-by-index
        prev_feature_points.erase(prev_feature_points.begin() + k);
        curr_feature_points.erase(curr_feature_points.begin() + k);
      }
    }

    cv::Mat transform = cv::estimateAffinePartial2D(prev_feature_points,
                                                    curr_feature_points);

    transforms.push_back(transform);

  }
}

std::vector<std::vector<double>> Stabilizer::GetPathFromTransforms(
    const std::vector<cv::Mat>& transforms) {
  std::vector<std::vector<double>> path;

  double x = 0;
  double y = 0;
  double angle = 0;

  //calculates position at each "time"
  for(size_t i = 0; i < transforms.size();i++) {
    x += transforms[i].at<double>(0,2);
    y += transforms[i].at<double>(1,2);
    angle += atan2(transforms[i].at<double>(1,0),
                   transforms[i].at<double>(0,0));
    path.push_back({x,y,angle});
  }
  return path;
}

std::vector<std::vector<double>> Stabilizer::Smoothen(
    std::vector<std::vector<double>>& original_path, int radius) {
  std::vector<std::vector<double>> smoothened;

  for(size_t i = 0; i < original_path.size(); i++) {
    double x_sum = 0;
    double y_sum = 0;
    double angle_sum = 0;
    size_t count = 0;

    for(int k = -1*radius; k <= radius; k++) {
      if (i+k >= 0 && i+k < original_path.size()) {
        x_sum += original_path[i+k][0];
        y_sum += original_path[i+k][1];
        angle_sum += original_path[i+k][2];

        count++;
      }
    }

    smoothened.push_back({x_sum/(double)count,
                          y_sum/(double)count,
                          angle_sum/(double)count});
  }
  return smoothened;
}

}
