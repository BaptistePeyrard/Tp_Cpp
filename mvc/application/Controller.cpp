#include "Controller.h"



Controller::Controller()
	: Subject(), currentScreen(0)
{

}

void Controller::setScreen(const int& choix)
{
	if (choix > 0 && choix <= 12)
		currentScreen = choix;
	notify(); //va observer tt les fonctions notify pour trouver le bon écran à afficher
}

int Controller::getCurrentScreen()
{
	return currentScreen;
}

const Fonctions & Controller::getFonctions()
{
	return fonctions;
}

void Controller::afficherImage(Mat image)
{
	fonctions.image(image);
	setScreen(0);
}

void Controller::apChangerCouleur(Mat image)
{
	fonctions.couleur(image, image);
	setScreen(0);
}

void Controller::apMedian(Mat image)
{
	fonctions.Median(image, image);
	setScreen(0);
}

void Controller::apChangement_luminosite(Mat image)
{
	fonctions.Changement_luminosite(image);
	setScreen(0);
}

void Controller::apGaussien(Mat image)
{
	fonctions.Gaussien(image, image);
	setScreen(0);
}

void Controller::apSeuillage(Mat image)
{
	fonctions.Seuillage(image, image);
	setScreen(0);
}

void Controller::apSegmentation(Mat image)
{
	fonctions.Segmentation(image);
	setScreen(0);
}

void Controller::apGradient(Mat image)
{
	fonctions.Gradient(image);
	setScreen(0);
}

void Controller::apDilatation(Mat image)
{
	fonctions.Dilatation(image, image);
	setScreen(0);
}

void Controller::apErosion(Mat image)
{
	fonctions.Erosion(image, image);
	setScreen(0);
}

void Controller::apContour(Mat image)
{
	fonctions.Contour(image, image);
	setScreen(0);
}


