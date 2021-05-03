//
// Created by Atharva Naik on 15/11/20.
//
#include <visualizer/video_player.h>

using fcax::visualizer::VideoPlayer;
void prepareSettings(VideoPlayer::Settings* settings) {
  settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(VideoPlayer, ci::app::RendererGl, prepareSettings);
