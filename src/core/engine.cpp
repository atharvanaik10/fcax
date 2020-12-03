//
// Created by Atharva Naik on 15/11/20.
//
#include "core/engine.h"

namespace fcax {

std::string& operator<<(std::string& out_file, const Engine &engine) {
  cv::VideoWriter video_out(
      out_file,cv::VideoWriter::fourcc('M','J','P','G'),
      engine.fps_,engine.frame_size_,true);
  for(cv::Mat frame:engine.curr_frames_){
    video_out.write(frame);
  }
  return out_file;
}

std::string& operator>>(std::string& in_file, Engine &engine) {
  cv::VideoCapture video_in(in_file);
  //try to open video_in
  if(!video_in.isOpened()) {
    throw std::invalid_argument("File cannot be opened");
  }
  engine.fps_ = video_in.get(cv::CAP_PROP_FPS);
  engine.frame_size_ = cv::Size((int)video_in.get(cv::CAP_PROP_FRAME_HEIGHT),
                                (int)video_in.get(cv::CAP_PROP_FRAME_HEIGHT));
  //add frame counter
  size_t count = 0;
  cv::Mat frame;
  //read frame and add to vector
  while(video_in.read(frame)) {
    engine.frames_.push_back(frame);
    count++;
  }
  std::cout<<"Read "<<count<<" frames"<<std::endl;
  engine.curr_frames_ = engine.frames_;
  return in_file;
}

void Engine::Stabilize() {
  frames_>>stabilizer_;
  stabilizer_.Stabilize();
  curr_frames_ = stabilizer_.GetFrames();
}

} // namespace fcax

