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

	// Create Directional Radius

	m_UpRadius.setRadius(2);
	m_UpRadius.setFillColor(sf::Color::Black);
	m_UpRadius.setOrigin(m_UpRadius.getGlobalBounds().width / 2, m_UpRadius.getGlobalBounds().height / 2);

	m_DownRadius.setRadius(2);
	m_DownRadius.setFillColor(sf::Color::Black);
	m_DownRadius.setOrigin(m_DownRadius.getGlobalBounds().width / 2, m_DownRadius.getGlobalBounds().height / 2);

	m_LeftRadius.setRadius(2);
	m_LeftRadius.setFillColor(sf::Color::Black);
	m_LeftRadius.setOrigin(m_LeftRadius.getGlobalBounds().width / 2, m_LeftRadius.getGlobalBounds().height / 2);

	m_RightRadius.setRadius(2);
	m_RightRadius.setFillColor(sf::Color::Black);
	m_RightRadius.setOrigin(m_RightRadius.getGlobalBounds().width / 2, m_RightRadius.getGlobalBounds().height / 2);

}

Player::~Player()
{
	m_ptrCurrentWindow.release(); 
}

/*! \fn DrawPlayer Used to draw the player sprite onto the game window
param one: The game window to draw onto.
*/
void Player::m_DrawPlayer(sf::RenderWindow& window)
{
	// window.draw(m_AttackRadius); 

	window.draw(m_PlayerBody);

	m_clAttack.m_DrawAttackBody(window);

	/*
	window.draw(m_UpRadius);
	window.draw(m_DownRadius);
	window.draw(m_LeftRadius);
	window.draw(m_RightRadius);
	*/
}

/*! \fn Update Used to update the player once each loop. */
void Player::m_Update()
{
	// Move Player; 

	m_Movement();

	m_Attack();

	m_CheckForDeath();
}

void Player::m_CheckForDeath()
{
	if (m_fLife <= 0)
	{
		std::cout << "You Lose" << std::endl;
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

	// Update Variables

	sf::Vector2f l_PlayerSize(m_PlayerBody.getGlobalBounds().height, m_PlayerBody.getGlobalBounds().width);

	m_UpRadius.setPosition(m_GetPlayerCenter() - sf::Vector2f(0, m_PlayerBody.getGlobalBounds().height / 2));
	m_DownRadius.setPosition(m_GetPlayerCenter() + sf::Vector2f(0, m_PlayerBody.getGlobalBounds().height / 2));
	m_LeftRadius.setPosition(m_GetPlayerCenter() - sf::Vector2f(m_PlayerBody.getGlobalBounds().width / 2, 0));
	m_RightRadius.setPosition(m_GetPlayerCenter() + sf::Vector2f(m_PlayerBody.getGlobalBounds().width / 2, 0));

	// End of moving view.
}

void Player::m_Attack()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{

		// Calculate mouse pos in world 

		sf::Vector2f l_MousePos = m_ptrCurrentWindow->mapPixelToCoords(sf::Mouse::getPosition(*m_ptrCurrentWindow));

		// Calculate angle 

		float l_fAngle;

		float l_fAngleInRads = std::atan2(l_MousePos.y - m_PlayerBody.getPosition().y, l_MousePos.x - m_PlayerBody.getPosition().x);

		l_fAngle = l_fAngleInRads * 180.f / PI;

		// std::cout << " Angle " << l_fAngle; 

		// Calculate position. 

		Vector l_EndVector = NormaliseVector(m_PlayerBody.getPosition().x, m_PlayerBody.getPosition().y, l_MousePos.x, l_MousePos.y); 

		m_AttackPossition = sf::Vector2f(l_EndVector.x, l_EndVector.y);

		sf::Vector2f l_AttackPos = sf::Vector2f(m_AttackPossition.x * 50, m_AttackPossition.y * 50);

		// Set Attack Position. 

		m_clAttack.m_CreateAttackBody(m_PlayerBody.getPosition() + l_AttackPos, l_fAngle + 90);

		// std::cout << "Slash : "  << l_dAngle << std::endl;
	}
	else
	{
		m_clAttack.m_DestroyAttackBody();
	}

}

bool Player::m_HitEnemy(sf::Vector2f enemyPos)
{
	return m_clAttack.m_HitDetection(enemyPos);
}

void Player::m_IsHit(bool enemyAttack)
{
	if (m_ImunityTimer.getElapsedTime().asSeconds() >= m_fImunityLimiter)
	{
		if (enemyAttack)
		{
			std::cout << "Player Hit" << std::endl;
				 
			m_ImunityTimer.restart();

			m_fLife -= 25.f;
		}
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
	m_ptrCurrentWindow.reset(&window);
}

sf::Vector2f Player::m_GetPlayerPosition()
{
	// std::cout << "(" << m_PlayerBody.getPosition().x << ", " << m_PlayerBody.getPosition().y << ")" << std::endl;

	return m_PlayerBody.getPosition();
}

sf::Vector2f Player::m_GetPlayerCenter()
{
	sf::Vector2f l_ReturnVector;

	l_ReturnVector = m_PlayerBody.getPosition() + sf::Vector2f(m_PlayerBody.getGlobalBounds().width / 2, m_PlayerBody.getGlobalBounds().height / 2);

	return l_ReturnVector;
}

void Player::m_LimitMovement(int direction)
{
	switch (direction)
	{
		// Up 
	case 0: 
		m_bNoUpMove = true; 
		break;

		// Down 
	case 1:
		m_bNoDownMove = true;
		break;

		// Left
	case 2:
		m_bNoLeftMove = true;
		break;

		// Right
	case 3:
		m_bNoRightMove = true;
		break;

		// Reset Top 
	case 4:
		m_bNoUpMove = false;
		break;

		// Reset Bottom 
	case 5:
		m_bNoDownMove = false;
		break;

		// Reset Left
	case 6:
		m_bNoLeftMove = false;
		break;

		// Reset Right
	case 7:
		m_bNoRightMove = false;
		break;

	default:
		break;
	}
}

sf::Vector2f Player::m_GetPlayerSize()
{
	return m_PlayerBody.getSize();;
}

sf::Vector2f Player::m_GetAttackPosition()
{
	return m_AttackPossition;
}

sf::FloatRect Player::m_GetAttackRect()
{
	return m_clAttack.m_GetAttackRect();
}


