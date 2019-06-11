#pragma once
#include <opencv2/opencv.hpp>
#include "Fonctions.h"
#include <string>
//v1) #include "C:\Users\babat\Desktop\mvc\application\application.h"

using namespace std;
using namespace cv;

class Image
{
private:

	 Mat ima;

public:
	Image();

	Image(const Image& image);

	const Image& operator=(const Image& image);

	void copy(const Image& image);

	void setImage(Mat image);

	Mat getImage() const;





	// v1) void getImage(Mat i);


};

std::ostream& operator<<(std::ostream& stream, const Image& image);