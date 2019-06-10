#pragma once
#include "observer.h"
#include "view.h"
#include "controller.h"


class ViewCouleur : public View
{

private:

	Controller& controller;
	
	Image image;

public:
	ViewCouleur(Controller& _controller);

	void notify();

	void display();

	//~ViewCouleur();
};

