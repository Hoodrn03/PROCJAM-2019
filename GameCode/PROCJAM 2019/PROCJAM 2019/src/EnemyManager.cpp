#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
}

EnemyManager::~EnemyManager()
{
}

void EnemyManager::m_AddEnemies(sf::Vector2f enemyPos)
{
	std::unique_ptr<Enemy> l_TempEnemy;

	l_TempEnemy.reset(new Enemy(enemyPos));

	v_EnemyList.push_back(*l_TempEnemy); 
}

void EnemyManager::m_UpdateEnemies()
{
	if (v_EnemyList.size() > 0)
	{
		for (unsigned int i = 0; i < v_EnemyList.size(); i++)
		{
			v_EnemyList[i].m_Update();
		}
	}
}

void EnemyManager::m_MoveToPlayer(sf::Vector2f playerPos)
{
	if (v_EnemyList.size() > 0)
	{
		for (unsigned int i = 0; i < v_EnemyList.size(); i++)
		{
			v_EnemyList[i].m_MoveToPlayer(playerPos); 
		}
	}
}

void EnemyManager::m_EnemiesHit(sf::FloatRect playerAttack, sf::Vector2f direction)
{
	if (v_EnemyList.size() > 0)
	{
		for (unsigned int i = 0; i < v_EnemyList.size(); i++)
		{
			if (playerAttack.contains(v_EnemyList[i].m_GetEnemyCenter()))
			{
				v_EnemyList[i].m_EnemyKnockBack(direction); 
			}
		}
	}
}

bool EnemyManager::m_AttackPlayer(sf::Vector2f playerPos)
{
	if (v_EnemyList.size() > 0)
	{
		for (unsigned int i = 0; i < v_EnemyList.size(); i++)
		{
			bool l_bValue = v_EnemyList[i].m_HitPlayer(playerPos);

			if (l_bValue == true)
			{
				return l_bValue;
			}
		}
	}

	return false;
}

void EnemyManager::m_RemoveEnemies()
{
	if (v_EnemyList.size() > 0)
	{
		for (unsigned int i = 0; i < v_EnemyList.size(); i++)
		{
			if (v_EnemyList[i].m_DestroyEnemy() == true)
			{
				v_EnemyList.erase(v_EnemyList.begin() + i);
			}
		}
	}
}

void EnemyManager::m_DrawEnemies(sf::RenderWindow& window)
{
	if (v_EnemyList.size() > 0)
	{
		for (unsigned int i = 0; i < v_EnemyList.size(); i++)
		{
			v_EnemyList[i].m_DrawEnemy(window);
		}
	}
}
