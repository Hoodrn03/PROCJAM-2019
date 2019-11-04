#include "Cell.h"

Cell::Cell()
{
	m_CellBody.setSize(m_CellSize);

	m_CellBody.setOutlineThickness(1.f);

	m_CellBody.setOutlineColor(sf::Color::Blue); 

	m_CellBody.setPosition(100, 100); 
}

/*! \constructor Overload
param one: The osition to place the cell.
*/
Cell::Cell(sf::Vector2f position)
{
	m_CellBody.setSize(m_CellSize);

	m_CellBody.setOutlineThickness(1.f);

	m_CellBody.setOutlineColor(sf::Color::Blue);

	m_CellBody.setPosition(position);
}

Cell::~Cell()
{
}

/*! \fn DrawCell This will draw this cell into the game.
param One: The window in which to draw this cell.
*/
void Cell::m_DrawCell(sf::RenderWindow& window)
{
	window.draw(m_CellBody);
}
