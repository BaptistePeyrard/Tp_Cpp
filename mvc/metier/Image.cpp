#include "Image.h"


/*
void Image::getImage(Mat i) 
{

	image = i;
	Application application;
	application.run(i);
}
*/


Image::Image()
	: ima()
{

}



Image::Image(const Image& image)
{

	copy(image);

}

const Image& Image::operator=(const Image& image)
{

	copy(image);

	return *this;


}

void Image::copy(const Image& image)
{
	 ima = image.ima;
}

void Image::setImage(const Mat image)
{
	ima = image;
}

Mat Image::getImage() const
{
	return ima;
}

std::ostream& operator<<(std::ostream& stream, const Image& image)
{
	stream << image.getImage();
	return stream;
}


