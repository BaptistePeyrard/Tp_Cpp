#pragma once
#include "observer.h"
#include "view.h"
#include "controller.h"

class ViewDilatation : public View
{
private:

	Controller& controller;

	Image image;

public:
	ViewDilatation(Controller& _controller);

	void notify();

	void display();

	//~ViewDilatation();
};

