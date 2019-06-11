#include "pch.h"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class Fonctions
{
public:
	Fonctions();

	void choix(Mat image); //ok

	void image(Mat image); //ok

	void couleur(Mat image, Mat save); //ok

	void Median(Mat image, Mat save); //ok
	
	void Changement_luminosite(Mat image); //ok

	void Gaussien(Mat image, Mat save); //ok

	void Seuillage(Mat image, Mat save); //ok

	void Segmentation(Mat image); //ok

	void Gradient(Mat image); //ok

	void Dilatation(Mat image, Mat save); //ok

	void Erosion(Mat image, Mat save); //ok

	void Contour(Mat image, Mat save); //ok


	~Fonctions();
};

