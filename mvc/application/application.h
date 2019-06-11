#include "Controller.h"
#include "ViewMenu.h"


class Application
{
private:
	Controller controller;
	ViewMenu viewmenu;
public:
	/**
	 * Constructor
	 */
	Application();

	/**
	 * Runs the application
	 */
	void run();
};

