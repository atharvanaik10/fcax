//
// Created by Atharva Naik on 15/11/20.
//
#include "../../include/core/frame_extractor.h"

namespace fcax{

std::ofstream& operator<<(std::ofstream& out_folder,
                          FrameExtractor& extractor) {

  return out_folder;
}
std::string& operator>>(std::string& in_file, FrameExtractor& extractor) {
  cv::VideoCapture video(in_file);
  if(!video.isOpened()) {
    throw std::invalid_argument("File cannot be opened");
  }
  size_t count = 0;
  cv::Mat frame;
  while(video.read(frame)) {
    extractor.frames_.push_back(frame);
    count++;
  }
  std::cout<<"Read "<<count<<" frames"<<std::endl;
  return in_file;
}
}

