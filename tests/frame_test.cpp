//
// Created by Atharva Naik on 15/11/20.
//
#define CATCH_CONFIG_MAIN
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include <core/frame_extractor.h>
#include <catch2/catch.hpp>

using namespace fcax;

TEST_CASE("Test frame extraction") {
  SECTION("Normal file") {
    FrameExtractor extractor;
    std::string file = "/Users/atharvanaik/CLionProjects/Cinder/my-projects/"
        "FinalProject/final-project-atharvanaik10/tests/data/93frames.MOV";
    file>>extractor;
    REQUIRE(extractor.GetFrames().size() == 93);
  }
  SECTION("Normal file") {
    FrameExtractor extractor;
    std::string file = "/Users/atharvanaik/CLionProjects/Cinder/my-projects/"
        "FinalProject/final-project-atharvanaik10/tests/data/28frames.mp4";
    file>>extractor;
    REQUIRE(extractor.GetFrames().size() == 28);
  }
  SECTION("Normal file mp4") {
    FrameExtractor extractor;
    std::string file = "/Users/atharvanaik/CLionProjects/Cinder/my-projects/"
        "FinalProject/final-project-atharvanaik10/tests/data/95frames.mp4";
    file>>extractor;
    REQUIRE(extractor.GetFrames().size() == 95);
  }
  SECTION("1 frame mp4") {
    FrameExtractor extractor;
    std::string file = "/Users/atharvanaik/CLionProjects/Cinder/my-projects/"
        "FinalProject/final-project-atharvanaik10/tests/data/1frame.mp4";
    file>>extractor;
    REQUIRE(extractor.GetFrames().size() == 1);
  }
  SECTION("Large file") {
    FrameExtractor extractor;
    std::string file = "/Users/atharvanaik/CLionProjects/Cinder/my-projects/"
        "FinalProject/final-project-atharvanaik10/tests/data/17frames.MOV";
    file>>extractor;
    REQUIRE(extractor.GetFrames().size() == 17);
  }
}



