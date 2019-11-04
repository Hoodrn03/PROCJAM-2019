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
	/*! \var The current event variable for the window, used to check the event type. */
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

