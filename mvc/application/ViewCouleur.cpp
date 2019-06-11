#include "ViewCouleur.h"
#include <iostream>



using namespace std;

ViewCouleur::ViewCouleur(Controller& _controller)
	: View("Changement Couleur"), controller(_controller)
{
	controller.addObserver(this);
}

void ViewCouleur::notify()
{
	
	if (controller.getCurrentScreen() == 2)
		display();
}

void ViewCouleur::display()
{
	Mat im;
	//demander si on veut changer l'image avec un choix et si ou demander la nouvelle image (ca dans tt les views sauf menu)
	cout << "Voulez vous changer d'image [1] ou r�utiliser une ancienne [2] ?" << endl;
		int choix;
		cin >> choix;
		if (choix == 1) {

			//on commence en demandant le chemin de l'image, puis on verifie que cette image existe bel et bien
			string nom;
			cout << "Veuillez donner le chemin vers la photo ex: C:image.jpg" << endl;
			cin >> nom;
			im = imread(nom);
			// V�rifier si l�image existe bien dans le r�pertoire
			if (im.empty())
			{
				controller.setScreen(0);
			}

			image.setImage(im);


		}
		else {
			if (choix == 2) {

				im = image.getImage();

			}
			else {
				controller.setScreen(0);
			}
		}
		controller.apContour(im);
}






/*
ViewCouleur::~ViewCouleur()
{
}
*/
