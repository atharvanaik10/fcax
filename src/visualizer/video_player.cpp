//
// Created by Atharva Naik on 15/11/20.
//

#include "visualizer/video_player.h"

namespace fcax {

namespace visualizer {

VideoPlayer::VideoPlayer() {
  Engine engine;
  std::string in_file = "/Users/atharvanaik/CLionProjects/Cinder/my-projects/"
      "FinalProject/final-project-atharvanaik10/tests/data/test1.MOV";
  in_file>>engine;

}

} // namespace visualizer

} // namespace fcax