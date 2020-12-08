//
// Created by Atharva Naik on 15/11/20.
//
#pragma once


#include "../core/engine.h"
#include "cinder/app/App.h"
#include "cinder/app/AppBase.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "../other/CinderOpenCV.h"
#include "cinder/Thread.h"


namespace fcax {

namespace visualizer {

class VideoPlayer : public ci::app::App {
 public:
  VideoPlayer();

  void draw() override;

  void setup() override;

  void Backend();
 private:
  std::shared_ptr<std::thread> thread_;
  bool processed_ = false;
  Engine engine_;
  const int kHeight = 720;
  const int kWidth = 1280;
  std::vector<cv::Mat> frames_;
  std::vector<cv::Mat> curr_frames_;
  std::string in_file_ = "/Users/atharvanaik/CLionProjects/Cinder/my-projects/"
      "FinalProject/final-project-atharvanaik10/tests/data/IMG_1462.MOV";
  std::string out_file_ = "/Users/atharvanaik/CLionProjects/Cinder/my-projects/"
      "FinalProject/final-project-atharvanaik10/tests/data/stabresult2.mp4";
};

} // namespace visualizer

} // namespace fcax