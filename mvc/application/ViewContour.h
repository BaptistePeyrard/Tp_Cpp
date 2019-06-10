#pragma once
#include "observer.h"
#include "view.h"
#include "controller.h"

class ViewContour : public View
{
private:

	Controller& controller;

	Image image;

public:
	ViewContour(Controller& _controller);

	void notify();

	void display();

	//~ViewContour();
};

