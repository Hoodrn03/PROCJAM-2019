#pragma once

#include <iostream>
#include <deque>

#include "SFML/Graphics.hpp"

#include "Cell.h"

/*! \class This will hold the grid which will form the game map. */
class Grid
{
	// Constructor 

public:

	Grid();

	// Deconstructor 

	~Grid();

	// Data Members 

private:

	/*! \var This vector will hold multiple cells, each cell acts as a single map tile. */
	std::deque<std::deque<Cell>> v_Grid;

	// Member Functions 

public:

	/*! \fn CreateGrid This will form a starting grid for the game. 
	param one: The number of rows for the grid.
	param two: The number of columns for the grid. 
	*/
	void m_CreateGrid(unsigned int rows, unsigned int columns);

	void m_UpdateGrid(); 

	/*! \fn DrawGrid This will draw the grid into the game world. 
	param one: The main game window to draw the map. 
	*/
	void m_DrawGrid(sf::RenderWindow& window);

	void m_AddCellsUp();

	void m_AddCellsDown(); 

	void m_AddCellsLeft();

	void m_AddCellsRight(); 

};