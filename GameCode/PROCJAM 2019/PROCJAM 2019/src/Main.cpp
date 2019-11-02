
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow l_Window(sf::VideoMode(800, 800), "This thing");

	// Setup

	while (l_Window.isOpen())
	{
		// Begin of loop 

		sf::Event l_Event;

		while(l_Window.pollEvent(l_Event))
		{
			// Handle Events

			if (l_Event.type == sf::Event::Closed)
			{
				l_Window.close();
			}


			// Clear Window 

			l_Window.clear();

			// Draw Here

			l_Window.display();

			// Display Window 

			// End of loop 

		}
	}

	return 0;
}