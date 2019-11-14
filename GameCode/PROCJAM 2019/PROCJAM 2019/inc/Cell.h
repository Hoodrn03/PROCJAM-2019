#pragma once

#include "SFML/Graphics.hpp"

/*! \enum Tile This will be used to determine which tile this cell currently is. */
enum class Tile
{
	null = 0x001,		/*!< This is the base value for a Tile. */
	grass = 0x002,		/*!< This is the tile for grass, the basic tile used to fill the grid. */
	road = 0x003,		/*!< This will be passable but there to add more detail into the map. */
	mountain = 0x004	/*!< This will be the default unpassable tile in the game. */
};

/*! \class Cell This will be a single tile within the game world, it will have a position, id and a tile. */
class Cell
{
	// Constructor 

public:

	Cell();

	/*! \constructor Overload 
	param one: The position to place the cell. 
	*/
	Cell(sf::Vector2f position);

	// Deconstructor 

	~Cell();

	// Data Members 

private:

	/*! \var The main cell body used to hold the sprite for the cell. */
	sf::RectangleShape m_CellBody; 

	/*! \var The current tile assigned to this cell. */
	Tile m_CurrentTile = Tile::null;

public:

	/*! \var The constant size used for every cell in the map. */
	const sf::Vector2f m_CellSize = sf::Vector2f(48, 48); 

	/*! \var The id for this cell, unique to this cell. */
	int l_iID = 0; 

	// Member Functions

public:

	// Rendering 

	/*! \fn DrawCell This will draw this cell into the game. 
	param One: The window in which to draw this cell. 
	*/
	void m_DrawCell(sf::RenderWindow& window);

	/*! \fn DrawCell (overload one) This will draw this cell into the game.
	param One: The window in which to draw this cell.
	param Two: The top left of the current game view.
	Param Three: The bottom right of the current game view. 
	*/
	void m_DrawCell(sf::RenderWindow& window, sf::Vector2f upperBounds, sf::Vector2f lowerBounds);

	/*! \fn DrawCell (overload two) This will draw this cell into the game.
	param One: The window in which to draw this cell.
	param Two: The view currenly used in the game. 
	*/
	void m_DrawCell(sf::RenderWindow& window, sf::View& view);

	// Positioning


	/*! \fn SetCellPosition This will move the cell to a new position
	param One: The new position for the cell.
	*/
	void m_SetCellPosition(sf::Vector2f newPos);

	/*! \fn GetCellPosition This will return the current position of the cell. */
	sf::Vector2f m_GetCellPosition(); 

	/*! \fn GetCellBounds This will return a float rect construct of the current cell, contains top left as well as
							bottom right. */
	sf::FloatRect m_GetCellBounds();

	// Tile Assignemnt

	/*! \fn SetTile This will assign a tile to the cell.
	param One: an integer number associated with a tile.
	*/
	void m_SetTile(int tileNumber);

	/*! \fn SetTile (overload one) This will assign a tile to the cell.
	param One: The tile to assign to the cell.
	*/
	void m_SetTile(Tile newTile);

	/*! \fn GetTile This will return the curret tile type assigned to this cell. */
	Tile m_GetTile(); 

	/*! \fn IsTilePassabe Using the current tile of the cell it will check if the cell is passable by an entity. */
	bool m_IsTilePassable(); 
};