#include "observer.h"
#include "view.h"
#include "controller.h"

class ViewMenu : public View
{
private:

	Controller& controller;

	Image image;

public:
	ViewMenu(Controller& _controller);

	void notify();

	void display();

	//~ViewMenu();
};

