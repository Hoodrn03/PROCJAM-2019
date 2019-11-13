#include "Gameloop.h"

GameLoop::GameLoop()
{
}

GameLoop::~GameLoop()
{
}

/*! \ fn RunGame : Used to begin the game loop*/
void GameLoop::m_RunGame()
{
	// begin Setup

	// Window init. 

	m_ptrWindow.reset(new GameWindow());

	m_ptrWindow->m_CreateWindow(800, 800, "PROCJAM 2019", 120);

	// Init Event Handler

	std::unique_ptr<EventHandler> l_ptrEventHandler; 

	l_ptrEventHandler.reset(new EventHandler());

	// Init Grid

	m_ThisGrid.reset(new Grid());

	m_ThisGrid->m_CreateGrid(15, 15);

	// Init Player

	m_ThisPlayer.reset(new Player());

	m_ThisPlayer->m_CreateView(200, 200);

	m_ThisPlayer->m_SetPlayerStartingPos(m_ThisGrid->m_GetBorderlineCenter());
	
	// Init Enemies

	// Test Items 

	Attack l_NewAttack; 

	// End of Setup

	std::thread l_First([this] { this->m_Update(); });

	while (m_ptrWindow->m_GetWindow().isOpen())
	{
		// Begin of loop 

		// Update Items

		m_ThisPlayer->m_Update();
		m_ThisPlayer->m_SetCurrentWindow(m_ptrWindow->m_GetWindow());

		// l_NewAttack.m_CreateAttackBody(m_ThisPlayer->m_GetPlayerPosition()); 

		// End of Update

		// Handle Events 

		l_ptrEventHandler->m_HandleEvents(m_ptrWindow->m_GetWindow());

		// End of Events

		// Clear Window 

		m_ptrWindow->m_ClearWindow(sf::Color::Blue);

		// Beginning of drawing

		m_ThisGrid->m_DrawGrid(m_ptrWindow->m_GetWindow(), m_ThisPlayer->m_GetView());

		m_ThisPlayer->m_DrawPlayer(m_ptrWindow->m_GetWindow());

		l_NewAttack.m_DrawAttackBody(m_ptrWindow->m_GetWindow());

		// End of drawing

		m_ptrWindow->m_DisplayWindow();

		// Display Window 

		// End of loop 
	}

	l_First.join();
}

void GameLoop::m_Update()
{
	while (m_ptrWindow->m_GetWindow().isOpen())
	{
		// std::cout << " Update " << std::endl;

		Cell* l_TempCell = &m_ThisGrid->m_FindCellWithPosition(m_ThisPlayer->m_GetPlayerPosition());

		m_ThisPlayer->m_CheckMovementDirectionOne(l_TempCell->m_GetCellBounds(), l_TempCell->m_IsTilePassable());

		l_TempCell = &m_ThisGrid->m_FindCellWithPosition(m_ThisPlayer->m_GetPlayerPosition() + m_ThisPlayer->m_GetPlayerSize());

		m_ThisPlayer->m_CheckMovementDirectionTwo(l_TempCell->m_GetCellBounds(), l_TempCell->m_IsTilePassable());

		m_ThisGrid->m_UpdateGrid();
		m_ThisGrid->m_CheckForCollision(m_ThisPlayer->m_GetPlayerPosition());

		if (m_ThisGrid->m_PlayerOutsideGrid() == true)
		{
			m_ThisPlayer->m_SetPlayerStartingPos(l_TempCell->m_GetCellPosition());
		}
	}
}
