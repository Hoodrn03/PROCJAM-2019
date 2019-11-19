#pragma once

#include <cmath>

#include "SFML/Graphics.hpp"

class Movement
{
	// Constructor 

public:

	Movement()
	{

	}

	// Deconstructor 

	~Movement()
	{

	}

	// Data Members 

protected:

	sf::Vector2f m_MovementVector;

	// Member Functions 

public:

	sf::Vector2f m_GetMoveDirection(sf::Vector2f startPoint, sf::Vector2f endPos)
	{
		sf::Vector2f l_ReturnVector;

		// (x2 - x1) (y2- y1) gives a directional vector with a length. 

		l_ReturnVector = sf::Vector2f(endPos.x - startPoint.x, endPos.y - startPoint.y);

		// Square root of (x^2 + y^2) gives the magnitude of a vector. 

		float l_fVectorMagnitude = std::sqrt(std::pow(l_ReturnVector.x, 2) + std::pow(l_ReturnVector.y, 2));

		// Direction vector / magnitude == unit vector (a vector with direction but length of 1); 

		l_ReturnVector = l_ReturnVector / l_fVectorMagnitude; 

		return l_ReturnVector;
	}

};