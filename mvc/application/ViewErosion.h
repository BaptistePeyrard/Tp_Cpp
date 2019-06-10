#pragma once
#include "observer.h"
#include "view.h"
#include "controller.h"

class ViewErosion : public View
{
private:

	Controller& controller;

	Image image;

public:
	ViewErosion(Controller& _controller);

	void notify();

	void display();

	//~ViewErosion();
};

