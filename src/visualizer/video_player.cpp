//
// Created by Atharva Naik on 15/11/20.
//

#include "visualizer/video_player.h"

namespace fcax {

namespace visualizer {

VideoPlayer::VideoPlayer() {
  in_file_>>engine_;
  temp_file_<<engine_;
  frames_ = engine_.GetFrames();

  ci::app::setWindowSize(kWidth,kHeight);
  ci::app::setFrameRate(engine_.GetFPS());
}

void VideoPlayer::setup() {
  //create before qtime movies
  mov_before_ = cinder::qtime::MovieGl::create(temp_file_);

  //create new thread which calls backend
  thread_ = std::shared_ptr<std::thread>(
      new std::thread(std::bind(&VideoPlayer::Backend, this)));
}

void VideoPlayer::Backend() {
  processed_ = false;
  engine_.ColorCorrect();
  engine_.Stabilize();
  curr_frames_ = engine_.GetCurrFrames();
  out_file_<<engine_;
  //create after qtime movie
  mov_after_ = cinder::qtime::MovieGl::create(out_file_);
  processed_ = true;
}

void VideoPlayer::draw() {
  ci::gl::clear();
  if(processed_ && mov_after_->isPlayable()) {
    ci::Rectf box_after(glm::vec2(kWidth/2,kHeight/4),
                        glm::vec2(kWidth,3*kHeight/4));
    ci::gl::draw(mov_after_->getTexture(),box_after);
  } else {
    std::string message = "processing";
    ci::gl::drawStringCentered(message,glm::vec2(3*kWidth/4,kHeight/2));
  }
  if(mov_before_->isPlayable()) {
    ci::Rectf box_before(glm::vec2(0,kHeight/4),
                         glm::vec2(kWidth/2,3*kHeight/4));
    ci::gl::draw(mov_before_->getTexture(),box_before);
    HandlePlaybar();
  }
}

void VideoPlayer::keyDown(ci::app::KeyEvent event) {
   switch (event.getCode()) {
     case ci::app::KeyEvent::KEY_j:
       mov_before_->stepBackward();
       mov_after_->stepBackward();
       break;
     case ci::app::KeyEvent::KEY_l:
       mov_before_->stepForward();
       mov_after_->stepForward();
       break;
     case ci::app::KeyEvent::KEY_k:
       if(mov_before_->isPlaying()) {
         mov_before_->stop();
         mov_after_->stop();
       } else {
         mov_before_->play();
         mov_after_->play();
       }
       break;
   }
}

void VideoPlayer::HandlePlaybar() {
  glm::vec2 playbar_size(kPlaybarLength,kPlaybarHeight);
  glm::vec2 playbar_top_left_corner((kWidth-kPlaybarLength)/2,
                                    (3*kHeight/4)+kPlaybarPadding);
  ci::Rectf playbar(playbar_top_left_corner,
                    playbar_top_left_corner+playbar_size);
  ci::gl::drawStrokedRect(playbar);
}

} // namespace visualizer

} // namespace fcax