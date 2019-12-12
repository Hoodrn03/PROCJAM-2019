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

void Cell::m_DrawCell(sf::RenderWindow& window)
{
	window.draw(m_CellBody);
}

void Cell::m_SetPosition(sf::Vector2f newPos)
{
	m_CellBody.setPosition(newPos);
}

sf::Vector2f Cell::m_GetPosition()
{
	return m_CellBody.getPosition();
}

sf::FloatRect Cell::m_GetFloatRect()
{
	return m_CellBody.getGlobalBounds();
}

/*! \fn AddCell : This will be used to get the position of a new cell to add (0 = up, 1 = down, 2 = left, 3 = right)*/
sf::Vector2f Cell::m_AddCell(int direction)
{
	sf::Vector2f l_ReturnVector = m_CellBody.getPosition();

	switch (direction)
	{
	case 0:
		// Up 

		l_ReturnVector = sf::Vector2f(l_ReturnVector.x, l_ReturnVector.y - m_CellSize.y); 

		break;

	case 1:
		// Down 

		l_ReturnVector = sf::Vector2f(l_ReturnVector.x, l_ReturnVector.y + m_CellSize.y);

		break;

	case 2: 
		// Left 

		l_ReturnVector = sf::Vector2f(l_ReturnVector.x - m_CellSize.x, l_ReturnVector.y);

		break;

	case 3:
		// Right 

		l_ReturnVector = sf::Vector2f(l_ReturnVector.x + m_CellSize.x, l_ReturnVector.y);

		break;

	default:
		break;
	}

	return l_ReturnVector;
}

bool Cell::m_PointInsideCell(sf::Vector2f pointToCheck)
{
	if (m_InsideBox(m_CellBody.getPosition().x, m_CellBody.getPosition().y, m_CellSize.x, m_CellSize.y,
		pointToCheck.x, pointToCheck.y))
	{
		return true; 
	}

	return false;
}

void Cell::m_SetId(int newId)
{
	m_iID = newId;
}

int Cell::m_GetId()
{
	return m_iID;
}

void Cell::m_SetTile(tile newTile)
{
	m_ThisTile = newTile;

	if (m_ThisTile == tile::grass)
	{
		m_CellBody.setFillColor(sf::Color(145, 252, 0));
	}
	else if (m_ThisTile == tile::mountain)
	{
		m_CellBody.setFillColor(sf::Color(151, 124, 83));
	}
	else
	{
		m_CellBody.setFillColor(sf::Color::Magenta); 
	}
}

tile Cell::m_GetTile()
{
	return m_ThisTile;
}

bool Cell::m_IsPassable()
{
	if (m_ThisTile == tile::mountain)
	{
		return false;
	}
	else
	{
		return true; 
	}
}



