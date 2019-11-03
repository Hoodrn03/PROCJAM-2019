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

	l_ptrWindow->m_CreateWindow(800, 800, "PROCJAM 2019");

	// Test Items. 

	Grid l_NewGrid; 

	l_NewGrid.m_CreateGrid(50, 40); 

	// Setup

	while (l_ptrWindow->m_GetWindow().isOpen())
	{
		// Begin of loop 

		sf::Event l_Event;

		while (l_ptrWindow->m_GetWindow().pollEvent(l_Event))
		{
			// Handle Events

			if (l_Event.type == sf::Event::Closed)
			{
				l_ptrWindow->m_GetWindow().close();
			}


			// Clear Window 

			l_ptrWindow->m_ClearWindow();

			// Beginning of drawing

			l_NewGrid.m_DrawGrid(l_ptrWindow->m_GetWindow());

			// End of drawing

			l_ptrWindow->m_DisplayWindow();

			// Display Window 

			// End of loop 

		}
	}
}
