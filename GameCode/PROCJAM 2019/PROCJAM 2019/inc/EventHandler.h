#pragma once

#include <iostream>

#include"SFML/Graphics.hpp"

class EventHandler
{
	// Constructor 

public:

	EventHandler();

	// Deconstructor 

	~EventHandler();

	// Data Members 

private:


	// Member Functions 

public:

	/*! \fn HandleEvents This will handle the main events within the game which cannot be handled elsewhere. 
	param one: The game window in which to poll the events. 
	*/
	void m_HandleEvents(sf::RenderWindow &window); 



};