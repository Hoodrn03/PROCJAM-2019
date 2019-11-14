#pragma once

#include <iostream>
#include <deque>

#include "SFML/Graphics.hpp"

#include "CollisionDetection/BoxCollision.h"
#include "Random/RandomGenerator.h"

#include "Cell.h"

struct gridPos
{
	int x, y; 
};

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

	int m_iAddCellDirection = 0; 

	/*! \var This vector will hold multiple cells, each cell acts as a single map tile. */
	std::deque<std::deque<Cell>> v_Grid;

	sf::Vector2f m_TopLeft;

	sf::Vector2f m_BottomRight; 

	sf::RectangleShape m_Borderline; 

	std::unique_ptr<Cell> m_LastCell;

	bool m_bPlayerOutside = false;

	// Member Functions 

public:

	// Grid Creation

	/*! \fn CreateGrid This will form a starting grid for the game. 
	param one: The number of rows for the grid.
	param two: The number of columns for the grid. 
	*/
	void m_CreateGrid(unsigned int rows, unsigned int columns);

	void m_CreateGrid(unsigned int rows, unsigned int columns, sf::Vector2f startingPos);

	void m_CreateBorderline(); 

	void m_SetTopAndBottom();

	void m_AddCellsUp();

	void m_AddCellsDown();

	void m_AddCellsLeft();

	void m_AddCellsRight();

	void m_CheckCellPositions(); 

	bool m_PlayerOutsideGrid(); 

	// Position Data 

	sf::Vector2f m_GetBorderlineCenter(); 

	gridPos m_FindCellGridPos(Cell* cellToCheck);

	Cell & m_FindCellWithPosition(gridPos cellPos);

	Cell& m_FindCellWithPosition(sf::Vector2f cellPos);

	sf::Vector2f m_GetStartingPositionFromGrid(); 

	// Map Generation

	void m_CreateRoad();

	void m_CreateMountain();

	void m_CreateGrass(); 

	Tile m_GetTileToGenerate(gridPos currentGridPosition); 

	// Update

	void m_UpdateGrid(); 

	void m_CheckForCollision(sf::Vector2f playerPos); 

	// Rendering

	/*! \fn DrawGrid This will draw the grid into the game world. 
	param one: The main game window to draw the map. 
	*/
	void m_DrawGrid(sf::RenderWindow& window);

	void m_DrawGrid(sf::RenderWindow& window, sf::Vector2f upperBounds, sf::Vector2f lowerBounds);

	void m_DrawGrid(sf::RenderWindow& window, sf::View& view);



};