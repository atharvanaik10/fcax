//
// Created by Atharva Naik on 2/12/20.
//
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "opencv2/opencv.hpp"

#pragma once

namespace fcax {

class Stabilizer {
 public:
  /**
   * Stabilize method to calculate how to transfrom every frame
   * @return smooth transformation matrix
   */
  std::vector<cv::Mat> Stabilize();

  /**
   * Returns the frames of the stabilizer
   * @return vector of mat frames
   */
  std::vector<cv::Mat> GetFrames() { return frames_; }

  /**
   * Input operator overloaded to take in frames and convert to grayscale
   * @param frames frames
   * @param stabilizer stabilizer
   * @return frames
   */
  friend std::vector<cv::Mat>& operator>>
      (std::vector<cv::Mat> &frames, Stabilizer &stabilizer);

 private:
  const int kSmoothingRadius = 10;
  std::vector<cv::Mat> frames_;

  /**
   * Calculates the transforms using the changes in cv::goodFeaturesToTrack
   * @param transforms
   */
  void CalculateTransforms(std::vector<cv::Mat> &transforms);

  /**
   * Gets the path from the transforms. (Sum over time)
   * @param transforms
   * @return path/graph of movement
   */
  std::vector<std::vector<double>> GetPathFromTransforms(
      const std::vector<cv::Mat> &transforms);

  /**
   * Gets a tranformation matrix from inputted parameters
   * @param d_x
   * @param d_y
   * @param d_a
   * @return
   */
  cv::Mat GetTranformationMatrix(double d_x, double d_y, double d_a);

  /**
   * Uses a moving average filter to smoothen the path
   * @param original_path
   * @param radius
   * @return
   */
  std::vector<std::vector<double>> Smoothen(
      std::vector<std::vector<double>> &original_path, int radius);
};

} // namespace fcax