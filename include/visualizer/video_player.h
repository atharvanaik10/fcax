//
// Created by Atharva Naik on 15/11/20.
//
#pragma once


#include "../core/engine.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

namespace fcax {

namespace visualizer {

class VideoPlayer : public ci::app::App {
 public:
  VideoPlayer();


 private:
//  const int kHeight = 1080;
//  const int kWidth = 1920;
  std::vector<cv::Mat> frames_;
  std::string in_file_ = "/Users/atharvanaik/CLionProjects/Cinder/my-projects/"
      "FinalProject/final-project-atharvanaik10/tests/data/IMG_1462.MOV";
  std::string out_file_ = "/Users/atharvanaik/CLionProjects/Cinder/my-projects/"
      "FinalProject/final-project-atharvanaik10/tests/data/stabresult2.mp4";
};

} // namespace visualizer

} // namespace fcax