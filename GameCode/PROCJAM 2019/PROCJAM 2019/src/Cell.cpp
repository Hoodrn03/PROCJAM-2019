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

void Cell::m_DrawCell(sf::RenderWindow& window, sf::Vector2f upperBounds, sf::Vector2f lowerBounds)
{
	float l_fBuffer = 55.f; 

	if ((m_CellBody.getPosition().x > upperBounds.x - l_fBuffer && m_CellBody.getPosition().y > upperBounds.y - l_fBuffer) &&
		(m_CellBody.getPosition().x < upperBounds.x + lowerBounds.x + l_fBuffer && m_CellBody.getPosition().y < upperBounds.y + lowerBounds.y + l_fBuffer))
	{
		window.draw(m_CellBody);
	}
}

void Cell::m_DrawCell(sf::RenderWindow& window, sf::View & view)
{
	sf::Vector2f l_ViewCenter(window.getView().getCenter());
	sf::Vector2f l_ViewSize(window.getView().getSize() + sf::Vector2f(100, 100));

	sf::FloatRect l_CurrentViewRect(l_ViewCenter - l_ViewSize / 2.f, l_ViewSize);

	if (l_CurrentViewRect.contains(m_CellBody.getPosition()))
	{
		window.draw(m_CellBody);
	}

}

sf::Vector2f Cell::m_GetCellPosition()
{
	return m_CellBody.getPosition();
}

void Cell::m_SetTile(int tileNumber)
{
	switch (tileNumber)
	{
	case 1:
		m_CurrentTile = Tile::road;
		m_CellBody.setFillColor(sf::Color::Magenta); 
		break;
	case 2:
		m_CurrentTile = Tile::mountain;
		break;
	default:
		m_CurrentTile = Tile::grass;
		break;
	}
}

Tile Cell::m_GetTile()
{
	return m_CurrentTile;
}
