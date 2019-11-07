#include "Player.h"

Player::Player()
{
	// Create Player's sprite.

	m_PlayerBody.setRadius(15.f);

	m_PlayerBody.setOrigin(m_PlayerBody.getPosition().x + (m_PlayerBody.getGlobalBounds().width / 2),
		m_PlayerBody.getPosition().y + (m_PlayerBody.getGlobalBounds().height / 2));

	m_PlayerBody.setPosition(400, 400); 

	m_PlayerBody.setFillColor(sf::Color(150, 150, 150, 255));

	// End of player creation. 
}

Player::~Player()
{
}

/*! \fn DrawPlayer Used to draw the player sprite onto the game window
param one: The game window to draw onto.
*/
void Player::m_DrawPlayer(sf::RenderWindow& window)
{
	window.draw(m_PlayerBody);
}

/*! \fn Update Used to update the player once each loop. */
void Player::m_Update()
{
	// Move Player; 

	m_Movement();
}

/*! \fn Movement Used to handle the movement of the player character. */
void Player::m_Movement()
{
	// Move Player. 

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_MovementVector.y = -m_fSpeed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_MovementVector.y = m_fSpeed;
	}
	else
	{
		m_MovementVector.y = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_MovementVector.x = -m_fSpeed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_MovementVector.x = m_fSpeed;
	}
	else
	{
		m_MovementVector.x = 0;
	}

	m_PlayerBody.move(m_MovementVector);

	// End of moving player.

	// Move View

	m_MoveView(m_PlayerBody.getPosition()); 

	// End of moving view.
}

sf::Vector2f Player::m_GetPlayerPosition()
{
	std::cout << "(" << m_PlayerBody.getPosition().x << ", " << m_PlayerBody.getPosition().y << ")" << std::endl;

	return m_PlayerBody.getPosition();
}


