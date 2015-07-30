#include <iostream>
#include <fstream>
#include <opencv2/highgui/highgui.hpp>
#include <unistd.h>
#include <sys/stat.h> // Linux specific. Used to create output dir.
#include "greyscale.h"


void displayUsage(std::ostream& os) {
	os << "USAGE: ";
	os << "./greyscale IMAGE -[abglrw]" << std::endl;
	os << "Filters:" << std::endl;
	os << "\t a: Average " << std::endl;
	os << "\t l: Lightness" << std::endl;
	os << "\t Spread" << std::endl;
	os << "\t\t b: Blue" << std::endl;
	os << "\t\t g: Green" << std::endl;
	os << "\t\t r: Red" << std::endl;
	os << "\t w: Weighted" << std::endl;
}


int main(int argc, char* argv[]) {
	if (argc < 3) {
		std::cout << "Error: missing arguments" << std::endl;
		displayUsage(std::cout);
		return EXIT_FAILURE;
	}

	std::string file_name(argv[1]);
	std::cout << "Opening " << file_name << "... ";

	// Creating Mat object and reading image from file:
	cv::Mat image(0,0,CV_8UC3);
	image = cv::imread(file_name, CV_LOAD_IMAGE_COLOR);

	if (image.empty()) {
		std::cout << "Could not open." << std::endl;
		return EXIT_FAILURE;
	}

	std::cout 	<< image.size().width 
				<< " x "
				<< image.size().height 
				<< " px" << std::endl;

	// Running the filters...					
	int opt;
	while ( (opt = getopt(argc, argv, "abglrw")) != -1) {
		if (opt == '?') {
			std::cout << "Unknown option: '" << char(optopt) << "'!" << std::endl;
				break;
		}
		// Valid option:
		// Making a copy of the matrix and applying filter to it.
		cv::Mat m = image.clone();
		std::string prefix;

		if (opt == 'a') {
			greyscaleAVG(m);
			prefix = "AVG";
		}
		else if (opt == 'l') {
			greyscaleLightness(m);
			prefix = "Light";
		}
		else if (opt == 'r') {
			greyscaleSpread(m, RED);
			prefix = "RSpr";
		}
		else if (opt == 'g') {
			greyscaleSpread(m, GREEN);
			prefix = "GSpr";
		}
		else if (opt == 'b') {
			greyscaleSpread(m, BLUE);
			prefix = "BSpr";
		}

		else if (opt == 'w') {
			prefix = "W";
			greyscaleWeighted(m);
		}

		// Saving image:
		mkdir("out", S_IRWXU);
		std::string out = "out/" + prefix + "-" + file_name;
		std::cout << "Saving to: " << out << std::endl;
		cv::imwrite(out, m);
	
	}

 	return 0;
}