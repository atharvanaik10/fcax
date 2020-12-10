//
// Created by Atharva Naik on 6/12/20.
//
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <string>

#include "opencv2/opencv.hpp"
#include "opencv2/xphoto.hpp"

#pragma once

namespace fcax {

class ColorCorrector {
 public:
  /**
   * Returns the frames of the corrector
   * @return vector of mat frames
   */
  std::vector<cv::Mat> GetFrames() { return transforms_; }

  void EstimateIlluminants();

  /**
   * Input operator overloaded to take in frames and convert to grayscale
   * @param frames frames
   * @param stabilizer stabilizer
   * @return frames
   */
  friend std::vector<cv::Mat>& operator>>
      (std::vector<cv::Mat> &frames, ColorCorrector &corrector);

 private:
  std::vector<cv::Mat> frames_;
  std::vector<cv::Mat> transforms_;
  //double kSaturationPct = 0.1;

  cv::Mat GetTransform(cv::Mat frame);

};

} // namespace fcax