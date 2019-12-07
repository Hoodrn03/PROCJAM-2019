#pragma once

#include "SFML/Graphics.hpp"

#include "CollisionDetection/BoxCollision.h"

/*! \class Cell This will be a single tile within the game world, it will have a position, id and a tile. */
class Cell: public BoxCollision
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

	int m_iID = 0; 
	// Member Functions

public:

	// Rendering

	void m_DrawCell(sf::RenderWindow& window); 

	// Positioning 

	void m_SetPosition(sf::Vector2f newPos);

	sf::Vector2f m_GetPosition(); 

	sf::FloatRect m_GetFloatRect(); 

	sf::Vector2f m_AddCell(int direction);

	bool m_PointInsideCell(sf::Vector2f pointToCheck); 

	// Identifiying 

	void m_SetId(int newId); 

	int m_GetId(); 

};