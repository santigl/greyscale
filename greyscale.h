#ifndef GREYSCALE_H
#define GREYSCALE_H
#include <opencv2/core/core.hpp>

enum Color {BLUE, GREEN, RED}; // cv::Mat uses BGR order.

void greyscaleAVG(cv::Mat& img);
void greyscaleLightness(cv::Mat& img);
void greyscaleSpread(cv::Mat& img, Color);
void greyscaleWeighted(cv::Mat&);

#endif