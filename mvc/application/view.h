#pragma once
#include <string>
#include "observer.h"
#include <opencv2/opencv.hpp>
#include "C:\Users\bp686990\Desktop\Tp_Cpp-master\mvc\metier\Fonctions.h"

//Generic view
class View: public Observer
{
private:
	//Title of the view
	std::string title;
	// v3) Mat image;
public:

	/**
	 * Constructor
	 * @param _title: title of the view
	 */
	View(const std::string& _title);

	/**
	 * Clears console
	 */
	void clear() const;

	/**
	 * Displays generic dialog
	 */
	virtual void display() const;
};

