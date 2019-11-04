#include "GameView.h"

GameView::GameView()
{
}

GameView::~GameView()
{
}

void GameView::m_CreateView(float width, float height)
{
	m_ThisView.setSize(width, height); 
}

void GameView::m_MoveView(sf::Vector2f newPos)
{
	if (newPos != m_CurrentPosition)
	{
		m_CurrentPosition = newPos;

		m_ThisView.setCenter(m_CurrentPosition); 
	}
}

void GameView::m_SetCurrentWindow(sf::RenderWindow& window)
{
	window.setView(m_ThisView);
}
