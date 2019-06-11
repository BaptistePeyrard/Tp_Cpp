#include "ViewMenu.h"
#include <iostream>

using namespace std;

ViewMenu::ViewMenu(Controller& _controller)
	: View("Menu"), controller(_controller)
{
	controller.addObserver(this);
}

void ViewMenu::notify()
{
	if (controller.getCurrentScreen() == 0)
		display();
}

void ViewMenu::display()
{

	clear();
	View::display();

	
	cout << endl << "[1] - Afficher l'image";
	cout << endl << "[2] - Appliquer une couleur";
	cout << endl << "[3] - Changer la luminosite";
	cout << endl << "[4] - Appliquer un filtre median";
	cout << endl << "[5] - Appliquer un filtre gaussien";
	cout << endl << "[6] - Appliquer la dilatation";
	cout << endl << "[7] - Appliquer l'erosion";
	cout << endl << "[8] - operations de seuillages";
	cout << endl << "[9] - Segmentation par croissance de region";
	cout << endl << "[10] - Calcul du gradient";
	cout << endl << "[11] - Detecteur de contour (Canny)";
	cout << endl << "[12] - Quitter l'application" << endl;
	
	int choix;
	cin.clear();
	cin >> choix;

	controller.setScreen(choix);
}

/*
ViewMenu::~ViewMenu()
{
}
*/
