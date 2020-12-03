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
  std::vector<cv::Mat> frames_;

};

} // namespace visualizer

} // namespace fcax