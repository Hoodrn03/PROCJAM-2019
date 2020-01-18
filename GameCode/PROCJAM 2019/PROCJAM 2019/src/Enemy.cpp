#include "..\inc\Enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(sf::Vector2f enemyPos)
{
	m_CreateEnemy(enemyPos); 
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

Enemy::~Enemy()
{
}

void Enemy::m_CreateEnemy(sf::Vector2f enemyPos)
{
	// Main enemy setup

	m_EnemyBody.setSize(m_EnemySize);

	m_EnemyBody.setPosition(enemyPos);

	m_EnemyBody.setFillColor(sf::Color::Black);

	// Detection Radius setup 

	m_DetectionRadius.setRadius(150);

	m_DetectionRadius.setOrigin(sf::Vector2f(m_DetectionRadius.getPosition().x + m_DetectionRadius.getGlobalBounds().width / 2,
		m_DetectionRadius.getPosition().y + m_DetectionRadius.getGlobalBounds().height / 2));

	m_DetectionRadius.setPosition(m_EnemyBody.getPosition());

	m_DetectionRadius.setOutlineThickness(5);

	m_DetectionRadius.setFillColor(sf::Color::Transparent);

	m_DetectionRadius.setOutlineColor(sf::Color::Magenta);

	// Setup Attack Radius 

	m_AttackRadius.setRadius(m_EnemyBody.getGlobalBounds().width + 10.f);

	m_AttackRadius.setOrigin(sf::Vector2f(m_AttackRadius.getPosition().x + m_AttackRadius.getGlobalBounds().width / 2,
		m_AttackRadius.getPosition().y + m_AttackRadius.getGlobalBounds().height / 2));

	m_AttackRadius.setPosition(m_GetEnemyCenter());

	m_AttackRadius.setFillColor(sf::Color::Green);
}

void Enemy::m_CreateEnemy(float x, float y)
{
	// Main enemy setup

	m_EnemyBody.setSize(m_EnemySize);

	m_EnemyBody.setPosition(x, y);

	m_EnemyBody.setFillColor(sf::Color::Black);

	// Detection Radius setup 

	m_DetectionRadius.setRadius(150);

	m_DetectionRadius.setOrigin(sf::Vector2f(m_DetectionRadius.getPosition().x + m_DetectionRadius.getGlobalBounds().width / 2,
		m_DetectionRadius.getPosition().y + m_DetectionRadius.getGlobalBounds().height / 2));

	m_DetectionRadius.setPosition(m_EnemyBody.getPosition());

	m_DetectionRadius.setOutlineThickness(5);

	m_DetectionRadius.setFillColor(sf::Color::Transparent);

	m_DetectionRadius.setOutlineColor(sf::Color::Magenta);

	// Setup Attack Radius 

	m_AttackRadius.setRadius(m_EnemyBody.getGlobalBounds().width + 10.f);

	m_AttackRadius.setOrigin(sf::Vector2f(m_AttackRadius.getPosition().x + m_AttackRadius.getGlobalBounds().width / 2,
		m_AttackRadius.getPosition().y + m_AttackRadius.getGlobalBounds().height / 2));

	m_AttackRadius.setPosition(m_GetEnemyCenter());

	m_AttackRadius.setFillColor(sf::Color::Green);

}

void Enemy::m_DrawEnemy(sf::RenderWindow& window)
{
	/*
	window.draw(m_DetectionRadius);

	window.draw(m_AttackRadius); 
	*/
	window.draw(m_EnemyBody); 

	/*
	window.draw(m_UpRadius);
	window.draw(m_DownRadius);
	window.draw(m_LeftRadius);
	window.draw(m_RightRadius);
	*/
}

void Enemy::m_Update()
{
	m_Move();
}

void Enemy::m_Move()
{
	m_EnemyBody.move(m_MovementVector);

	m_DetectionRadius.setPosition(m_GetEnemyCenter());
	m_AttackRadius.setPosition(m_GetEnemyCenter());
}


void Enemy::m_LimitMovement(int direction)
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

void Enemy::m_MoveToPlayer(sf::Vector2f playerPos)
{
	float l_fDistToPlayer = m_Dist(playerPos.x, playerPos.y, m_EnemyBody.getPosition().x, m_EnemyBody.getPosition().y); 

	if (l_fDistToPlayer <= m_DetectionRadius.getRadius())
	{
		// std::cout << "Inside Radius" << std::endl;

		m_bEnemyMoving = true; 

		m_MovementVector = m_GetMoveDirection(m_EnemyBody.getPosition(), playerPos);

		if (m_bNoUpMove == true)
		{
			if (m_MovementVector.y < 0)
			{
				m_MovementVector.y = 0;
			}
		}
		else if (m_bNoDownMove == true)
		{
			if (m_MovementVector.y > 0)
			{
				m_MovementVector.y = 0;
			}
		}

		if (m_bNoLeftMove == true)
		{
			if (m_MovementVector.x < 0)
			{
				m_MovementVector.x = 0;
			}
		}
		else if (m_bNoRightMove == true)
		{
			if (m_MovementVector.x > 0)
			{
				m_MovementVector.x = 0;
			}
		}
	}
	else
	{
		m_MovementVector = sf::Vector2f(0, 0); 

		m_bEnemyMoving = false; 
	}

	m_UpRadius.setPosition(m_GetEnemyCenter() - sf::Vector2f(0, m_EnemyBody.getGlobalBounds().height / 2));
	m_DownRadius.setPosition(m_GetEnemyCenter() + sf::Vector2f(0, m_EnemyBody.getGlobalBounds().height / 2));
	m_LeftRadius.setPosition(m_GetEnemyCenter() - sf::Vector2f(m_EnemyBody.getGlobalBounds().width / 2, 0));
	m_RightRadius.setPosition(m_GetEnemyCenter() + sf::Vector2f(m_EnemyBody.getGlobalBounds().width / 2, 0));
}

bool Enemy::m_HitPlayer(sf::Vector2f playerPos)
{
	float l_fDistToPlayer = m_Dist(playerPos.x, playerPos.y, m_EnemyBody.getPosition().x, m_EnemyBody.getPosition().y);

	if (l_fDistToPlayer <= m_AttackRadius.getRadius())
	{
		// std::cout << "Inside Radius" << std::endl;

		return true;
	}
	else
	{
		return false;
	}
}

sf::Vector2f Enemy::m_GetEnemyCenter()
{
	return sf::Vector2f(m_EnemyBody.getPosition().x + m_EnemyBody.getGlobalBounds().width / 2, 
		m_EnemyBody.getPosition().y + m_EnemyBody.getGlobalBounds().height / 2);
}

void Enemy::m_EnemyKnockBack(sf::Vector2f direction)
{
	if (m_ImunityTimer.getElapsedTime().asSeconds() >= m_fDamageImunity)
	{
		m_ImunityTimer.restart(); 

		float l_fSpeed = m_DetectionRadius.getRadius() / 2;

		m_EnemyBody.move(direction * l_fSpeed);

		m_fHealth -= 25; 
	}
}

bool Enemy::m_DestroyEnemy()
{
	if (m_fHealth <= 0)
	{
		return true;
	}

	return false; 
}
