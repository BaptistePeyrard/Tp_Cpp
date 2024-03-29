#include "Fonctions.h"
#include "Image.h"

Fonctions::Fonctions()
{
}



void Fonctions::image(Mat image)	//affiche tout simplement l'image de base, pas besoin de sauvegarde car pas de modifications potentielles
{

	String windowNameOriginalImage = "Original Image";
	namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
	imshow(windowNameOriginalImage, image);
	waitKey(0);
	destroyAllWindows();
	
}

void Fonctions::couleur(Mat image, Mat save)
{
	
	Mat couleur;

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
		cvtColor(image, couleur, COLOR_BGR2HSV);
	if (choix_couleur == 3)
		cvtColor(image, couleur, COLOR_BGR2HLS);
	if (choix_couleur == 4)
		cvtColor(image, couleur, COLOR_YUV2BGR);






	String windowNamecouleur = "image color�";
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
			image = save; //on prend save car si on applique l'option 5, l'image sera modifi�
		}
		if (choix == 2) {
			cout << "Donnez le chemin (et donc le nom) pour l'enregistrement ex: D:nouvelle_image.png" << endl;
			string chemin;
			cin >> chemin;
			imwrite(chemin, couleur);
			image = couleur;
		}
		if (choix == 3) {
			image = save;
		}
		if (choix == 4) {
			image = couleur;
		}
		if (choix == 5) {
			Fonctions a;
			a.couleur(couleur, save);
		}
	}
	else {
		cout << "il y a erreur sur la marchandise" << endl;
	
	}
}

void Fonctions::Median(Mat image, Mat save)	//image sera l'image servant de modele, elle sera donc modifi� si ce filtre est appliqu� plusieurs fois � la suite, save permet de renvoyer l'image initial � la fin
{



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
	cout << "[5] - Appliquer le filtre a cette nouvelle image (n'enregistre pas cette nouvelle image)" << endl;	//permet de recommencer immediatement sans repasser par la liste des filtres
	int choix;
	cin >> choix;
	if (choix == 1 || choix == 2 || choix == 3 || choix == 4 || choix == 5) {
		if (choix == 1) {
			cout << "Donnez le chemin (et donc le nom) pour l'enregistrement ex: D:nouvelle_image.png" << endl;
			string chemin;
			cin >> chemin;
			imwrite(chemin, filtreMedian);	//on enregistre l'image dans le dossier voulu
			image = save;
		}
		if (choix == 2) {
			cout << "Donnez le chemin (et donc le nom) pour l'enregistrement ex: D:nouvelle_image.png" << endl;
			string chemin;
			cin >> chemin;
			imwrite(chemin, filtreMedian);
			image = filtreMedian;
		}
		if (choix == 3) {
			image = save;
		}
		if (choix == 4) {
			image = filtreMedian;
		}
		if (choix == 5) {
			Fonctions a;
			a.Median(filtreMedian, save);	//ici on relance le filtre mais on remplace "image" par "filtre median" cela permet de faire l'action � l'infini
		}
	}
	else {
		cout << "il y a erreur sur la marchandise" << endl;	//si l'utilisateur rentre autre chose que 1, 2, 3, 4 ou 5, on le renvoie aux choix avec l'image initiale
		
	
	}



}

void Fonctions::Changement_luminosite(Mat image)
{
	
	// Changement de luminosit� dans l�image en utilisant la m�thode convertTo()
	Mat imageBrighnessHigh100;
	image.convertTo(imageBrighnessHigh100, -1, 1, 100);
	Mat imageBrighnessLow100;
	image.convertTo(imageBrighnessLow100, -1, 1, -100);




	/*
Affichage de l�image de l�image originale et des deux nouvelles
images dans trois fen�tres diff�rentes avec la m�thode imshow ()
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


	waitKey(0);
	destroyAllWindows();
	cout << "Que voulez-vous faire ?" << endl;
	cout << "[1] - Enregistrer le resultat et continuer avec l'image initiale" << endl;
	cout << "[2] - Ne pas enregistrer le resultat et cotinuer avec l'image initiale" << endl;
	int choix;
	cin >> choix;
	if (choix == 1 || choix == 2) {
		if (choix == 1) {
			cout << "Donnez le chemin (et donc le nom) pour l'enregistrement de l'image 1 ex: D:nouvelle_image1.png" << endl;
			string chemin1;
			cin >> chemin1;
			cout << "Donnez le chemin (et donc le nom) pour l'enregistrement de l'image 1 ex: D:nouvelle_image1.png" << endl;
			string chemin2;
			cin >> chemin2;
			imwrite(chemin1, imageBrighnessHigh100);//on enregistre les images dans le dossier voulu
			imwrite(chemin2, imageBrighnessLow100);
		}

		if (choix == 3) {
		}
	}
	else {
		cout << "il y a erreur sur la marchandise" << endl;
	}


}

void Fonctions::Gaussien(Mat image, Mat save)
{
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
			image = save;
		}
		if (choix == 2) {
			cout << "Donnez le chemin (et donc le nom) pour l'enregistrement ex: D:nouvelle_image.png" << endl;
			string chemin;
			cin >> chemin;
			imwrite(chemin, filtreGauss);
			image = filtreGauss;
		}
		if (choix == 3) {
			image = save;
		}
		if (choix == 4) {
			image = filtreGauss;
		}
		if (choix == 5) {
			Fonctions a;
			a.Gaussien(filtreGauss, save);
		}
	}
	else {
		cout << "il y a erreur sur la marchandise" << endl;
		image = save;
	}
}

void Fonctions::Seuillage(Mat image, Mat save)
{
	
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
			image = save;
		}
		if (choix == 2) {
			cout << "Donnez le chemin (et donc le nom) pour l'enregistrement ex: D:nouvelle_image.png" << endl;
			string chemin;
			cin >> chemin;
			imwrite(chemin, seuillage);
			image = seuillage;
		}
		if (choix == 3) {
			image = save;
		}
		if (choix == 4) {
			image = seuillage;
		}
		if (choix == 5) {
			Fonctions a;
			a.Seuillage(seuillage, save);	//il faut redemander les param�tres du seuillages sinon inutile
		}
	}
	else {
		cout << "il y a erreur sur la marchandise" << endl;
		image = save;
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
	Fonctions a;
	Mat gradient;
	Sobel(image, gradient, CV_8U, 1, 1, 5);
	String windowNamegradient = "Gradient";
	String windowNameOriginalImage = "Original Image";
	namedWindow(windowNamegradient, WINDOW_NORMAL);
	namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
	imshow(windowNameOriginalImage, image);
	imshow(windowNamegradient, gradient);
	waitKey(0);
	destroyAllWindows();
}

void Fonctions::Dilatation(Mat image, Mat save)
{
	
	Mat kernel = getStructuringElement(MORPH_RECT, Size(15, 16));
	Mat dilatation;
	dilate(image, dilatation, kernel);		// on prend l'image de base, le nom de la nouvelle puis "l'�l�ment" 
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
			image = save;
		}
		if (choix == 2) {
			cout << "Donnez le chemin (et donc le nom) pour l'enregistrement ex: D:nouvelle_image.png" << endl;
			string chemin;
			cin >> chemin;
			imwrite(chemin, dilatation);
			image = dilatation;
		}
		if (choix == 3) {
			image = save;
		}
		if (choix == 4) {
			image = dilatation;
		}
		if (choix == 5) {
			Fonctions a;
			a.Dilatation(dilatation, save);
		}
	}
	else {
		cout << "il y a erreur sur la marchandise" << endl;
		image = save;
	}
}


void Fonctions::Erosion(Mat image, Mat save)
{

	Mat element = getStructuringElement(MORPH_RECT, Size(15, 16));
	Mat erosion;
	erode(image, erosion, element);		// on prend l'image de base, le nom de la nouvelle puis "l'�l�ment" 
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
			image = save;
		}
		if (choix == 2) {
			cout << "Donnez le chemin (et donc le nom) pour l'enregistrement ex: D:nouvelle_image.png" << endl;
			string chemin;
			cin >> chemin;
			imwrite(chemin, erosion);
			image = erosion;
		}
		if (choix == 3) {
			image = save;
		}
		if (choix == 4) {
			image = erosion;
		}
		if (choix == 5) {
			Fonctions a;
			a.Erosion(erosion, save);
		}
	}
	else {
		cout << "il y a erreur sur la marchandise" << endl;
		image = save;
	}
}

void Fonctions::Contour(Mat image, Mat save)
{
	
	Mat contour;

	/*

	Autre utilisation, avec un filtre gris avant le tra�age des contours :

	Mat gris;
	cvtColor(image, gris, COLOR_BGR2GRAY);
	Canny(gris, contour, 10, 350);
	*/



	Canny(image, contour, 10, 350); //on aurait pu mettre un filtre gris avant (pour faciliter la reconnaissance des contours) mais finalement, apr�s plusieurs tests, le r�sultat est mieux sans

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
			image = save;
		}
		if (choix == 2) {
			cout << "Donnez le chemin (et donc le nom) pour l'enregistrement ex: D:nouvelle_image.png" << endl;
			string chemin;
			cin >> chemin;
			imwrite(chemin, contour);
			image = contour;
		}
		if (choix == 3) {
			image = save;
		}
		if (choix == 4) {
			image = contour;
		}

	}
	else {
		cout << "il y a erreur sur la marchandise" << endl;
		image = save;
	}
}


Fonctions::~Fonctions()
{
}

