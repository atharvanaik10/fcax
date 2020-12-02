//
// Created by Atharva Naik on 15/11/20.
//
#include "core/engine.h"

namespace fcax{

std::ofstream& operator<<(std::ofstream& out_folder, Engine &engine) {

  return out_folder;
}

std::string& operator>>(std::string& in_file, Engine &engine) {
  cv::VideoCapture video(in_file);
  //try to open video
  if(!video.isOpened()) {
    throw std::invalid_argument("File cannot be opened");
  }
  //add frame counter
  size_t count = 0;
  cv::Mat frame;
  //read frame and add to vector
  while(video.read(frame)) {
    engine.frames_.push_back(frame);
    count++;
  }
  std::cout<<"Read "<<count<<" frames"<<std::endl;
  return in_file;
}

} // namespace fcax

