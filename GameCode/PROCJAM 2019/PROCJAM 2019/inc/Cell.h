#pragma once

#include "SFML/Graphics.hpp"


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

public:

	/*! \var The constant size used for every cell in the map. */
	const sf::Vector2f m_CellSize = sf::Vector2f(48, 48); 

	// Member Functions

public:


};