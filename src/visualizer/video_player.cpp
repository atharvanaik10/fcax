//
// Created by Atharva Naik on 15/11/20.
//

#include "visualizer/video_player.h"

namespace fcax {

namespace visualizer {

VideoPlayer::VideoPlayer() {
  FrameExtractor extractor;
  std::string file = "/Users/atharvanaik/Desktop/opencvtest.MOV";
  file>>extractor;
}

}
}