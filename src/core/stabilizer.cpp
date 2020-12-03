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

void Stabilizer::Stabilize() {
  std::vector<cv::Mat> transforms;

  for(int i = 1; i < frames_.size() - 2; i++){
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

//todo check
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

}
