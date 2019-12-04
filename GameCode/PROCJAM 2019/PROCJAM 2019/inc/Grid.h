#pragma once

#include <iostream>
#include <deque>

#include "SFML/Graphics.hpp"

#include "CollisionDetection/BoxCollision.h"
#include "Random/RandomGenerator.h"

#include "Cell.h"



/*! \class This will hold the grid which will form the game map. */
class Grid : public BoxCollision, public RandomGenerator
{
	// Constructor 

public:

	Grid();

	// Deconstructor 

	~Grid();

	// Data Members 

private:

	std::deque<std::deque<Cell>> v_GridOfCells; 

	// Member Functions 

public:

	// Creating Grid

	void m_CreateinitialGrid(int numberOfLoops); 

	void m_AddCells(int direction);

	// Rendering 

	void m_DrawGrid(sf::RenderWindow & window);

	void m_DrawGrid(sf::RenderWindow& window, sf::View& viewRect);
};