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
  std::vector<cv::Mat> GetCurrFrames() { return curr_Frames_; }

  /**
   * Uses OpenCV's white balancer to correct all the frames individually
   */
  void EstimateIlluminants();

  /**
   * Input operator overloaded to take in frames
   * @param frames frames
   * @param corrector corrector
   * @return frames
   */
  friend std::vector<cv::Mat>& operator>>
      (std::vector<cv::Mat> &frames, ColorCorrector &corrector);

 private:
  std::vector<cv::Mat> frames_;
  std::vector<cv::Mat> curr_Frames_;
};

} // namespace fcax