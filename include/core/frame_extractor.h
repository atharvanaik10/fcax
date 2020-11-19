//
// Created by Atharva Naik on 15/11/20.
//
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "opencv2/opencv.hpp"


#pragma once

namespace fcax {

class FrameExtractor {
 public:

  friend std::ofstream& operator<<(std::ofstream &out_folder,
                                   FrameExtractor &extractor);
  friend std::string& operator>>(std::string &in_file,
                                  FrameExtractor &extractor);
 private:
  std::vector<cv::Mat> frames_;
};

} // namespace fcax
