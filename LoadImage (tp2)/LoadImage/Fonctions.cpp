#include "pch.h"
#include "Fonctions.h"


Fonctions::Fonctions()
{
}

/*notes, à faire :
		- il faut demander à l'utilisateur les valeurs à appliquer pour les filtres (median gauss luminosité et partout en fait)
		- il faut faire une architecture mvc
		- il faut faire le diagramme hml machin
*/

void Fonctions::choix(Mat image)	//affiche les actions possibles à réaliser et demande à l'utilisateur ce qu'il veut faire
{
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
	cout << endl << "[Autres caracteres] - Quitter l'application" << endl;
	
	int choix;
	cin >> choix;
	Fonctions a;
	if (choix == 1 || choix == 2 || choix == 3 || choix == 4 || choix == 5 || choix == 6 || choix == 7 || choix == 8 || choix == 9 || choix == 10 || choix == 11){
		if (choix == 1)
			a.image(image);
		if (choix == 2)
			a.couleur(image, image);
		if (choix == 3)
			a.Changement_luminosite(image);
		if (choix == 4)
			a.Median(image, image);	//on marque 2 fois image car cette fonction va prendre une image et une sauvegarde de l'image
		if (choix == 5)
			a.Gaussien(image, image);
		if (choix == 6)
			a.Dilatation(image, image);
		if (choix == 7)
			a.Erosion(image, image);
		if (choix == 8)
			a.Seuillage(image, image);
		if (choix == 9)
			a.Segmentation(image);
		if (choix == 10)
			a.Gradient(image);
		if (choix == 11)
			a.Contour(image, image);
	}
	else {
		cout << "il y a anguille sous roche" << endl;
		a.choix(image);
	}
}


void Fonctions::image(Mat image)	//affiche tout simplement l'image de base, pas besoin de sauvegarde car pas de modifications potentielles
{

	String windowNameOriginalImage = "Original Image";
	namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
	imshow(windowNameOriginalImage, image);
	waitKey(0);
	destroyAllWindows();
	Fonctions a;
	a.choix(image);
}

void Fonctions::couleur(Mat image, Mat save)
{
	Fonctions a;
	Mat couleur;
	Mat test;

	cout << endl << "Choisissez une couleur :" << endl;
	cout << "[1] - gris" << endl;
	cout << "[2] - rouge" << endl;
	cout << "[3] - vert" << endl;
	cout << "[4] - violet" << endl;

	int choix_couleur;
	cin >> choix_couleur;

	if (choix_couleur == 1)
		cvtColor(image, couleur, COLOR_BGR2GRAY);
	if (choix_couleur == 2) 
		cvtColor(test, couleur, COLOR_BGR2HSV);
	if (choix_couleur == 3)
		cvtColor(image, couleur, COLOR_BGR2HLS);
	if (choix_couleur == 4)
		cvtColor(image, couleur, COLOR_YUV2BGR);

	




	String windowNamecouleur = "image coloré";
	String windowNameOriginalImage = "Original Image";
	namedWindow(windowNamecouleur, WINDOW_NORMAL);
	namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
	imshow(windowNamecouleur, couleur);
	imshow(windowNameOriginalImage, image);
	waitKey(0);
	destroyAllWindows();
	cout << "Que voulez-vous faire ?" << endl;
	cout << "[1] - Enregistrer le resultat et continuer avec l'image initiale" << endl;
	cout << "[2] - Enregistrer le resultat et continuer avec la nouvelle image" << endl;
	cout << "[3] - Ne pas enregistrer le resultat et cotinuer avec l'image initiale" << endl;
	cout << "[4] - Ne pas enregistrer le resultat et continuer avec la nouvelle image" << endl;
	cout << "[5] - Appliquer le filtre a cette nouvelle image (n'enregistre pas cette nouvelle image)" << endl;	
	int choix;
	cin >> choix;
	if (choix == 1 || choix == 2 || choix == 3 || choix == 4 || choix == 5) {
		if (choix == 1) {
			cout << "Donnez le chemin (et donc le nom) pour l'enregistrement ex: D:nouvelle_image.png" << endl;
			string chemin;
			cin >> chemin;
			imwrite(chemin, couleur);	
			a.choix(save);
		}
		if (choix == 2) {
			cout << "Donnez le chemin (et donc le nom) pour l'enregistrement ex: D:nouvelle_image.png" << endl;
			string chemin;
			cin >> chemin;
			imwrite(chemin, couleur);
			a.choix(couleur);
		}
		if (choix == 3) {
			a.choix(save);
		}
		if (choix == 4) {
			a.choix(couleur);
		}
		if (choix == 5) {
			a.Median(couleur, save);	
		}
	}
	else {
		cout << "il y a erreur sur la marchandise" << endl;	
		a.choix(save);
	}
}

void Fonctions::Median(Mat image, Mat save)	//image sera l'image servant de modele, elle sera donc modifié si ce filtre est appliqué plusieurs fois à la suite, save permet de renvoyer l'image initial à la fin
{




	Fonctions a;
	Mat filtreMedian;
	medianBlur(image, filtreMedian, 7);		//on met d'abord l'image de base, puis la nouvelle image, puis un nombre impair (plus il est grand et plus le filtre va etre puissant) (7 c'est pas mal)
	String windowNameMedian = "Filtre median";
	String windowNameOriginalImage = "Original Image";
	namedWindow(windowNameMedian, WINDOW_NORMAL);
	namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
	imshow(windowNameOriginalImage, image);
	imshow(windowNameMedian, filtreMedian);
	waitKey(0);	//on met 0 pour que les images ne s'enlevent jamais toutes seules
	destroyAllWindows();
	cout << "Que voulez-vous faire ?" << endl;
	cout << "[1] - Enregistrer le resultat et continuer avec l'image initiale" << endl;
	cout << "[2] - Enregistrer le resultat et continuer avec la nouvelle image" << endl;
	cout << "[3] - Ne pas enregistrer le resultat et cotinuer avec l'image initiale" << endl;
	cout << "[4] - Ne pas enregistrer le resultat et continuer avec la nouvelle image" << endl;
	cout <<	"[5] - Appliquer le filtre a cette nouvelle image (n'enregistre pas cette nouvelle image)" << endl;	//permet de recommencer immediatement sans repasser par la liste des filtres
	int choix;
	cin >> choix;
	if (choix == 1 || choix == 2 || choix == 3 || choix == 4 || choix == 5) {
		if (choix == 1) {
			cout << "Donnez le chemin (et donc le nom) pour l'enregistrement ex: D:nouvelle_image.png" << endl;
			string chemin;
			cin >> chemin;
			imwrite(chemin, filtreMedian);	//on enregistre l'image dans le dossier voulu
			a.choix(save);
		}
		if (choix == 2) {
			cout << "Donnez le chemin (et donc le nom) pour l'enregistrement ex: D:nouvelle_image.png" << endl;
			string chemin;
			cin >> chemin;
			imwrite(chemin, filtreMedian);
			a.choix(filtreMedian);
		}
		if (choix == 3) {
			a.choix(save);
		}
		if (choix == 4) {
			a.choix(filtreMedian);
		}
		if (choix == 5) {
			a.Median(filtreMedian, save);	//ici on relance le filtre mais on remplace "image" par "filtre median" cela permet de faire l'action à l'infini
		}
	}
	else {
		cout << "il y a erreur sur la marchandise" << endl;	//si l'utilisateur rentre autre chose que 1, 2, 3, 4 ou 5, on le renvoie aux choix avec l'image initiale
		a.choix(save);
	}



}

void Fonctions::Changement_luminosite(Mat image)
{
	
	// Changement de luminosité dans l’image en utilisant la méthode convertTo()
	Mat imageBrighnessHigh100;
	image.convertTo(imageBrighnessHigh100, -1, 1, 100);
	Mat imageBrighnessLow100;
	image.convertTo(imageBrighnessLow100, -1, 1, -100);




	/*
Affichage de l’image de l’image originale et des deux nouvelles
images dans trois fenêtres différentes avec la méthode imshow ()
*/
	String windowNameBrightnessLow100 = "Brightness Decreased by 100";
	String windowNameOriginalImage = "Original Image";
	String windowNameBrightnessHigh100 = "Brightness Increased by 100";
	//String windowNameBrightnessLow100 = "Brightness Decreased by 100";
	namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
	namedWindow(windowNameBrightnessHigh100, WINDOW_NORMAL);
	namedWindow(windowNameBrightnessLow100, WINDOW_NORMAL);

	imshow(windowNameOriginalImage, image);
	imshow(windowNameBrightnessHigh100, imageBrighnessHigh100);
	imshow(windowNameBrightnessLow100, imageBrighnessLow100);

	// Sauvegarde d’une image traitée à l'aide de la méthode imwrite ()
	imwrite("C:\My_new_image.jpg", imageBrighnessHigh100);
	waitKey(0);
	destroyAllWindows();
	Fonctions a;
	a.choix(image);
		

}

void Fonctions::Gaussien(Mat image, Mat save)
{
	Fonctions a;
	Mat filtreGauss;
	GaussianBlur(image, filtreGauss, Size(7, 7), 0, 0);		// on prend l'image de base, le nom de la nouvelle puis une taille "Size(-,-) puis 0 0
	String windowNameGauss = "Filtre gaussien";
	String windowNameOriginalImage = "Original Image";
	namedWindow(windowNameGauss, WINDOW_NORMAL);
	namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
	imshow(windowNameOriginalImage, image);
	imshow(windowNameGauss, filtreGauss);
	waitKey(0);
	destroyAllWindows();
	cout << "Que voulez-vous faire ?" << endl;
	cout << "[1] - Enregistrer le resultat et continuer avec l'image initiale" << endl;
	cout << "[2] - Enregistrer le resultat et continuer avec la nouvelle image" << endl;
	cout << "[3] - Ne pas enregistrer le resultat et cotinuer avec l'image initiale" << endl;
	cout << "[4] - Ne pas enregistrer le resultat et continuer avec la nouvelle image" << endl;
	cout << "[5] - Appliquer le filtre a cette nouvelle image (n'enregistre pas cette nouvelle image)" << endl;
	int choix;
	cin >> choix;
	if (choix == 1 || choix == 2 || choix == 3 || choix == 4 || choix == 5) {
		if (choix == 1) {
			cout << "Donnez le chemin (et donc le nom) pour l'enregistrement ex: D:nouvelle_image.png" << endl;
			string chemin;
			cin >> chemin;
			imwrite(chemin, filtreGauss);	//on enregistre l'image dans le dossier voulu
			a.choix(save);
		}
		if (choix == 2) {
			cout << "Donnez le chemin (et donc le nom) pour l'enregistrement ex: D:nouvelle_image.png" << endl;
			string chemin;
			cin >> chemin;
			imwrite(chemin, filtreGauss);
			a.choix(filtreGauss);
		}
		if (choix == 3) {
			a.choix(save);
		}
		if (choix == 4) {
			a.choix(filtreGauss);
		}
		if (choix == 5) {
			a.Gaussien(filtreGauss, save);	
		}
	}
	else {
		cout << "il y a erreur sur la marchandise" << endl;	
		a.choix(save);
	}
}

void Fonctions::Seuillage(Mat image, Mat save)
{
	Fonctions a;
	Mat seuillage;
	threshold(image, seuillage, 127, 255, THRESH_BINARY);
	String windowNameseuillage = "Seuillage";
	String windowNameOriginalImage = "Original Image";
	namedWindow(windowNameseuillage, WINDOW_NORMAL);
	namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
	imshow(windowNameOriginalImage, image);
	imshow(windowNameseuillage, seuillage);
	waitKey(0);
	destroyAllWindows();

	cout << "Que voulez-vous faire ?" << endl;
	cout << "[1] - Enregistrer le resultat et continuer avec l'image initiale" << endl;
	cout << "[2] - Enregistrer le resultat et continuer avec la nouvelle image" << endl;
	cout << "[3] - Ne pas enregistrer le resultat et cotinuer avec l'image initiale" << endl;
	cout << "[4] - Ne pas enregistrer le resultat et continuer avec la nouvelle image" << endl;
	cout << "[5] - Appliquer le filtre a cette nouvelle image (n'enregistre pas cette nouvelle image)" << endl;
	int choix;
	cin >> choix;
	if (choix == 1 || choix == 2 || choix == 3 || choix == 4 || choix == 5) {
		if (choix == 1) {
			cout << "Donnez le chemin (et donc le nom) pour l'enregistrement ex: D:nouvelle_image.png" << endl;
			string chemin;
			cin >> chemin;
			imwrite(chemin, seuillage);	//on enregistre l'image dans le dossier voulu
			a.choix(save);
		}
		if (choix == 2) {
			cout << "Donnez le chemin (et donc le nom) pour l'enregistrement ex: D:nouvelle_image.png" << endl;
			string chemin;
			cin >> chemin;
			imwrite(chemin, seuillage);
			a.choix(seuillage);
		}
		if (choix == 3) {
			a.choix(save);
		}
		if (choix == 4) {
			a.choix(seuillage);
		}
		if (choix == 5) {
			a.Seuillage(seuillage, save);	//il faut redemander les paramétres du seuillages sinon inutile
		}
	}
	else {
		cout << "il y a erreur sur la marchandise" << endl;
		a.choix(save);
	}

}

void Fonctions::Segmentation(Mat image)
{
	Fonctions a;
	Mat segmentation;
	watershed(image, segmentation);
	String windowNamesegmentation = "Segmentation";
	String windowNameOriginalImage = "Original Image";
	namedWindow(windowNamesegmentation, WINDOW_NORMAL);
	namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
	imshow(windowNameOriginalImage, image);
	imshow(windowNamesegmentation, segmentation);
	waitKey(0);
	destroyAllWindows();
}

void Fonctions::Gradient(Mat image)
{
}

void Fonctions::Dilatation(Mat image, Mat save)
{
	Fonctions a;
	Mat kernel = getStructuringElement(MORPH_RECT, Size(15, 16));
	Mat dilatation;
	dilate(image, dilatation,kernel);		// on prend l'image de base, le nom de la nouvelle puis "l'élément" 
	String windowNamedilatation = "Dilatation";
	String windowNameOriginalImage = "Original Image";
	namedWindow(windowNamedilatation, WINDOW_NORMAL);
	namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
	imshow(windowNameOriginalImage, image);
	imshow(windowNamedilatation, dilatation);
	waitKey(0);
	destroyAllWindows();
	cout << "Que voulez-vous faire ?" << endl;
	cout << "[1] - Enregistrer le resultat et continuer avec l'image initiale" << endl;
	cout << "[2] - Enregistrer le resultat et continuer avec la nouvelle image" << endl;
	cout << "[3] - Ne pas enregistrer le resultat et cotinuer avec l'image initiale" << endl;
	cout << "[4] - Ne pas enregistrer le resultat et continuer avec la nouvelle image" << endl;
	cout << "[5] - Appliquer le filtre a cette nouvelle image (n'enregistre pas cette nouvelle image)" << endl;
	int choix;
	cin >> choix;
	if (choix == 1 || choix == 2 || choix == 3 || choix == 4 || choix == 5) {
		if (choix == 1) {
			cout << "Donnez le chemin (et donc le nom) pour l'enregistrement ex: D:nouvelle_image.png" << endl;
			string chemin;
			cin >> chemin;
			imwrite(chemin, dilatation);	//on enregistre l'image dans le dossier voulu
			a.choix(save);
		}
		if (choix == 2) {
			cout << "Donnez le chemin (et donc le nom) pour l'enregistrement ex: D:nouvelle_image.png" << endl;
			string chemin;
			cin >> chemin;
			imwrite(chemin, dilatation);
			a.choix(dilatation);
		}
		if (choix == 3) {
			a.choix(save);
		}
		if (choix == 4) {
			a.choix(dilatation);
		}
		if (choix == 5) {
			a.Dilatation(dilatation, save);	
		}
	}
	else {
		cout << "il y a erreur sur la marchandise" << endl;	
		a.choix(save);
	}
}


void Fonctions::Erosion(Mat image, Mat save)
{
	Fonctions a;
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 16));
	Mat erosion;
	erode(image, erosion, element);		// on prend l'image de base, le nom de la nouvelle puis "l'élément" 
	String windowNameerosion = "Erosion";
	String windowNameOriginalImage = "Original Image";
	namedWindow(windowNameerosion, WINDOW_NORMAL);
	namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
	imshow(windowNameOriginalImage, image);
	imshow(windowNameerosion, erosion);
	waitKey(0);
	destroyAllWindows();
	cout << "Que voulez-vous faire ?" << endl;
	cout << "[1] - Enregistrer le resultat et continuer avec l'image initiale" << endl;
	cout << "[2] - Enregistrer le resultat et continuer avec la nouvelle image" << endl;
	cout << "[3] - Ne pas enregistrer le resultat et cotinuer avec l'image initiale" << endl;
	cout << "[4] - Ne pas enregistrer le resultat et continuer avec la nouvelle image" << endl;
	cout << "[5] - Appliquer le filtre a cette nouvelle image (n'enregistre pas cette nouvelle image)" << endl;
	int choix;
	cin >> choix;
	if (choix == 1 || choix == 2 || choix == 3 || choix == 4 || choix == 5) {
		if (choix == 1) {
			cout << "Donnez le chemin (et donc le nom) pour l'enregistrement ex: D:nouvelle_image.png" << endl;
			string chemin;
			cin >> chemin;
			imwrite(chemin, erosion);	//on enregistre l'image dans le dossier voulu
			a.choix(save);
		}
		if (choix == 2) {
			cout << "Donnez le chemin (et donc le nom) pour l'enregistrement ex: D:nouvelle_image.png" << endl;
			string chemin;
			cin >> chemin;
			imwrite(chemin, erosion);
			a.choix(erosion);
		}
		if (choix == 3) {
			a.choix(save);
		}
		if (choix == 4) {
			a.choix(erosion);
		}
		if (choix == 5) {
			a.Erosion(erosion, save);
		}
	}
	else {
		cout << "il y a erreur sur la marchandise" << endl;
		a.choix(save);
	}
}

void Fonctions::Contour(Mat image, Mat save)
{
	Fonctions a;
	Mat contour;
	Mat gris;
	Mat seuillage;
	
	

	Canny(image, contour, 10, 350); //on aurait pu mettre un filtre gris avant (pour faciliter la reconnaissance des contours) mais finalement, aprés plusieurs tests, le résultat est mieux sans
	
	String windowNamecontour = "contour";
	String windowNameOriginalImage = "Original Image";
	namedWindow(windowNamecontour, WINDOW_NORMAL);
	namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
	imshow(windowNameOriginalImage, image);
	imshow(windowNamecontour, contour);
	waitKey(0);
	destroyAllWindows();

	cout << "Que voulez-vous faire ?" << endl;
	cout << "[1] - Enregistrer le resultat et continuer avec l'image initiale" << endl;
	cout << "[2] - Enregistrer le resultat et continuer avec la nouvelle image" << endl;
	cout << "[3] - Ne pas enregistrer le resultat et cotinuer avec l'image initiale" << endl;
	cout << "[4] - Ne pas enregistrer le resultat et continuer avec la nouvelle image" << endl;
	
	int choix;
	cin >> choix;
	if (choix == 1 || choix == 2 || choix == 3 || choix == 4) {
		if (choix == 1) {
			cout << "Donnez le chemin (et donc le nom) pour l'enregistrement ex: D:nouvelle_image.png" << endl;
			string chemin;
			cin >> chemin;
			imwrite(chemin, contour);
			a.choix(save);
		}
		if (choix == 2) {
			cout << "Donnez le chemin (et donc le nom) pour l'enregistrement ex: D:nouvelle_image.png" << endl;
			string chemin;
			cin >> chemin;
			imwrite(chemin, contour);
			a.choix(contour);
		}
		if (choix == 3) {
			a.choix(save);
		}
		if (choix == 4) {
			a.choix(contour);
		}
		
	}
	else {
		cout << "il y a erreur sur la marchandise" << endl;
		a.choix(save);
	}
}


Fonctions::~Fonctions()
{
}
