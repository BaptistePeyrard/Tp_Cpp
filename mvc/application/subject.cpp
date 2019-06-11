#include "subject.h"
#include <iostream>

/**
 * Constructor
 */
Subject::Subject()
{
}

/**
 * Add an observer to the collection
 * @param observer: Observer to add
 */
void Subject::addObserver(Observer* observer)
{
	observers.push_back(observer);
}

/**
 * Notifies all the observers of the subject
 */
void Subject::notify()
{
	for (int iObserver = 0; iObserver < observers.size(); ++iObserver)
	{
		std::cout << "bonjour";
		int choix;
		std::cin >> choix;
		
		observers[iObserver]->notify();
	}
}
