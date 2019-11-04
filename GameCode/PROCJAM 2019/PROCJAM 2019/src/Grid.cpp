#include "Grid.h"

Grid::Grid()
{
}

Grid::~Grid()
{
}

/*! \fn CreateGrid This will form a starting grid for the game.
param one: The number of rows for the grid.
param two: The number of columns for the grid.
*/
void Grid::m_CreateGrid(int rows, int columns)
{

	/*! \var Used to offset the tiles to prevent them being placed on top of themselves. */
	float l_fXoffset = 0, l_fYoffset = 0;

	for (unsigned int i = 0; i < rows; i++)
	{
		Cell l_TempCellOne((sf::Vector2f(l_fXoffset, l_fYoffset))); 

		v_Grid.push_back(l_TempCellOne);

		for (unsigned int j = 0; j < columns; j++)
		{
			Cell l_TempCellTwo(sf::Vector2f(l_fXoffset, l_fYoffset));

			v_Grid.push_back(l_TempCellTwo);

			l_fYoffset += l_TempCellTwo.m_CellSize.y;
		}

		l_fYoffset = 0;

		l_fXoffset += l_TempCellOne.m_CellSize.x;
	}

}

/*! \fn DrawGrid This will draw the grid into the game world.
param one: The main game window to draw the map.
*/
void Grid::m_DrawGrid(sf::RenderWindow& window)
{
	for (unsigned int i = 0; i < v_Grid.size(); i++)
	{
		v_Grid[i].m_DrawCell(window); 
	}
}
