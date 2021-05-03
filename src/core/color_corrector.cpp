//
// Created by Atharva Naik on 6/12/20.
//
#include "core/color_corrector.h"

namespace fcax {

std::vector<cv::Mat>& operator>>(std::vector<cv::Mat>& frames,
                                 ColorCorrector& corrector) {
  for(cv::Mat frame:frames) {
    cv::Mat temp = frame;
    corrector.frames_.push_back(temp);
  }
  return frames;
}

void ColorCorrector::EstimateIlluminants() {
  cv::Ptr<cv::xphoto::WhiteBalancer> wb = cv::xphoto::createGrayworldWB();
  for(cv::Mat frame:frames_) {
    cv::Mat temp;
    wb->balanceWhite(frame,temp);
    curr_Frames_.push_back(temp);
  }
}


} // namespace fcax