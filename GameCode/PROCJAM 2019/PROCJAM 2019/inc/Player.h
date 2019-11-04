#pragma once

#include <iostream>

#include "SFML/Graphics.hpp"

#include "GameView.h"

class Player: public GameView
{
	// Constructor 

public:

	Player();

	// Deconstructor

	~Player();

	// Data Members 

private:

	sf::CircleShape m_PlayerBody;

	sf::Vector2f m_MovementVector;

	const float m_fSpeed = 1.5f;

	// Member Functions 

public:

	void m_DrawPlayer(sf::RenderWindow& window); 

	void m_Update(); 

	void m_Movement(); 

};