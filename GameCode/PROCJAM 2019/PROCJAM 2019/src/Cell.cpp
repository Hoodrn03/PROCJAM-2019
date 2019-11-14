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

// Rendering 

/*! \fn DrawCell This will draw this cell into the game.
param One: The window in which to draw this cell.
*/
void Cell::m_DrawCell(sf::RenderWindow& window)
{
	window.draw(m_CellBody);
}

/*! \fn DrawCell (overload one) This will draw this cell into the game.
param One: The window in which to draw this cell.
param Two: The top left of the current game view.
Param Three: The bottom right of the current game view.
*/
void Cell::m_DrawCell(sf::RenderWindow& window, sf::Vector2f upperBounds, sf::Vector2f lowerBounds)
{
	float l_fBuffer = 55.f; 

	if ((m_CellBody.getPosition().x > upperBounds.x - l_fBuffer && m_CellBody.getPosition().y > upperBounds.y - l_fBuffer) &&
		(m_CellBody.getPosition().x < upperBounds.x + lowerBounds.x + l_fBuffer && m_CellBody.getPosition().y < upperBounds.y + lowerBounds.y + l_fBuffer))
	{
		window.draw(m_CellBody);
	}
}

/*! \fn DrawCell (overload two) This will draw this cell into the game.
param One: The window in which to draw this cell.
param Two: The view currenly used in the game.
*/
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

// Positioning 

/*! \fn SetCellPosition This will move the cell to a new position
param One: The new position for the cell.
*/
void Cell::m_SetCellPosition(sf::Vector2f newPos)
{
	m_CellBody.setPosition(newPos);
}

/*! \fn GetCellPosition This will return the current position of the cell. */
sf::Vector2f Cell::m_GetCellPosition()
{
	return m_CellBody.getPosition();
}

/*! \fn GetCellBounds This will return a float rect construct of the current cell, contains top left as well as
						bottom right. */
sf::FloatRect Cell::m_GetCellBounds()
{
	return sf::FloatRect(m_CellBody.getPosition(), m_CellBody.getSize());
}

// Tile Assignment 

/*! \fn SetTile This will assign a tile to the cell.
param One: an integer number associated with a tile.
*/
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

/*! \fn SetTile (overload one) This will assign a tile to the cell.
param One: The tile to assign to the cell.
*/
void Cell::m_SetTile(Tile newTile)
{
	m_CurrentTile = newTile;

	switch (newTile)
	{
	case Tile::road:
		m_CellBody.setFillColor(sf::Color(155, 118, 83));
		break;
	case Tile::mountain:
		m_CellBody.setFillColor(sf::Color(121, 99, 66));
		break;
	case Tile::grass:
		m_CellBody.setFillColor(sf::Color(96, 128, 56));
		break;
	default:
		
		break;
	}
}

/*! \fn GetTile This will return the curret tile type assigned to this cell. */
Tile Cell::m_GetTile()
{
	return m_CurrentTile;
}

/*! \fn IsTilePassabe Using the current tile of the cell it will check if the cell is passable by an entity. */
bool Cell::m_IsTilePassable()
{
	if (m_CurrentTile == Tile::mountain || m_CurrentTile == Tile::null)
	{
		return false;
	}
	else
	{
		return true; 
	}
}
