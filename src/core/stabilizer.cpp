//
// Created by Atharva Naik on 2/12/20.
//
#include "core/stabilizer.h"

namespace fcax {

std::vector<cv::Mat>& operator>>(std::vector<cv::Mat> &frames,
                                 Stabilizer& stabilizer) {
  for(cv::Mat frame:frames) {
    cv::Mat greyed;
    cvtColor(frame,greyed, cv::COLOR_BGR2GRAY);
    stabilizer.frames_.push_back(greyed);
  }
  return frames;
}

}
