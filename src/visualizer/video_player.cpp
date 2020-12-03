//
// Created by Atharva Naik on 15/11/20.
//

#include "visualizer/video_player.h"

namespace fcax {

namespace visualizer {

VideoPlayer::VideoPlayer() {
  Engine engine;
  in_file_>>engine;
  engine.Stabilize();
  out_file_<<engine;
  //ci::app::setWindowSize(kHeight,kWidth);
}


} // namespace visualizer

} // namespace fcax