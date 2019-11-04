#include "EventHandler.h"

EventHandler::EventHandler()
{
}

EventHandler::~EventHandler()
{
}

void EventHandler::m_HandleEvents(sf::RenderWindow& window)
{
	sf::Event l_Event;

	while (window.pollEvent(l_Event))
	{
		
		// Handle Events

		switch (l_Event.type)
		{
			// Case Closed
		case sf::Event::Closed:

			window.close();

			break;

			// Default Case
		default:
			break;
		}

	}
}

