//
// Created by Atharva Naik on 15/11/20.
//
#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
#include "../core/engine.h"
#include "cinder/app/App.h"
#include "cinder/app/AppBase.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "../other/CinderOpenCV.h"
#include "cinder/Thread.h"
#include "cinder/qtime/QuickTimeImplAvf.h"
#include "cinder/qtime/QuickTimeGlImplAvf.h"

namespace fcax {

namespace visualizer {

class VideoPlayer : public ci::app::App {
 public:
  /**
   * Sets up engine with the in_file and sets window size and frame rate
   */
  VideoPlayer();

  /**
   * Sets up the movie using the newly written file and
   * creates the backend thread
   */
  void setup() override;

  /**
   * If the backend has been processed, it plays the movie (draws the video).
   * Otherwise, it prints "processing"
   */
  void draw() override;

  /**
   * Handles the playbar and the playhead by drawing them and
   * updating them with mouse click
   */
  void HandlePlaybar();

  /**
   * Checks for j,k,l keys pressed to move back one frame, play/pause,
   * or move forward one frame.
   * @param event
   */
  void keyDown(ci::app::KeyEvent event) override;

  /**
   * Checks for mouse position and adjusts playbar
   * and seeks video to correct time
   * @param event
   */
  void mouseDown(ci::app::MouseEvent event) override;
  void mouseDrag(ci::app::MouseEvent event) override;



  /**
   * This function is called by the secondary thread. It calls engine_'s
   * stabilize method and writes the new video to file in the backend.
   */
  void Backend();
 private:
  std::shared_ptr<std::thread> thread_;
  bool processed_ = false;

  Engine engine_;

  const int kHeight = 720;
  const int kWidth = 1280;
  const int kPlaybarHeight = 10;
  const int kPlaybarLength = 800;
  const int kPlaybarPadding = 50;

  ci::qtime::MovieGlRef mov_before_;
  ci::qtime::MovieGlRef mov_after_;
  float duration_;
  int num_frames_;
  std::vector<cv::Mat> frames_;
  std::vector<cv::Mat> curr_frames_;

  std::string in_file_ = "/Users/atharvanaik/CLionProjects/Cinder/my-projects/"
      "FinalProject/final-project-atharvanaik10/tests/data/IMG_1462.mov";
  std::string temp_file_ = "/Users/atharvanaik/CLionProjects/Cinder/my-projects/"
      "FinalProject/final-project-atharvanaik10/tests/data/fcax_before.mp4";
  std::string out_file_ = "/Users/atharvanaik/CLionProjects/Cinder/my-projects/"
      "FinalProject/final-project-atharvanaik10/tests/data/fcax_after.mp4";
};

} // namespace visualizer

} // namespace fcax