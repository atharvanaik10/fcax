//
// Created by Atharva Naik on 15/11/20.
//
#pragma once

#include "../core/frame_extractor.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

namespace fcax {

namespace visualizer {
class VideoPlayer : public ci::app::App {
 public:
  VideoPlayer();
};
}
}