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
  std::vector<cv::Mat> GetFrames() { return frames_; }

  /**
   * Output operator writes frames to file
   * @param out_folder folder to write to
   * @param extractor extractor
   * @return
   */
  friend std::ofstream& operator<<(std::ofstream &out_folder,
                                   FrameExtractor &extractor);
  
  /**
   * Input operator takes in a filename to extract frames from
   * @param in_file filename of video file
   * @param extractor extractor
   * @return filename
   */
  friend std::string& operator>>(std::string &in_file,
                                  FrameExtractor &extractor);
 private:
  std::vector<cv::Mat> frames_;
};

} // namespace fcax
