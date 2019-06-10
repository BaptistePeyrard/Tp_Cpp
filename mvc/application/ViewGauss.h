#pragma once
#include "observer.h"
#include "view.h"
#include "controller.h"

class ViewGauss : public View
{
private:

	Controller& controller;

	Image image;

public:
	ViewGauss(Controller& _controller);

	void notify();

	void display();

	//~ViewGauss();
};

