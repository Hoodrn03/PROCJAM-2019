#pragma once

#include <iostream>

#include "SFML/Graphics.hpp"

#include "Cell.h"

class Grid
{
	// Constructor 

public:

	Grid();

	// Deconstructor 

	~Grid();

	// Data Members 

private:

	std::vector<Cell> v_Grid; 

	// Member Functions 

public:

	void m_CreateGrid(int rows, int columns); 

	void m_DrawGrid(sf::RenderWindow& window);

};