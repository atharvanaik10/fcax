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
  SECTION("Valid video file") {
    FrameExtractor extractor;
    std::string file = "/Users/atharvanaik/Desktop/opencvtest.MOV";
    file>>extractor;
    REQUIRE(extractor.GetFrames().size() == 93);
  }
}



