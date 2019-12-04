#include "Grid.h"

Grid::Grid()
{
	Cell l_TempCell(sf::Vector2f(0, 0));

	std::deque<Cell> l_TempDeque; 

	l_TempDeque.push_back(l_TempCell);

	v_GridOfCells.push_back(l_TempDeque);

}

Grid::~Grid()
{
}

void Grid::m_CreateinitialGrid(int numberOfLoops)
{
	int l_iMinifyNumberOfLoops = numberOfLoops / 4; 

	for (int i = 0; i < l_iMinifyNumberOfLoops; i++)
	{
		m_AddCells(0);
		m_AddCells(1);
		m_AddCells(2);
		m_AddCells(3);
	}
}

void Grid::m_AddCells(int direction)
{
	// Add cells up. The first element of each deque. 
	if (direction == 0)
	{
		if (v_GridOfCells.size() > 0)
		{
			for (unsigned int i = 0; i < v_GridOfCells.size(); i++)
			{

				Cell l_TempCell(v_GridOfCells[i][0].m_AddCell(0));

				v_GridOfCells[i].push_front(l_TempCell);

			}
		}
	}
	// Add cells down. The last element of each deque.
	else if (direction == 1)
	{
		if (v_GridOfCells.size() > 0)
		{
			for (unsigned int i = 0; i < v_GridOfCells.size(); i++)
			{

				int l_iIndex = v_GridOfCells[i].size() - 1; 

				Cell l_TempCell(v_GridOfCells[i][l_iIndex].m_AddCell(1));

				v_GridOfCells[i].push_back(l_TempCell);

			}
		}
	}
	// Add cells left. The each element of the first deque. 
	else if (direction == 2)
	{
		if (v_GridOfCells.size() > 0)
		{
			std::deque<Cell> l_TempDeque; 

			for (unsigned int i = 0; i < v_GridOfCells[0].size(); i++)
			{

				Cell l_TempCell(v_GridOfCells[0][i].m_AddCell(2));

				l_TempDeque.push_back(l_TempCell);

			}

			v_GridOfCells.push_front(l_TempDeque);
		}
	}
	// Add cells right. The each element of the last deque. 
	else if (direction == 3)
	{
		if (v_GridOfCells.size() > 0)
		{
			std::deque<Cell> l_TempDeque;

			int l_iIndex = v_GridOfCells.size() - 1; 

			for (unsigned int i = 0; i < v_GridOfCells[0].size(); i++)
			{

				Cell l_TempCell(v_GridOfCells[l_iIndex][i].m_AddCell(3));

				l_TempDeque.push_back(l_TempCell);

			}

			v_GridOfCells.push_back(l_TempDeque);
		}
	}
	
}

void Grid::m_DrawGrid(sf::RenderWindow& window)
{
	if (v_GridOfCells.size() > 0)
	{
		for (unsigned int i = 0; i < v_GridOfCells.size(); i++)
		{
			for (unsigned int j = 0; j < v_GridOfCells[i].size(); j++)
			{
				v_GridOfCells[i][j].m_DrawCell(window);
			}
		}
	}
}

void Grid::m_DrawGrid(sf::RenderWindow& window, sf::View& viewRect)
{
	if (v_GridOfCells.size() > 0)
	{
		for (unsigned int i = 0; i < v_GridOfCells.size(); i++)
		{
			for (unsigned int j = 0; j < v_GridOfCells[i].size(); j++)
			{

				sf::Vector2f l_ViewPos = sf::Vector2f(viewRect.getCenter().x - viewRect.getSize().x / 2, viewRect.getCenter().y - viewRect.getSize().y / 2),
					l_ViewSize = sf::Vector2f(viewRect.getSize().x, viewRect.getSize().y);

				sf::Vector2f l_CellPos = v_GridOfCells[i][j].m_GetPosition(); 

				if (m_InsideBox(l_ViewPos.x, l_ViewPos.y, l_ViewSize.x, l_ViewSize.y, l_CellPos.x, l_CellPos.y))
				{
					v_GridOfCells[i][j].m_DrawCell(window); 
				}
			}
		}
	}
}
