#include <iostream>
#include "application.h"

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	/* v2)
	//on commence en demandant le chemin de l'image, puis on verifie que cette image existe bel et bien
	string nom;
	cout << "Veuillez donner le chemin vers la photo ex: C:image.jpg" << endl;
	cin >> nom;
	Mat ima = imread(nom);
	// V�rifier si l�image existe bien dans le r�pertoire
	if (ima.empty())
	{
		cout << "Could not open or find the image" << endl;
		cin.get(); //wait for any key press
		return -1;
	}
	
	Image im;
	im.getImage(ima);	
	*/
	Application appliation;
		appliation.run();
}