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
  mov_ = cinder::qtime::MovieGl::create(out_file_);
  thread_ = std::shared_ptr<std::thread>(new std::thread(std::bind(&VideoPlayer::Backend, this)));
}

void VideoPlayer::Backend() {
  load_count_ = 0;
  processed_ = false;
  engine_.Stabilize();
  curr_frames_ = engine_.GetCurrFrames();
  out_file_<<engine_;
  processed_ = true;

}
void VideoPlayer::draw() {
  ci::gl::clear();
  if(processed_) {
    mov_->play();
    ci::gl::draw(mov_->getTexture(),getWindowBounds());
  }
  else {
    std::string message = "processing";
//    if(load_count_%4 == 0) {
//      message = "processing";
//    } else if (load_count_%4 == 1) {
//      message = "processing.";
//    } else if (load_count_%4 == 2) {
//      message = "processing..";
//    } else if (load_count_%4 == 3) {
//      message = "processing...";
//    }
    ci::gl::drawStringCentered(message,glm::vec2(kWidth/2,kHeight/2));
    load_count_++;
  }
}

} // namespace visualizer

} // namespace fcax