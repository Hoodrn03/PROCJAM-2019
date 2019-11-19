#include "..\inc\Enemy.h"

Enemy::Enemy()
{
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
}

void Enemy::m_DrawEnemy(sf::RenderWindow& window)
{

	window.draw(m_DetectionRadius);
	window.draw(m_EnemyBody); 
}

void Enemy::m_Update()
{
	m_Move();
}

void Enemy::m_Move()
{
	m_EnemyBody.move(m_MovementVector);

	m_DetectionRadius.setPosition(m_EnemyBody.getPosition());
}

void Enemy::m_MoveToPlayer(sf::Vector2f playerPos)
{
	float l_fDistToPlayer = m_Dist(playerPos.x, playerPos.y, m_EnemyBody.getPosition().x, m_EnemyBody.getPosition().y); 

	if (l_fDistToPlayer <= m_DetectionRadius.getRadius())
	{
		// std::cout << "Inside Radius" << std::endl;

		m_MovementVector = m_GetMoveDirection(m_EnemyBody.getPosition(), playerPos);
	}
	else
	{
		m_MovementVector = sf::Vector2f(0, 0); 
	}

}
