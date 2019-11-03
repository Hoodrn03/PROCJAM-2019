#pragma once

#include "SFML/Graphics.hpp"

class Cell
{
	// Constructor 

public:

	Cell();

	Cell(sf::Vector2f position);

	// Deconstructor 

	~Cell();

	// Data Members 

private:

	sf::RectangleShape m_CellBody; 

public:

	const sf::Vector2f m_CellSize = sf::Vector2f(48, 48); 

	// Member Functions

public:

	void m_DrawCell(sf::RenderWindow& window);

};