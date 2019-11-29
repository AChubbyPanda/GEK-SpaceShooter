#include "Enemy.h"

const void Enemy::TakeDamage()
{
	int temp = m_Health - m_Damage;
	m_Health = temp;
}

Enemy::Enemy(const std::string e_Name, int e_PosX, int e_PosY, int e_Health, int e_Damage, const ESide e_Side, int e_Points)
	:m_Points{}
{
	m_Name = e_Name;
	m_PosX = e_PosX;
	m_PosY = e_PosY;
	m_Health = e_Health;
	m_Damage = e_Damage;
	m_Side = e_Side;
	m_Points = e_Points;
}

Enemy::~Enemy()
{
}