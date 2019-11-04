#pragma once

#include <iostream>

#include "SFML/Graphics.hpp"

class GameView
{
	// Constructor 

public:

	GameView();

	// Deconstructor 

	~GameView();

	// Data Members 

private:

	sf::View m_ThisView; 

	sf::Vector2f m_CurrentPosition;

	// Member Functions

public:

	void m_CreateView(float width, float height);

	void m_MoveView(sf::Vector2f newPos);

	void m_SetCurrentWindow(sf::RenderWindow& window);

};