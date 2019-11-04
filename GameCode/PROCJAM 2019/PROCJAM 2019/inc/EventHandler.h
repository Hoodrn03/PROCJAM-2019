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

	void m_HandleEvents(sf::RenderWindow &window); 



};