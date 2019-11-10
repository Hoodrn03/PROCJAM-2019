#pragma once

#include "SFML/Graphics.hpp"

enum class Tile
{
	null, grass, road, mountain
};

class Cell
{
	// Constructor 

public:

	Cell();

	/*! \constructor Overload 
	param one: The osition to place the cell. 
	*/
	Cell(sf::Vector2f position);

	// Deconstructor 

	~Cell();

	// Data Members 

private:

	/*! \var The main cell body used to hold the sprite for the cell. */
	sf::RectangleShape m_CellBody; 

	Tile m_CurrentTile = Tile::null;

public:

	/*! \var The constant size used for every cell in the map. */
	const sf::Vector2f m_CellSize = sf::Vector2f(48, 48); 

	int l_iID = 0; 

	// Member Functions

public:

	/*! \fn DrawCell This will draw this cell into the game. 
	param One: The window in which to draw this cell. 
	*/
	void m_DrawCell(sf::RenderWindow& window);

	/*! \fn DrawCell This will draw this cell into the game.
	param One: The window in which to draw this cell.
	*/
	void m_DrawCell(sf::RenderWindow& window, sf::Vector2f upperBounds, sf::Vector2f lowerBounds);

	void m_DrawCell(sf::RenderWindow& window, sf::View& view);

	/*! \fn GetCellPosition This will return the current position of the cell. */
	sf::Vector2f m_GetCellPosition(); 

	Tile m_GetTile(); 

	void m_SetCellPosition(sf::Vector2f newPos);

	void m_SetTile(int tileNumber);

	void m_SetTile(Tile newTile);

	sf::FloatRect m_GetCellBounds(); 
};