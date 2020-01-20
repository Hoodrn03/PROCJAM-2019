#include "Grid.h"

Grid::Grid()
{
	for (unsigned int i = 0; i < v_GridOfCells.size(); i++)
	{
		v_GridOfCells[i].clear();
	}

	v_GridOfCells.clear();

	Cell l_TempCell(sf::Vector2f(0, 0));

	std::deque<Cell> l_TempDeque; 

	l_TempDeque.push_back(l_TempCell);

	v_GridOfCells.push_back(l_TempDeque);

	m_MapInnerBorder.setFillColor(sf::Color::Green); 

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

	m_UpdateInnerBorder();
}

void Grid::m_AddCells(int direction)
{
	if (v_GridOfCells.size() > 0)
	{
		// Add cells up. The first element of each deque. 
		if (direction == 0)
		{
			if (v_GridOfCells.size() > 0)
			{
				for (unsigned int i = 0; i < v_GridOfCells.size(); i++)
				{
					Cell l_TempCell(v_GridOfCells[i][0].m_AddCell(0));

					l_TempCell.m_SetId(m_iIdCounter);

					v_GridOfCells[i].push_front(l_TempCell);

					m_iIdCounter++;
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

					l_TempCell.m_SetId(m_iIdCounter);

					v_GridOfCells[i].push_back(l_TempCell);

					m_iIdCounter++;
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

					l_TempCell.m_SetId(m_iIdCounter);

					l_TempDeque.push_back(l_TempCell);

					m_iIdCounter++;
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

					l_TempCell.m_SetId(m_iIdCounter);

					l_TempDeque.push_back(l_TempCell);

					m_iIdCounter++;
				}

				v_GridOfCells.push_back(l_TempDeque);
			}
		}

		m_UpdateInnerBorder();
	}
}

void Grid::m_AddCells(int direction, int numberOfLoops)
{
	if (v_GridOfCells.size() > 0)
	{
		// Add cells up. The first element of each deque. 
		if (direction == 0)
		{
			for (int j = 0; j < numberOfLoops; j++)
			{
				if (v_GridOfCells.size() > 0)
				{
					for (unsigned int i = 0; i < v_GridOfCells.size(); i++)
					{
						Cell l_TempCell(v_GridOfCells[i][0].m_AddCell(0));

						l_TempCell.m_SetId(m_iIdCounter);

						// Set Tile 

						if (v_GridOfCells[i][1].m_GetTile() == tile::mountain)
						{
							int l_iPlaceMountain = m_GererateInt(0, 100);

							if (l_iPlaceMountain <= 25)
							{
								l_TempCell.m_SetTile(tile::mountain);
							}
							else
							{
								l_TempCell.m_SetTile(tile::grass);
							}
						}
						else
						{
							int l_iPlaceMountain = m_GererateInt(0, 100);

							if (l_iPlaceMountain <= 17)
							{
								l_TempCell.m_SetTile(tile::mountain);
							}
							else
							{
								l_TempCell.m_SetTile(tile::grass);
							}
						}

						v_GridOfCells[i].push_front(l_TempCell);

						m_iIdCounter++;
					}
				}
			}
		}
		// Add cells down. The last element of each deque.
		else if (direction == 1)
		{
			for (int j = 0; j < numberOfLoops; j++)
			{
				if (v_GridOfCells.size() > 0)
				{
					for (unsigned int i = 0; i < v_GridOfCells.size(); i++)
					{

						int l_iIndex = v_GridOfCells[i].size() - 1;

						Cell l_TempCell(v_GridOfCells[i][l_iIndex].m_AddCell(1));

						l_TempCell.m_SetId(m_iIdCounter);

						// Set Tile 

						if (v_GridOfCells[i][l_iIndex - 1].m_GetTile() == tile::mountain)
						{
							int l_iPlaceMountain = m_GererateInt(0, 100);

							if (l_iPlaceMountain <= 20)
							{
								l_TempCell.m_SetTile(tile::mountain);
							}
							else
							{
								l_TempCell.m_SetTile(tile::grass);
							}
						}
						else
						{
							int l_iPlaceMountain = m_GererateInt(0, 100);

							if (l_iPlaceMountain <= 17)
							{
								l_TempCell.m_SetTile(tile::mountain);
							}
							else
							{
								l_TempCell.m_SetTile(tile::grass);
							}
						}

						v_GridOfCells[i].push_back(l_TempCell);

						m_iIdCounter++;
					}
				}
			}
		}
		// Add cells left. The each element of the first deque. 
		else if (direction == 2)
		{
			for (int j = 0; j < numberOfLoops; j++)
			{
				if (v_GridOfCells.size() > 0)
				{
					std::deque<Cell> l_TempDeque;

					for (unsigned int i = 0; i < v_GridOfCells[0].size(); i++)
					{

						Cell l_TempCell(v_GridOfCells[0][i].m_AddCell(2));

						l_TempCell.m_SetId(m_iIdCounter);

						// Set Tile 

						if (v_GridOfCells[1][i].m_GetTile() == tile::mountain)
						{
							int l_iPlaceMountain = m_GererateInt(0, 100);

							if (l_iPlaceMountain <= 20)
							{
								l_TempCell.m_SetTile(tile::mountain);
							}
							else
							{
								l_TempCell.m_SetTile(tile::grass);
							}
						}
						else
						{
							int l_iPlaceMountain = m_GererateInt(0, 100);

							if (l_iPlaceMountain <= 17)
							{
								l_TempCell.m_SetTile(tile::mountain);
							}
							else
							{
								l_TempCell.m_SetTile(tile::grass);
							}
						}

						l_TempDeque.push_back(l_TempCell);

						m_iIdCounter++;
					}

					v_GridOfCells.push_front(l_TempDeque);
				}
			}
		}
		// Add cells right. The each element of the last deque. 
		else if (direction == 3)
		{
			for (int j = 0; j < numberOfLoops; j++)
			{
				if (v_GridOfCells.size() > 0)
				{
					std::deque<Cell> l_TempDeque;

					int l_iIndex = v_GridOfCells.size() - 1;

					for (unsigned int i = 0; i < v_GridOfCells[0].size(); i++)
					{

						// Create Cell

						Cell l_TempCell(v_GridOfCells[l_iIndex][i].m_AddCell(3));

						l_TempCell.m_SetId(m_iIdCounter);

						// Set Tile 

						if (v_GridOfCells[l_iIndex - 1][i].m_GetTile() == tile ::mountain)
						{
							int l_iPlaceMountain = m_GererateInt(0, 100);

							if (l_iPlaceMountain <= 20)
							{
								l_TempCell.m_SetTile(tile::mountain);
							}
							else
							{
								l_TempCell.m_SetTile(tile::grass);
							}
						}
						else
						{
							int l_iPlaceMountain = m_GererateInt(0, 100);

							if (l_iPlaceMountain <= 17)
							{
								l_TempCell.m_SetTile(tile::mountain);
							}
							else
							{
								l_TempCell.m_SetTile(tile::grass);
							}
						}

						// Add to map

						l_TempDeque.push_back(l_TempCell);

						m_iIdCounter++;
					}

					v_GridOfCells.push_back(l_TempDeque);
				}
			}
		}

		m_UpdateInnerBorder();
	}
}

Cell* Grid::m_CheckPlayerInCell(sf::Vector2f playerPos)
{
	if (v_GridOfCells.size() > 0)
	{
		for (unsigned int i = 0; i < v_GridOfCells.size(); i++)
		{
			for (unsigned int j = 0; j < v_GridOfCells[i].size(); j++)
			{
				if (v_GridOfCells[i][j].m_PointInsideCell(playerPos))
				{
					return &v_GridOfCells[i][j];
				}
			}
		}
	}
	return nullptr; 

}

void Grid::m_UpdateInnerBorder()
{
	if (v_GridOfCells.size() > 2)
	{
		sf::Vector2f l_NewPosition = v_GridOfCells[2][2].m_GetPosition();

		Cell l_TempCell; 

		int l_iIndexX = v_GridOfCells.size() - 3, l_iIndexY = v_GridOfCells[v_GridOfCells.size() - 1].size() - 3;

		float l_fWidth = l_iIndexX * l_TempCell.m_CellSize.x;
		float l_fHeight = l_iIndexY * l_TempCell.m_CellSize.y;

		m_MapInnerBorder.setPosition(l_NewPosition);
		m_MapInnerBorder.setSize(sf::Vector2f(l_fWidth, l_fHeight));
	}
}

void Grid::m_PlayerExitDirection(sf::Vector2f playerPos)
{
	int l_iPlayerExitDirection = m_ExitBox(m_MapInnerBorder.getPosition().x, m_MapInnerBorder.getPosition().y, m_MapInnerBorder.getGlobalBounds().width, m_MapInnerBorder.getGlobalBounds().height,
		playerPos.x, playerPos.y);

	if (l_iPlayerExitDirection >= 0)
	{
		m_AddCells(l_iPlayerExitDirection, 3); 
	}

}

sf::Vector2f Grid::m_GetStartingPoint()
{
	int l_iXpos, l_iYpos; 

	bool l_bEndGeneration = false; 

	sf::Vector2f l_ReturnVector; 

	do
	{

		l_iXpos = m_GererateInt(0, v_GridOfCells.size());
		l_iYpos = m_GererateInt(0, v_GridOfCells[l_iXpos].size());

		if (v_GridOfCells[l_iXpos][l_iYpos].m_GetTile() == tile::grass)
		{
			l_ReturnVector = v_GridOfCells[l_iXpos][l_iYpos].m_GetPosition();

			l_bEndGeneration = true; 
		}

	} while (l_bEndGeneration == false);

	return l_ReturnVector;
}

int Grid::m_EnemySpawnModifier()
{
	int l_ReturnValue = v_GridOfCells.size() + v_GridOfCells[0].size(); 

	l_ReturnValue = l_ReturnValue / 3; 

	return l_ReturnValue;
}

void Grid::m_AddGrassToMap()
{
	if (v_GridOfCells.size() > 0)
	{
		for (unsigned int i = 0; i < v_GridOfCells.size(); i++)
		{
			for (unsigned int j = 0; j < v_GridOfCells[i].size(); j++)
			{
				if (v_GridOfCells[i][j].m_GetTile() == tile::null)
				{
					v_GridOfCells[i][j].m_SetTile(tile::grass); 
				}
			}
		}
	}

	std::cout << "Added Grass To Map." << std::endl;

}

void Grid::m_AddMountainToMap()
{
	if (v_GridOfCells.size() > 0)
	{
		int l_iNumberOfInitialMountainTiles = 10;

		int l_iXpos, l_iYpos;

		for (int i = 0; i < l_iNumberOfInitialMountainTiles; i++)
		{
			l_iXpos = m_GererateInt(0, v_GridOfCells.size());
			l_iYpos = m_GererateInt(0, v_GridOfCells[0].size());

			if (v_GridOfCells[l_iXpos][l_iYpos].m_GetTile() == tile::null)
			{
				v_GridOfCells[l_iXpos][l_iYpos].m_SetTile(tile::mountain);
			}
		}

		int l_iDefaultPlaceChance = 15, l_iAdjacentBonus = 15, l_iCurrentBonus = 0;

		for (int i = 0; i < (int)v_GridOfCells.size(); i++)
		{
			for (int j = 0; j < (int)v_GridOfCells[i].size(); j++)
			{
				if (v_GridOfCells[i][j].m_GetTile() == tile::null)
				{
					// Check Up 

					if (j - 1 > 0)
					{
						if (v_GridOfCells[i][j - 1].m_GetTile() == tile::mountain)
						{
							l_iCurrentBonus += l_iAdjacentBonus; 
						}
					}

					// Check Down

					if (j + 1 < (int)v_GridOfCells[i].size())
					{
						if (v_GridOfCells[i][j + 1].m_GetTile() == tile::mountain)
						{
							l_iCurrentBonus += l_iAdjacentBonus;
						}
					}

					// Check Left

					if (i - 1 > 0)
					{
						if (v_GridOfCells[i - 1][j].m_GetTile() == tile::mountain)
						{
							l_iCurrentBonus += l_iAdjacentBonus;
						}
					}

					// Check Right

					if (i + 1 < (int)v_GridOfCells.size())
					{
						if (v_GridOfCells[i + 1][j].m_GetTile() == tile::mountain)
						{
							l_iCurrentBonus += l_iAdjacentBonus;
						}
					}

					int l_iPlaceMountain = m_GererateInt(0, 100); 

					if (l_iPlaceMountain <= l_iDefaultPlaceChance + l_iCurrentBonus)
					{
						v_GridOfCells[i][j].m_SetTile(tile::mountain); 
					}

				}

				l_iCurrentBonus = 0; 
			}
		}
	}

	std::cout << "Added Mountain To Map." << std::endl;
}

void Grid::m_SetCellTile(Cell& currentCell)
{
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

		// window.draw(m_MapInnerBorder);
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

				if (m_InsideBox(l_ViewPos.x - 50, l_ViewPos.y - 50, l_ViewSize.x + 50, l_ViewSize.y + 50, l_CellPos.x, l_CellPos.y))
				{
					v_GridOfCells[i][j].m_DrawCell(window); 
				}
			}
		}

		// window.draw(m_MapInnerBorder);
	}
}
