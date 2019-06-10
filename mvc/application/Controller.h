#pragma once
#include "subject.h"
#include "C:\Users\babat\Desktop\mvc\metier\Fonctions.h" //il existe surement un autre moyen

class Controller : public Subject
{
private:
	int currentScreen = 0;

	
	Fonctions fonctions;


public:
	Controller();

	void setScreen(const int& value);

	int getCurrentScreen();

	const Fonctions& getFonctions();

	void afficherImage(Mat image);

	void apChangerCouleur(Mat image);

	void apMedian(Mat image);

	void apChangement_luminosite(Mat image); 

	void apGaussien(Mat image); 

	void apSeuillage(Mat image); 

	void apSegmentation(Mat image); 

	void apGradient(Mat image); 

	void apDilatation(Mat image); 

	void apErosion(Mat image); 

	void apContour(Mat image); 




};

