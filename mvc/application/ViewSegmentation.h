#pragma once
#include "observer.h"
#include "view.h"
#include "controller.h"

class ViewSegmentation : public View
{
private:

	Controller& controller;

	Image image;

public:
	ViewSegmentation(Controller& _controller);

	void notify();

	void display();

	//~ViewSegmentation();
};

