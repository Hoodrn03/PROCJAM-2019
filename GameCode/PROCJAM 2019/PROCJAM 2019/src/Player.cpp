#include "Player.h"

Player::Player()
{
	// Create Player's sprite.

	m_PlayerBody.setSize(sf::Vector2f(15.f, 15.f));

	m_PlayerBody.setPosition(400, 400); 

	m_PlayerBody.setFillColor(sf::Color(150, 150, 150, 255));

	// End of player creation. 

	m_AttackRadius.setRadius(50);

	m_AttackRadius.setOrigin(sf::Vector2f(m_AttackRadius.getPosition().x + m_AttackRadius.getGlobalBounds().width / 2, 
		m_AttackRadius.getPosition().y + m_AttackRadius.getGlobalBounds().height / 2));

	m_AttackRadius.setFillColor(sf::Color::Green);

}

Player::~Player()
{
}

/*! \fn DrawPlayer Used to draw the player sprite onto the game window
param one: The game window to draw onto.
*/
void Player::m_DrawPlayer(sf::RenderWindow& window)
{
	window.draw(m_AttackRadius); 

	window.draw(m_PlayerBody);

	m_clAttack.m_DrawAttackBody(window);
}

/*! \fn Update Used to update the player once each loop. */
void Player::m_Update()
{
	// Move Player; 

	m_Movement();

	m_Attack();
}

void Player::m_CheckMovementDirectionOne(sf::FloatRect currentCellBounds, bool passableTile)
{

	if (currentCellBounds.intersects(m_PlayerBody.getGlobalBounds()))
	{
		if (passableTile == false)
		{
			// Check left

			if (currentCellBounds.left < m_PlayerBody.getPosition().x)
			{
				m_bNoLeftMove = true; 

				// std::cout << "Touching A" << std::endl;
			}

			// Check up

			if (currentCellBounds.top < m_PlayerBody.getPosition().y)
			{
				m_bNoUpMove = true;

				// std::cout << "Touching W" << std::endl;
			}
		}
		else
		{
			m_bNoUpMove = false;
			m_bNoLeftMove = false;
		}
		
	}

}

void Player::m_CheckMovementDirectionTwo(sf::FloatRect currentCellBounds, bool passableTile)
{
	if (currentCellBounds.intersects(m_PlayerBody.getGlobalBounds()))
	{
		if (passableTile == false)
		{
			// Check right

			// std::cout << "cell bounds : " << currentCellBounds.left << " Player Bounds " << m_PlayerBody.getPosition().x + m_PlayerBody.getSize().x << std::endl;

			if (currentCellBounds.left > m_PlayerBody.getPosition().x + 5)
			{
				m_bNoRightMove = true;

				// td::cout << "Touching D" << std::endl;
			}

			// Check down

			if (currentCellBounds.top > m_PlayerBody.getPosition().y + 5)
			{
				m_bNoDownMove = true;

				// std::cout << "Touching S" << std::endl;
			}
		}
		else
		{
			m_bNoRightMove = false;
			m_bNoDownMove = false;
		}
	}
}

/*! \fn Movement Used to handle the movement of the player character. */
void Player::m_Movement()
{
	// Move Player. 

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && m_bNoUpMove == false)
	{
		m_MovementVector.y = -m_fSpeed;

		m_bMoveUp = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && m_bNoDownMove == false)
	{
		m_MovementVector.y = m_fSpeed;

		m_bMoveDown = true;
	}
	else
	{
		m_MovementVector.y = 0;

		m_bMoveUp = false;
		m_bMoveDown = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && m_bNoLeftMove == false)
	{
		m_MovementVector.x = -m_fSpeed;

		m_bMoveLeft = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && m_bNoRightMove == false)
	{
		m_MovementVector.x = m_fSpeed;

		m_bMoveRight = true;
	}
	else
	{
		m_MovementVector.x = 0;

		m_bMoveLeft = false;
		m_bMoveRight = false;
	}

	m_PlayerBody.move(m_MovementVector);
	m_AttackRadius.setPosition(sf::Vector2f(m_PlayerBody.getPosition().x + m_PlayerBody.getGlobalBounds().width / 2,
		m_PlayerBody.getPosition().y + m_PlayerBody.getGlobalBounds().height / 2));

	// End of moving player.



	// Move View

	m_MoveView(m_PlayerBody.getPosition()); 

	// End of moving view.
}

void Player::m_Attack()
{


	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{

		// Calculate mouse pos in world 

		sf::Vector2f l_MousePos = m_CurrentWindow->mapPixelToCoords(sf::Mouse::getPosition(*m_CurrentWindow));

		// Calculate angle 

		float l_fAngle;

		float l_fAngleInRads = std::atan2(l_MousePos.y - m_PlayerBody.getPosition().y, l_MousePos.x - m_PlayerBody.getPosition().x);

		l_fAngle = l_fAngleInRads * 180.f / PI;

		// std::cout << " Angle " << l_fAngle; 

		// Calculate position. 

		Vector l_EndVector = NormaliseVector(m_PlayerBody.getPosition().x, m_PlayerBody.getPosition().y, l_MousePos.x, l_MousePos.y); 

		sf::Vector2f l_AttackPos = sf::Vector2f(l_EndVector.x * 50, l_EndVector.y * 50);

		// Set Attack Position. 

		m_clAttack.m_CreateAttackBody(m_PlayerBody.getPosition() + l_AttackPos, l_fAngle + 90);

		// std::cout << "Slash : "  << l_dAngle << std::endl;
	}
	else
	{
		m_clAttack.m_DestroyAttackBody();
	}

}

void Player::m_SetPlayerStartingPos(sf::Vector2f newPos)
{
	m_PlayerBody.setPosition(newPos); 
}

void Player::m_SetPlayerStartingPos(float x, float y)
{
	m_PlayerBody.setPosition(x, y);
}

void Player::m_SetWindowPtr(sf::RenderWindow& window)
{
	m_CurrentWindow.reset(&window);
}

sf::Vector2f Player::m_GetPlayerPosition()
{
	// std::cout << "(" << m_PlayerBody.getPosition().x << ", " << m_PlayerBody.getPosition().y << ")" << std::endl;

	return m_PlayerBody.getPosition();
}

sf::Vector2f Player::m_GetPlayerSize()
{
	return m_PlayerBody.getSize();;
}


