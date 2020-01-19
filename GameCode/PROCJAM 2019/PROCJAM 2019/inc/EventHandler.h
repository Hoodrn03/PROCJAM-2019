#pragma once

#include <iostream>

#include"SFML/Graphics.hpp"

/*! \class EventHandler Usedto handle events which cannot be handled within the area they are used. */
class EventHandler
{
	// Constructor 

public:

	EventHandler();

	// Deconstructor 

	~EventHandler();

	// Data Members 

private:

	sf::Event m_Event; 

	// Member Functions 

public:

	/*! \fn HandleEvents This will handle the main events within the game which cannot be handled elsewhere. 
	param one: The game window in which to poll the events. 
	*/
	void m_HandleEvents(sf::RenderWindow &window); 

	sf::Event m_GetEvent(); 

};