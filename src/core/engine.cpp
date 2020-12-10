//
// Created by Atharva Naik on 15/11/20.
//
#include "core/engine.h"

#include <opencv2/core/opengl.hpp>

namespace fcax {

std::string& operator<<(std::string& out_file, const Engine &engine) {
  std::cout<<"fps " << engine.fps_<<std::endl;
  cv::VideoWriter video_out(
      out_file,cv::VideoWriter::fourcc('m','p','4','v'),
      engine.fps_,engine.frame_size_);
  for(cv::Mat frame:engine.curr_frames_){
    video_out.write(frame);
  }
  video_out.release();
  return out_file;
}

std::string& operator>>(std::string& in_file, Engine &engine) {
  cv::VideoCapture video_in(in_file);
  //try to open video_in
  if(!video_in.isOpened()) {
    throw std::invalid_argument("File cannot be opened");
  }
  engine.fps_ = video_in.get(cv::CAP_PROP_FPS);
  engine.frame_size_ = cv::Size((int)video_in.get(cv::CAP_PROP_FRAME_WIDTH),
                                (int)video_in.get(cv::CAP_PROP_FRAME_HEIGHT));
  //add frame counter
  size_t count = 0;
  cv::Mat frame;
  //read frame and add to vector
  while(video_in.read(frame)) {
    cv::Mat new_frame;
    cv::cvtColor(frame,new_frame,cv::COLOR_BGR2RGB);
    cv::Mat newer_frame;
    cv::cvtColor(new_frame,newer_frame,cv::COLOR_RGB2BGR);
    engine.frames_.push_back(newer_frame);
    count++;
  }
  std::cout<<"Read "<<count<<" frames"<<std::endl;
  engine.curr_frames_ = engine.frames_;
  video_in.release();
  return in_file;
}

void Engine::Stabilize() {
  frames_>>stabilizer_;

  std::vector<cv::Mat> smooth_transforms = stabilizer_.Stabilize();
  for(int i = 0; i < curr_frames_.size()-1; i++) {
    cv::warpAffine(curr_frames_[i],
                   curr_frames_[i],
                   smooth_transforms[i],
                   curr_frames_[i].size());
  }
  std::cout<<"Stabilized"<<std::endl;

}

void Engine::ColorCorrect() {
  curr_frames_>>corrector_;
  std::cout<<"Getting illuminants"<<std::endl;
  corrector_.EstimateIlluminants();
  curr_frames_ = corrector_.GetFrames();
  std::cout<<"Corrected"<<std::endl;
}

std::vector<cv::ogl::Texture2D> Engine::GetTextures() {
  std::vector<cv::ogl::Texture2D> textures;
  for(cv::Mat frame:frames_) {
    cv::ogl::Texture2D tex;
    cv::ogl::convertToGLTexture2D(frame, tex);
    textures.push_back(tex);
  }
  return textures;
}

} // namespace fcax

