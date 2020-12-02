//
// Created by Atharva Naik on 15/11/20.
//
#define CATCH_CONFIG_MAIN

#include <core/engine.h>

#include <catch2/catch.hpp>
#include <cstdlib>
#include <string>

using namespace fcax;

TEST_CASE("Test frame extraction") {
  SECTION("1 frame file mov") {
    Engine engine;
    std::string file = "/Users/atharvanaik/CLionProjects/Cinder/my-projects/"
        "FinalProject/final-project-atharvanaik10/tests/data/test1.mov";
    file>> engine;
    REQUIRE(engine.GetFrames().size() == 1);
  }
  SECTION("Normal file mp4") {
    Engine engine;
    std::string file = "/Users/atharvanaik/CLionProjects/Cinder/my-projects/"
        "FinalProject/final-project-atharvanaik10/tests/data/test2.mp4";
    file>> engine;
    REQUIRE(engine.GetFrames().size() == 86);
  }
  SECTION("Normal file mp4") {
    Engine engine;
    std::string file = "/Users/atharvanaik/CLionProjects/Cinder/my-projects/"
        "FinalProject/final-project-atharvanaik10/tests/data/test3.mp4";
    file>> engine;
    REQUIRE(engine.GetFrames().size() == 130);
  }
  SECTION("Normal file mp4") {
    Engine engine;
    std::string file = "/Users/atharvanaik/CLionProjects/Cinder/my-projects/"
        "FinalProject/final-project-atharvanaik10/tests/data/test4.mp4";
    file>> engine;
    REQUIRE(engine.GetFrames().size() == 42);
  }
  SECTION("Thicc file mov") {
    Engine engine;
    std::string file = "/Users/atharvanaik/CLionProjects/Cinder/my-projects/"
        "FinalProject/final-project-atharvanaik10/tests/data/test5.mov";
    file>> engine;
    REQUIRE(engine.GetFrames().size() == 39);
  }
}



