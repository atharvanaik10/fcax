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
}

TEST_CASE("Test fps and frame size") {
  Engine engine;
  std::string file = "/Users/atharvanaik/CLionProjects/Cinder/my-projects/"
      "FinalProject/final-project-atharvanaik10/tests/data/test1.mov";
  file>>engine;
  REQUIRE(abs(engine.GetFPS() - 60) < 1);
  REQUIRE(engine.GetFrameSize().height == 1080);
  REQUIRE(engine.GetFrameSize().width == 1920);
}

TEST_CASE("Test stabilization and color correction") {
  SECTION("Stabilization") {
    Engine engine;
    std::string file = "/Users/atharvanaik/CLionProjects/Cinder/my-projects/"
        "FinalProject/final-project-atharvanaik10/tests/data/IMG_1462.mov";
    file>>engine;
    engine.Stabilize();
    REQUIRE(engine.GetCurrFrames().size() == engine.GetFrames().size());
  }
  SECTION("CC") {
    Engine engine;
    std::string file = "/Users/atharvanaik/CLionProjects/Cinder/my-projects/"
        "FinalProject/final-project-atharvanaik10/tests/data/IMG_1462.mov";
    file>>engine;
    engine.ColorCorrect();
    REQUIRE(engine.GetCurrFrames().size() == engine.GetFrames().size());
  }
}



