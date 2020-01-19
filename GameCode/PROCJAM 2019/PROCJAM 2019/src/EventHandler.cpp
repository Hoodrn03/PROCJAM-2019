#include "EventHandler.h"

EventHandler::EventHandler()
{
}

EventHandler::~EventHandler()
{
}

/*! \fn HandleEvents This will handle the main events within the game which cannot be handled elsewhere.
param one: The game window in which to poll the events.
*/
void EventHandler::m_HandleEvents(sf::RenderWindow& window)
{

	while (window.pollEvent(m_Event))
	{
		
		// Handle Events

		switch (m_Event.type)
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

sf::Event EventHandler::m_GetEvent()
{
	return m_Event;
}

