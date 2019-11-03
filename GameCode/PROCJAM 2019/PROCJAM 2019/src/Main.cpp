
#include <SFML/Graphics.hpp>

#include "GameLoop.h"

int main()
{
	std::unique_ptr<GameLoop> l_ptrGameLoop;

	l_ptrGameLoop.reset(new GameLoop); 

	l_ptrGameLoop->m_RunGame(); 

	return 0;
}