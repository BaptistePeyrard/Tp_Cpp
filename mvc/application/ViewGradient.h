#pragma once
#include "observer.h"
#include "view.h"
#include "controller.h"

class ViewGradient : public View
{
private:

	Controller& controller;

	Image image;

public:
	ViewGradient(Controller& _controller);

	void notify();

	void display();

	//~ViewGradient();
};

