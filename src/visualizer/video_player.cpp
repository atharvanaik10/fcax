//
// Created by Atharva Naik on 15/11/20.
//

#include "visualizer/video_player.h"

namespace fcax {

namespace visualizer {

VideoPlayer::VideoPlayer() {
  in_file_>>engine_;
  frames_ = engine_.GetFrames();

  ci::app::setWindowSize(kWidth,kHeight);
}

void VideoPlayer::setup() {
  thread_ = std::shared_ptr<std::thread>(new std::thread(std::bind(&VideoPlayer::Backend, this)));
}

void VideoPlayer::Backend() {
  processed_ = false;
  engine_.Stabilize();
  curr_frames_ = engine_.GetCurrFrames();
  processed_ = true;
  //out_file_<<engine;
}
void VideoPlayer::draw() {
  ci::gl::clear();
  if(processed_) {
    for (cv::Mat frame : frames_) {
      ci::Surface s = cinder::fromOcv(frame);
      ci::gl::Texture2dRef t = ci::gl::Texture2d::create(s);
      ci::gl::clear();
      ci::gl::draw(t);
    }
  }
  else {
    ci::gl::drawStringCentered("processing",glm::vec2(kWidth/2,kHeight/2));
  }
}

} // namespace visualizer

} // namespace fcax