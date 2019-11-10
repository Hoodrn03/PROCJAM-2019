#include "Grid.h"

Grid::Grid()
{
}

Grid::~Grid()
{
}


void Grid::m_CreateGrid(unsigned int rows, unsigned int columns)
{
	/*! \var Used to offset the tiles to prevent them being placed on top of themselves. */
	float l_fXoffset = 0, l_fYoffset = 0;

	/*! \var Used to get the current cell size. */
	Cell l_Cell;

	/*! \var Used to ensure the offset for the cells is correct. */
	float l_fCellWidth = l_Cell.m_CellSize.x, l_fCellHeight = l_Cell.m_CellSize.y;

	int l_NewId = 0; 

	for (unsigned int i = 0; i < rows; i++)
	{
		std::deque<Cell> l_TempGrid; 

		for (unsigned int j = 0; j < columns; j++)
		{
			Cell l_TempCell(sf::Vector2f(l_fXoffset, l_fYoffset));

			l_TempCell.l_iID = l_NewId; 

			l_NewId++;

			l_TempGrid.push_back(l_TempCell);

			l_fYoffset += l_fCellHeight;
		}

		v_Grid.push_back(l_TempGrid);

		l_fYoffset = 0;

		l_fXoffset += l_fCellWidth;
	}

	m_SetTopAndBottom();

}

void Grid::m_CreateGrid(unsigned int rows, unsigned int columns, sf::Vector2f startingPos)
{
	/*! \var Used to offset the tiles to prevent them being placed on top of themselves. */
	float l_fXoffset = 0 + startingPos.x, l_fYoffset = 0 + startingPos.y;

	/*! \var Used to get the current cell size. */
	Cell l_Cell;

	/*! \var Used to ensure the offset for the cells is correct. */
	float l_fCellWidth = l_Cell.m_CellSize.x, l_fCellHeight = l_Cell.m_CellSize.y;

	for (unsigned int i = 0; i < rows; i++)
	{
		std::deque<Cell> l_TempGrid;

		for (unsigned int j = 0; j < columns; j++)
		{
			Cell l_TempCell(sf::Vector2f(l_fXoffset, l_fYoffset));

			l_TempGrid.push_back(l_TempCell);

			l_fYoffset += l_fCellHeight;
		}

		v_Grid.push_back(l_TempGrid);

		l_fYoffset = 0;

		l_fXoffset += l_fCellWidth;
	}

	m_SetTopAndBottom();

}

void Grid::m_CreateBorderline()
{
	m_Borderline.setPosition(m_TopLeft);
	m_Borderline.setSize(m_BottomRight);

	m_Borderline.setFillColor(sf::Color::Green); 
}

void Grid::m_SetTopAndBottom()
{
	/*! \var Used to get the current cell size. */
	Cell l_Cell;

	/*! \var Used to ensure the offset for the cells is correct. */
	float l_fCellWidth = l_Cell.m_CellSize.x, l_fCellHeight = l_Cell.m_CellSize.y;

	m_TopLeft = v_Grid[3][3].m_GetCellPosition();

	int l_iShrinkX = (v_Grid.size() - 6), l_iShrinkY = (v_Grid[0].size() - 6);

	m_BottomRight = sf::Vector2f(l_iShrinkX * l_fCellWidth, l_iShrinkY * l_fCellHeight);

	m_CreateBorderline();
}

void Grid::m_UpdateGrid()
{
	if (m_iAddCellDirection == 1)
	{
		m_AddCellsUp();

		m_iAddCellDirection = 0; 
	}
	else if (m_iAddCellDirection == 2)
	{
		m_AddCellsDown();

		m_iAddCellDirection = 0;
	}
	else if (m_iAddCellDirection == 3)
	{
		m_AddCellsLeft();

		m_iAddCellDirection = 0;
	}
	else if (m_iAddCellDirection == 4)
	{
		m_AddCellsRight();

		m_iAddCellDirection = 0;
	}
	

}

void Grid::m_CheckForCollision(sf::Vector2f playerPos)
{
	int l_iResult; 

	// Top of Grid.

	l_iResult = m_ExitBox(m_Borderline.getPosition().x, m_Borderline.getPosition().y, m_Borderline.getGlobalBounds().width,
		m_Borderline.getGlobalBounds().height, playerPos.x, playerPos.y);

	if (l_iResult > 0)
	{
		m_iAddCellDirection = l_iResult;

		std::cout << "Outside " << l_iResult << std::endl;
	}

}

/*! \fn DrawGrid This will draw the grid into the game world.
param one: The main game window to draw the map.
*/
void Grid::m_DrawGrid(sf::RenderWindow& window)
{
	for (unsigned int i = 0; i < v_Grid.size(); i++)
	{
		for (unsigned int j = 0; j < v_Grid[i].size(); j++)
		{
			v_Grid[i][j].m_DrawCell(window);
		}
	}

	// window.draw(m_Borderline); 
}

void Grid::m_DrawGrid(sf::RenderWindow& window, sf::Vector2f upperBounds, sf::Vector2f lowerBounds)
{
	for (unsigned int i = 0; i < v_Grid.size(); i++)
	{
		for (unsigned int j = 0; j < v_Grid[i].size(); j++)
		{
			v_Grid[i][j].m_DrawCell(window, upperBounds, lowerBounds);
		}
	}

	// window.draw(m_Borderline);
}

void Grid::m_DrawGrid(sf::RenderWindow& window, sf::View &view)
{
	int l_iCellsDrawn = 0;

	for (unsigned int i = 0; i < v_Grid.size(); i++)
	{
		for (unsigned int j = 0; j < v_Grid[i].size(); j++)
		{
			v_Grid[i][j].m_DrawCell(window, view);
		}
	}

	// window.draw(m_Borderline);
}

void Grid::m_AddCellsUp()
{
	unsigned int l_iRowsToAdd, l_iCollumnsToAdd = 4; 

	l_iRowsToAdd = v_Grid.size(); 

	/*! \var Used to get the current cell size. */
	Cell l_Cell;

	/*! \var Used to ensure the offset for the cells is correct. */
	float l_fCellWidth = l_Cell.m_CellSize.x, l_fCellHeight = l_Cell.m_CellSize.y;

	float l_fStartingX, l_fStartingY, l_fYoffset;

	l_fStartingY = v_Grid[0][0].m_GetCellPosition().y;

	l_fYoffset = l_fStartingY;

	for (unsigned int i = 0; i < l_iRowsToAdd; i++)
	{
		l_fStartingX = v_Grid[i][0].m_GetCellPosition().x;

		for (unsigned int j = l_iCollumnsToAdd; j > 0; j--)
		{
			 l_fYoffset -= l_fCellHeight;

			 Cell l_TempCell(sf::Vector2f(l_fStartingX, l_fYoffset));

			 v_Grid[i].push_front(l_TempCell); 
		}

		l_fYoffset = l_fStartingY; 
	}
	
	m_SetTopAndBottom();

}

void Grid::m_AddCellsDown()
{
	unsigned int l_iRowsToAdd, l_iCollumnsToAdd = 4;

	l_iRowsToAdd = v_Grid.size();

	/*! \var Used to get the current cell size. */
	Cell l_Cell;

	/*! \var Used to ensure the offset for the cells is correct. */
	float l_fCellWidth = l_Cell.m_CellSize.x, l_fCellHeight = l_Cell.m_CellSize.y;

	float l_fStartingX, l_fStartingY, l_fYoffset;

	unsigned int l_iLastLineInGrid = v_Grid[0].size() - 1;

	l_fStartingY = v_Grid[0][l_iLastLineInGrid].m_GetCellPosition().y;

	l_fYoffset = l_fStartingY;

	for (unsigned int i = 0; i < l_iRowsToAdd; i++)
	{
		l_fStartingX = v_Grid[i][l_iLastLineInGrid].m_GetCellPosition().x;

		for (unsigned int j = l_iCollumnsToAdd; j > 0; j--)
		{
			l_fYoffset += l_fCellHeight;

			Cell l_TempCell(sf::Vector2f(l_fStartingX, l_fYoffset));

			v_Grid[i].push_back(l_TempCell);
		}

		l_fYoffset = l_fStartingY;
	}

	m_SetTopAndBottom();
}

void Grid::m_AddCellsLeft()
{
	unsigned int l_iRowsToAdd, l_iCollumnsToAdd = 4;

	l_iRowsToAdd = v_Grid[0].size();

	/*! \var Used to get the current cell size. */
	Cell l_Cell;

	/*! \var Used to ensure the offset for the cells is correct. */
	float l_fCellWidth = l_Cell.m_CellSize.x, l_fCellHeight = l_Cell.m_CellSize.y;

	float l_fStartingX, l_fStartingY;

	l_fStartingX = v_Grid[0][0].m_GetCellPosition().x;
	l_fStartingY = v_Grid[0][0].m_GetCellPosition().y;

	/*! \var Used to offset the tiles to prevent them being placed on top of themselves. */
	float l_fXoffset = l_fStartingX - l_fCellWidth, l_fYoffset = l_fStartingY;

	for (unsigned int i = 0; i < l_iCollumnsToAdd; i++)
	{
		std::deque<Cell> l_TempGrid;

		for (unsigned int j = 0; j < l_iRowsToAdd; j++)
		{
			Cell l_TempCell(sf::Vector2f(l_fXoffset, l_fYoffset));

			l_TempGrid.push_back(l_TempCell);

			l_fYoffset += l_fCellHeight;
		}

		v_Grid.push_front(l_TempGrid);

		l_fYoffset = 0;

		l_fXoffset -= l_fCellWidth;
	}

	m_SetTopAndBottom();

}

void Grid::m_AddCellsRight()
{
	unsigned int l_iRowsToAdd, l_iCollumnsToAdd = 4;

	l_iRowsToAdd = v_Grid[0].size();

	/*! \var Used to get the current cell size. */
	Cell l_Cell;

	/*! \var Used to ensure the offset for the cells is correct. */
	float l_fCellWidth = l_Cell.m_CellSize.x, l_fCellHeight = l_Cell.m_CellSize.y;

	float l_fStartingX, l_fStartingY;

	l_fStartingX = v_Grid[v_Grid.size() - 1][0].m_GetCellPosition().x;
	l_fStartingY = v_Grid[v_Grid.size() - 1][0].m_GetCellPosition().y;

	/*! \var Used to offset the tiles to prevent them being placed on top of themselves. */
	float l_fXoffset = l_fStartingX + l_fCellWidth, l_fYoffset = l_fStartingY;

	for (unsigned int i = 0; i < l_iCollumnsToAdd; i++)
	{
		std::deque<Cell> l_TempGrid;

		for (unsigned int j = 0; j < l_iRowsToAdd; j++)
		{
			Cell l_TempCell(sf::Vector2f(l_fXoffset, l_fYoffset));

			l_TempGrid.push_back(l_TempCell);

			l_fYoffset += l_fCellHeight;
		}

		v_Grid.push_back(l_TempGrid);

		l_fYoffset = 0;

		l_fXoffset += l_fCellWidth;
	}

	m_SetTopAndBottom();
}

sf::Vector2f Grid::m_GetBorderlineCenter()
{
	sf::Vector2f l_Size(m_Borderline.getGlobalBounds().width, m_Borderline.getGlobalBounds().height);

	return m_Borderline.getPosition() + (l_Size / 2.f);
}

gridPos Grid::m_FindCellGridPos(Cell* cellToCheck)
{
	gridPos l_CellCurrGridPos;

	for (unsigned int i = 0; i < v_Grid.size(); i++)
	{
		for (unsigned int j = 0; j < v_Grid[i].size(); j++)
		{
			if (cellToCheck->l_iID == v_Grid[i][j].l_iID)
			{
				l_CellCurrGridPos.x = i; 
				l_CellCurrGridPos.y = j; 

				return l_CellCurrGridPos;
			}
		}
	}
	return gridPos();
}

void Grid::m_CreateRoad()
{
	v_Grid[m_GererateInt(0, v_Grid.size())][m_GererateInt(0, v_Grid[0].size())].m_SetTile(Tile::road);

	for (int i = 0; i < (int)v_Grid.size(); i++)
	{
		for (int j = 0; j < (int)v_Grid[i].size(); j++)
		{
			bool l_bRoadTilePresent = false;

			// Check Road Up

			if (j - 1 > 0)
			{
				Tile l_CheckTile;

				l_CheckTile = v_Grid[i][j - 1].m_GetTile();

				if (l_CheckTile == Tile::road)
				{
					l_bRoadTilePresent = true;
				}
			}

			// Check Road Down

			if (j + 1 < v_Grid.size())
			{
				Tile l_CheckTile;

				l_CheckTile = v_Grid[i][j + 1].m_GetTile();

				if (l_CheckTile == Tile::road)
				{
					l_bRoadTilePresent = true;
				}
			}

			// Check Road Left 

			if (i - 1 > 0)
			{
				Tile l_CheckTile;

				l_CheckTile = v_Grid[i - 1][j].m_GetTile();

				if (l_CheckTile == Tile::road)
				{
					l_bRoadTilePresent = true;
				}
			}

			// Check Road Right

			if (i + 1 < v_Grid[i].size())
			{
				Tile l_CheckTile;

				l_CheckTile = v_Grid[i + 1][j].m_GetTile();

				if (l_CheckTile == Tile::road)
				{
					l_bRoadTilePresent = true;
				}
			}

			if (l_bRoadTilePresent)
			{
				// Create Road

				bool m_bHitEdge = false;

				Cell * l_FocusCell = &v_Grid[i][j];

				int l_iloopLimit = 0; 

				do
				{
					int l_iRoadDirection = m_GererateInt(1, 6);

					gridPos l_ThisPos = m_FindCellGridPos(l_FocusCell);

					switch (l_iRoadDirection)
					{
					case 1:
						if (l_ThisPos.y - 1 > 0)
						{
							l_FocusCell = &v_Grid[l_ThisPos.x][l_ThisPos.y - 1];	// Up

							l_FocusCell->m_SetTile(Tile::road);
						}
						else
						{
							m_bHitEdge = true;
						}

						break;

					case 2:
						if (l_ThisPos.y + 1 < v_Grid[i].size())
						{
							l_FocusCell = &v_Grid[l_ThisPos.x][l_ThisPos.y + 1];	// Down 

							l_FocusCell->m_SetTile(Tile::road);
						}
						else
						{
							m_bHitEdge = true;
						}
						break;

					case 3:
						if (l_ThisPos.x - 1 > 0)
						{
							l_FocusCell = &v_Grid[l_ThisPos.x - 1][l_ThisPos.y];	// Left

							l_FocusCell->m_SetTile(Tile::road);
						}
						else
						{
							m_bHitEdge = true;
						}
						break;

					default:
						if (l_ThisPos.x + 1 < v_Grid.size())
						{
							l_FocusCell = &v_Grid[l_ThisPos.x + 1][l_ThisPos.y];	// Right

							l_FocusCell->m_SetTile(Tile::road);
						}
						else
						{
							m_bHitEdge = true;
						}
						break;
					}

					l_iloopLimit++;

					if (l_iloopLimit >= 1000)
					{
						m_bHitEdge = true; 
					}

				} while (!m_bHitEdge);

				if (m_bHitEdge)
				{
					i = 100, j = 100;
					break;
				}
			}
		}
	}
}

void Grid::m_CreateMountain()
{
	int l_iBaseMountainChance = 25, l_iMountainAdjacentBonus = 15; 

	for (int i = 0; i < (int)v_Grid.size(); i++)
	{
		for (int j = 0; j < (int)v_Grid[i].size(); j++)
		{
			bool l_bMountainTilePresent = false;

			// Check mountain Up

			if (j - 1 > 0)
			{
				Tile l_CheckTile;

				l_CheckTile = v_Grid[i][j - 1].m_GetTile();

				if (l_CheckTile == Tile::mountain)
				{
					l_bMountainTilePresent = true;
				}
			}

			// Check mountain Down

			if (j + 1 < v_Grid.size())
			{
				Tile l_CheckTile;

				l_CheckTile = v_Grid[i][j + 1].m_GetTile();

				if (l_CheckTile == Tile::mountain)
				{
					l_bMountainTilePresent = true;
				}
			}

			// Check mountain Left 

			if (i - 1 > 0)
			{
				Tile l_CheckTile;

				l_CheckTile = v_Grid[i - 1][j].m_GetTile();

				if (l_CheckTile == Tile::mountain)
				{
					l_bMountainTilePresent = true;
				}
			}

			// Check mountain Right

			if (i + 1 < v_Grid[i].size())
			{
				Tile l_CheckTile;

				l_CheckTile = v_Grid[i + 1][j].m_GetTile();

				if (l_CheckTile == Tile::mountain)
				{
					l_bMountainTilePresent = true;
				}
			}

			if (v_Grid[i][j].m_GetTile() == Tile::null)
			{

				// Place Mountain Tile

				int l_iRand = m_GererateInt(1, 100);

				if (l_bMountainTilePresent)
				{
					if (l_iRand <= l_iBaseMountainChance + l_iMountainAdjacentBonus)
					{
						v_Grid[i][j].m_SetTile(Tile::mountain);
					}
				}
				else
				{
					if (l_iRand <= l_iBaseMountainChance)
					{
						v_Grid[i][j].m_SetTile(Tile::mountain);
					}
				}
			}

		}
	}
}

void Grid::m_CreateGrass()
{
	for (int i = 0; i < (int)v_Grid.size(); i++)
	{
		for (int j = 0; j < (int)v_Grid[i].size(); j++)
		{
			if (v_Grid[i][j].m_GetTile() == Tile::null)
			{
				v_Grid[i][j].m_SetTile(Tile::grass);
			}
		}
	}
}

