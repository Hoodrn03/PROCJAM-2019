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

	m_ThisGrid->m_CreateGrid(30, 30);

	// Init Player

	m_ThisPlayer.reset(new Player());

	m_ThisPlayer->m_CreateView(800, 800);

	// m_ThisPlayer->m_SetPlayerStartingPos(m_ThisGrid->m_GetStartingPositionFromGrid());

	m_ThisPlayer->m_SetPlayerStartingPos(0, 0);
	m_ThisPlayer->m_SetWindowPtr(m_ptrWindow->m_GetWindow());

	// Init Enemies

	m_ThisEnemyManager.m_AddEnemies(sf::Vector2f(300, 300));

	m_ThisEnemyManager.m_AddEnemies(sf::Vector2f(150, 300));

	m_ThisEnemyManager.m_AddEnemies(sf::Vector2f(300, 200));

	// Test Items 

	// End of Setup

	std::thread l_First([this] { this->m_Update(); });

	while (m_ptrWindow->m_GetWindow().isOpen())
	{
		// Begin of loop 

		// Update Items

			// Update Player
		m_ThisPlayer->m_Update();
		m_ThisPlayer->m_SetCurrentWindow(m_ptrWindow->m_GetWindow());

			// Update Enemies
		m_ThisEnemyManager.m_MoveToPlayer(m_ThisPlayer->m_GetPlayerPosition());
		m_ThisEnemyManager.m_UpdateEnemies();
		m_ThisEnemyManager.m_EnemiesHit(m_ThisPlayer->m_GetAttackRect(), m_ThisPlayer->m_GetAttackPosition());
		
		m_ThisPlayer->m_IsHit(m_ThisEnemyManager.m_AttackPlayer(m_ThisPlayer->m_GetPlayerPosition()));

		// End of Update

		// Handle Events 

		l_ptrEventHandler->m_HandleEvents(m_ptrWindow->m_GetWindow());

		// End of Events

		// Clear Window 

		m_ptrWindow->m_ClearWindow(sf::Color::Blue);

		// Beginning of drawing

		m_ThisGrid->m_DrawGrid(m_ptrWindow->m_GetWindow(), m_ThisPlayer->m_GetView());

		m_ThisPlayer->m_DrawPlayer(m_ptrWindow->m_GetWindow());

		m_ThisEnemyManager.m_DrawEnemies(m_ptrWindow->m_GetWindow());
		// End of drawing

		m_ptrWindow->m_DisplayWindow();

		// Display Window 

		// End of frame removal of items.

		m_ThisEnemyManager.m_RemoveEnemies(); 

		// End of loop 
	}

	l_First.join();
}

/*! \fn Update : Used to split some of the other functionality into a second thread. */
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
			m_ThisPlayer->m_SetPlayerStartingPos(sf::Vector2f(0, 0));
		}
	}
}
