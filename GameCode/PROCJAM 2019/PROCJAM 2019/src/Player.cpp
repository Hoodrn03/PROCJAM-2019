#include "Player.h"

Player::Player()
{
	m_PlayerBody.setRadius(15.f);

	m_PlayerBody.setPosition(400, 400); 

	m_PlayerBody.setFillColor(sf::Color(150, 150, 150, 255));
}

Player::~Player()
{
}

void Player::m_DrawPlayer(sf::RenderWindow& window)
{
	window.draw(m_PlayerBody);
}

void Player::m_Update()
{
	// Move Player; 

	m_Movement();
}

void Player::m_Movement()
{
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
}
}

