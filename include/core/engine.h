//
// Created by Atharva Naik on 15/11/20.
//
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "stabilizer.h"

#pragma once

namespace fcax {

class Engine {
 public:
  std::vector<cv::Mat> GetFrames() { return frames_; }
  void Stabilize();

  /**
   * Output operator writes frames to file
   * @param out_folder folder t o write to
   * @param Engine engine
   * @return
   */
  friend std::ofstream& operator<<(std::ofstream &out_folder,
                                   Engine &engine);
  
  /**
   * Input operator takes in a filename to extract frames from
   * @param in_file filename of video file
   * @param Engine engine
   * @return filename
   */
  friend std::string& operator>>(std::string &in_file, Engine &engine);
 private:
  std::vector<cv::Mat> frames_;
  std::vector<cv::Mat> curr_frames_;
  Stabilizer stabilizer_;
  double fps_;
  cv::Size frame_size_;
};

} // namespace fcax
