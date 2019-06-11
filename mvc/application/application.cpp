#include "application.h"

/**
 * Constructor
 */
Application::Application()
	: controller(), viewmenu(controller)
{
}

/**
 * Runs the application
 */
void Application::run()
{
	controller.notify();
}
