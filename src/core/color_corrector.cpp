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
  cv::Ptr<cv::xphoto::WhiteBalancer> wb = cv::xphoto::createSimpleWB();
  for(cv::Mat frame:frames_) {
    cv::Mat temp;
    wb->balanceWhite(frame,temp);
    transforms_.push_back(temp);
    //transforms_.push_back(GetTransform(frame));
  }
}

cv::Mat ColorCorrector::GetTransform(cv::Mat frame) {
  if (frame.channels() != 3) {
    throw std::out_of_range("Frame does not have 3 channels");
  }

  std::vector<cv::Mat> split_channels;
  cv::split(frame,split_channels);
  for(int i = 0; i < frame.channels(); i++) {
    cv::Mat flattened;
    split_channels[i].reshape(1,1).copyTo(flattened);

  }
  return frame;

}

} // namespace fcax