#pragma once
#include "observer.h"
#include "view.h"
#include "controller.h"

class ViewMedian : public View
{
private:

	Controller& controller;

	Image image;

public:
	ViewMedian(Controller& _controller);

	void notify();

	void display();

	//~ViewMedian();
};

