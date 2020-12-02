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
  void Stabilize();
  std::vector<cv::Mat> GetFrames() { return frames_; }
  friend std::vector<cv::Mat>& operator>>
      (std::vector<cv::Mat> &frames, Stabilizer &stabilizer);
 private:
  std::vector<cv::Mat> frames_;
  void SetTranformationMatrix();
  void GetCumulativeSum();
  double dx_;
  double dy_;
  double dangle_;

};

} // namespace fcax