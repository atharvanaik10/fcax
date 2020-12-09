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
  ci::app::setFrameRate(engine_.GetFPS());
}

void VideoPlayer::setup() {
  //create before and after qtime movies
  mov_before_ = cinder::qtime::MovieGl::create(in_file_);
  mov_after_ = cinder::qtime::MovieGl::create(out_file_);
  //create new thread which calls backend
  thread_ = std::shared_ptr<std::thread>(
      new std::thread(std::bind(&VideoPlayer::Backend, this)));
}

void VideoPlayer::Backend() {
  processed_ = false;
  engine_.Stabilize();
  curr_frames_ = engine_.GetCurrFrames();
  out_file_<<engine_;
  processed_ = true;
}

void VideoPlayer::draw() {
  ci::gl::clear();
  if(processed_) {
    mov_before_->play();
    mov_after_->play();

    ci::Rectf box_before(glm::vec2(0,kHeight/4), glm::vec2(kWidth/2,3*kHeight/4));
    ci::Rectf box_after(glm::vec2(kWidth/2,kHeight/4), glm::vec2(kWidth,3*kHeight/4));

    ci::gl::draw(mov_before_->getTexture(),box_before);
    ci::gl::draw(mov_after_->getTexture(),box_after);
  }
  else {
    std::string message = "processing";
    ci::gl::drawStringCentered(message,glm::vec2(kWidth/2,kHeight/2));
  }
}

} // namespace visualizer

} // namespace fcax