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
}

void Grid::m_UpdateGrid()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_AddCellsRight(); 
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
}

void Grid::m_AddCellsUp()
{
	unsigned int l_iRowsToAdd, l_iCollumnsToAdd = 2; 

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

}

void Grid::m_AddCellsDown()
{
	unsigned int l_iRowsToAdd, l_iCollumnsToAdd = 2;

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

}

void Grid::m_AddCellsLeft()
{
	unsigned int l_iRowsToAdd, l_iCollumnsToAdd = 2;

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
}

void Grid::m_AddCellsRight()
{
	unsigned int l_iRowsToAdd, l_iCollumnsToAdd = 2;

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
}
