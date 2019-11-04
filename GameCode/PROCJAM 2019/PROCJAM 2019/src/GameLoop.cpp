#include "Gameloop.h"

GameLoop::GameLoop()
{
}

GameLoop::~GameLoop()
{
}

void GameLoop::m_RunGame()
{
	// Window init. 

	std::unique_ptr<GameWindow> l_ptrWindow;

	l_ptrWindow.reset(new GameWindow());

	l_ptrWindow->m_CreateWindow(800, 800, "PROCJAM 2019", 120);

	// Init Event Handler

	std::unique_ptr<EventHandler> l_ptrEventHandler; 

	l_ptrEventHandler.reset(new EventHandler());

	// Test Items. 

	Grid l_NewGrid; 

	l_NewGrid.m_CreateGrid(50, 40); 

	Player l_NewPlayer; 

	l_NewPlayer.m_CreateView(300, 300);
	

	// Setup

	while (l_ptrWindow->m_GetWindow().isOpen())
	{
		// Begin of loop 

		l_NewPlayer.m_Update(); 
		l_NewPlayer.m_SetCurrentWindow(l_ptrWindow->m_GetWindow());
		// Handle Events 

		l_ptrEventHandler->m_HandleEvents(l_ptrWindow->m_GetWindow());

		// End of Events

		// Clear Window 

		l_ptrWindow->m_ClearWindow();

		// Beginning of drawing

		l_NewGrid.m_DrawGrid(l_ptrWindow->m_GetWindow());

		l_NewPlayer.m_DrawPlayer(l_ptrWindow->m_GetWindow());

		// End of drawing

		l_ptrWindow->m_DisplayWindow();

		// Display Window 

		// End of loop 
	}
}
