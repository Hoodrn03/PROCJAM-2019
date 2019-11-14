#include "..\inc\Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::m_CreateEnemy(sf::Vector2f enemyPos)
{
	m_EnemyBody.setSize(m_EnemySize);

	m_EnemyBody.setPosition(enemyPos);

	m_EnemyBody.setFillColor(sf::Color::White);
}
