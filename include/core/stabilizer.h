//
// Created by Atharva Naik on 2/12/20.
//
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "opencv2/opencv.hpp"

#pragma once

namespace fcax {

class Stabilizer {
 public:
  std::vector<cv::Mat> Stabilize();

  std::vector<cv::Mat> GetFrames() { return frames_; }

  friend std::vector<cv::Mat>& operator>>
      (std::vector<cv::Mat> &frames, Stabilizer &stabilizer);

 private:
  const int kSmoothingRadius = 5;
  std::vector<cv::Mat> frames_;

  void CalculateTransforms(std::vector<cv::Mat> &transforms);

  std::vector<std::vector<double>> GetPathFromTransforms(
      const std::vector<cv::Mat> &transforms);

  cv::Mat GetTranformationMatrix(double d_x, double d_y, double d_a);

  std::vector<std::vector<double>> Smoothen(
      std::vector<std::vector<double>> &original_path, int radius);
};

} // namespace fcax