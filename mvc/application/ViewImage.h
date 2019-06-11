#pragma once
#include "observer.h"
#include "view.h"
#include "controller.h"

class ViewImage : public View
{
private:

	Controller& controller;

	Image image;

public:
	ViewImage(Controller& _controller);

	void notify();

	void display();

	//~ViewImage();
};

