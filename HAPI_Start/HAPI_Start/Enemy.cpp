#include "Enemy.h"

const void Enemy::takeDamage()
{
	int temp = m_Health - m_Damage;
	m_Health = temp;
}

void Enemy::update()
{
	// AI stuff
}

ESide Enemy::getSide() const
{
	return ESide::eSideEnemy;
}

Enemy::Enemy (std::string entityName, int enemyHealth, int enemyDamage, int enemyPoints)
	: Entity(entityName)
	, points{}
{
	m_Health = enemyHealth;
	m_Damage = enemyDamage;
	points = enemyPoints;
}

//Enemy::Enemy(std::string EntityName)
//	: Entity(EntityName)
//{
//}

Enemy::~Enemy()
{
}