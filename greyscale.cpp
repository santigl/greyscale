#include "greyscale.h"
#include <algorithm>

void greyscaleSpread(cv::Mat& img, Color c) {
	unsigned int dest1, dest2, src; // Offsets
	// Setting up the color movements.
	// We do that here so that the conditional move is not evaluated at each
	// iteration.
	if (c == RED) {
		src = RED;
		dest1 = GREEN;
		dest2 = BLUE;
	}
	else if (c == GREEN) {
		src = GREEN;
		dest1 = RED;
		dest2 = BLUE;
	}
	else {
		src = BLUE;
		dest1 = RED;
		dest2 = GREEN;
	}
	// Main loop:
	for(int i = 0; i < img.rows; i++) {
		unsigned char* Mi = img.ptr<unsigned char>(i);  // Pointer to row (BGR)
		for(int j = 0; j < img.cols*3; j+=3)
			Mi[j+dest1] = Mi[j+dest2] = Mi[j+src];
	}
}


void greyscaleAVG(cv::Mat& img) {
	for(int i = 0; i < img.rows; i++) {
		unsigned char* Mi = img.ptr<unsigned char>(i); // Pointer to row
		for(int j = 0; j < img.cols*3; j+=3) {
			unsigned int avg = (Mi[j]+Mi[j+1]+Mi[j+2])/3;
			Mi[j] = Mi[j+1] = Mi[j+2] = (unsigned char) avg;
		}
	}
}


void greyscaleLightness(cv::Mat& img) {
	for(int i = 0; i < img.rows; i++) {
		unsigned char* Mi = img.ptr<unsigned char>(i); // Pointer to row
		for(int j = 0; j < img.cols*3; j+=3) {
			unsigned int min = std::min(Mi[j], std::min(Mi[j+1], Mi[j+2]));
			unsigned int max = std::max(Mi[j], std::max(Mi[j+1], Mi[j+2]));
			unsigned int avg = (min+max)/2;

			Mi[j] = Mi[j+1] = Mi[j+2] = (unsigned char) avg;
		}
	}
}


void greyscaleWeighted(cv::Mat& img) {
	for(int i = 0; i < img.rows; i++) {
		unsigned char* Mi = img.ptr<unsigned char>(i); // Pointer to row
		for(int j = 0; j < img.cols*3; j+=3) {
			double wSum = 0.0722*Mi[j] + 0.7152*Mi[j+1]+ 0.2126*Mi[j+2]; // BGR
			// Saturate:
			wSum = std::fmax(0, std::fmin(wSum, 255));
			Mi[j] = Mi[j+1] = Mi[j+2] = (unsigned char) wSum;
		}
	}
}