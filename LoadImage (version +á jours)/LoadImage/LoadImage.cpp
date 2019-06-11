#include "pch.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include "Fonctions.h"


using namespace cv;
using namespace std;




int main(int argc, char** argv)
{
	
	//on commence en demandant le chemin de l'image, puis on verifie que cette image existe bel et bien
	string nom;
	cout << "Veuillez donner le chemin vers la photo ex: C:image.jpg" << endl;
	cin >> nom;
	Mat image = imread(nom);
	// Vérifier si l’image existe bien dans le répertoire
	if (image.empty())
	{
		cout << "Could not open or find the image" << endl;
		cin.get(); //wait for any key press
		return -1;
	}

	//on appelle ensuite la fonction choix qui va nous montrer les différentes possibilitées 
	Fonctions a;
	a.choix(image);


	
	return 0;
}

