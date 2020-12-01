//
// Created by Atharva Naik on 15/11/20.
//
#define CATCH_CONFIG_MAIN

#include <string>
#include <cstdlib>

#include <core/frame_extractor.h>
#include <catch2/catch.hpp>

using namespace fcax;

TEST_CASE("Test frame extraction") {
  SECTION("1 frame file mov") {
    FrameExtractor extractor;
    std::string file = "/Users/atharvanaik/CLionProjects/Cinder/my-projects/"
        "FinalProject/final-project-atharvanaik10/tests/data/test1.mov";
    file>>extractor;
    REQUIRE(extractor.GetFrames().size() == 1);
  }
  SECTION("Normal file mp4") {
    FrameExtractor extractor;
    std::string file = "/Users/atharvanaik/CLionProjects/Cinder/my-projects/"
        "FinalProject/final-project-atharvanaik10/tests/data/test2.mp4";
    file>>extractor;
    REQUIRE(extractor.GetFrames().size() == 86);
  }
  SECTION("Normal file mp4") {
    FrameExtractor extractor;
    std::string file = "/Users/atharvanaik/CLionProjects/Cinder/my-projects/"
        "FinalProject/final-project-atharvanaik10/tests/data/test3.mp4";
    file>>extractor;
    REQUIRE(extractor.GetFrames().size() == 130);
  }
  SECTION("Normal file mp4") {
    FrameExtractor extractor;
    std::string file = "/Users/atharvanaik/CLionProjects/Cinder/my-projects/"
        "FinalProject/final-project-atharvanaik10/tests/data/test4.mp4";
    file>>extractor;
    REQUIRE(extractor.GetFrames().size() == 42);
  }
  SECTION("Thicc file mov") {
    FrameExtractor extractor;
    std::string file = "/Users/atharvanaik/CLionProjects/Cinder/my-projects/"
        "FinalProject/final-project-atharvanaik10/tests/data/test5.mov";
    file>>extractor;
    REQUIRE(extractor.GetFrames().size() == 39);
  }
}



