#include "GameView.h"

GameView::GameView()
{
}

GameView::~GameView()
{
}

/*! \fn CreateView Used to give the empty view a size.
param one: The width for the view.
param two: The height for the view.
*/
void GameView::m_CreateView(float width, float height)
{
	m_ThisView.setSize(width, height); 
}

/*! \fn MoveView This will set the center of the view to a new position.
param one: The new position for the view.
*/
void GameView::m_MoveView(sf::Vector2f newPos)
{
	if (newPos != m_CurrentPosition)
	{
		m_CurrentPosition = newPos;

		m_ThisView.setCenter(m_CurrentPosition); 
	}
}

/*! \fn SetCurrentWindow This will assign this view to the window.
param one: The game window to assign the view.
*/
void GameView::m_SetCurrentWindow(sf::RenderWindow& window)
{
	window.setView(m_ThisView);
}

sf::Vector2f GameView::m_GetUpperBounds()
{
	sf::Vector2f l_ReturnVector; 

	l_ReturnVector = sf::Vector2f(m_ThisView.getCenter().x - (m_ThisView.getSize().x * 0.5f), m_ThisView.getCenter().y - (m_ThisView.getSize().y * 0.5f));

	return l_ReturnVector;
}

sf::Vector2f GameView::m_GetLowerBounds()
{
	sf::Vector2f l_ReturnVector;

	l_ReturnVector = sf::Vector2f(m_ThisView.getCenter().x + (m_ThisView.getSize().x * 0.5f), m_ThisView.getCenter().y + (m_ThisView.getSize().y * 0.5f));

	return l_ReturnVector;
}

sf::View& GameView::m_GetView()
{
	return m_ThisView; 
}
