//
// Created by Atharva Naik on 15/11/20.
//

#include "visualizer/video_player.h"

namespace fcax {

namespace visualizer {

VideoPlayer::VideoPlayer() {
  Engine engine;
  std::string in_file = "/Users/atharvanaik/CLionProjects/Cinder/my-projects/"
      "FinalProject/final-project-atharvanaik10/tests/data/stabtest.mov";
  std::string out_file = "/Users/atharvanaik/CLionProjects/Cinder/my-projects/"
      "FinalProject/final-project-atharvanaik10/tests/data/stabresult.mp4";
  in_file>>engine;
  engine.Stabilize();
  out_file<<engine;

}

} // namespace visualizer

} // namespace fcax