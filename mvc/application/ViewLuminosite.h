#pragma once
#include "observer.h"
#include "view.h"
#include "controller.h"

class ViewLuminosite : public View
{
private:

	Controller& controller;

	Image image;

public:
	ViewLuminosite(Controller& _controller);

	void notify();

	void display();

	//~ViewLuminosite();
};

