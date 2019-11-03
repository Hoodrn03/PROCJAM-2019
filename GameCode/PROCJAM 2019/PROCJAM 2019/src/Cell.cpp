#include "Cell.h"

Cell::Cell()
{
	m_CellBody.setSize(m_CellSize);

	m_CellBody.setOutlineThickness(1.f);

	m_CellBody.setOutlineColor(sf::Color::Blue); 

	m_CellBody.setPosition(100, 100); 
}

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

void Cell::m_DrawCell(sf::RenderWindow& window)
{
	window.draw(m_CellBody);
}
