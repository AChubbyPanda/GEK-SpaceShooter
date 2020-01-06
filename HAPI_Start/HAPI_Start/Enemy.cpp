#include "Enemy.h"

const void Enemy::TakeDamage()
{
	int temp = m_Health - m_Damage;
	m_Health = temp;
}

void Enemy::Update()
{
	// AI stuff
}

ESide Enemy::GetSide() const
{
	return ESide::eSideEnemy;
}

Enemy::Enemy (std::string EntityName, int enemyHealth, int enemyDamage, int enemyPoints)
	: Entity(EntityName)
	, m_Points{}
{
	m_Health = enemyHealth;
	m_Damage = enemyDamage;
	m_Points = enemyPoints;
}

//Enemy::Enemy(std::string EntityName)
//	: Entity(EntityName)
//{
//}

Enemy::~Enemy()
{
}