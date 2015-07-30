#ifndef GREYSCALE_H
#define GREYSCALE_H
#include <opencv2/core/core.hpp>

enum Color {BLUE, GREEN, RED}; // cv::Mat uses BGR order.

void greyscaleSpread(cv::Mat& img, Color);
void greyscaleAVG(cv::Mat& img);
void greyscaleWeighted(cv::Mat&);

#endif