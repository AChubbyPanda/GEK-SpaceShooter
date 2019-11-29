#include "Bullet.h"

const void Bullet::TakeDamage()
{
	int temp = m_Health - m_Damage;
	m_Health = temp;
}

Bullet::Bullet(const std::string b_Name, int b_PosX, int b_PosY, int b_Health, int b_Damage, const ESide b_Side)
{
	m_Name = b_Name;
	m_PosX = b_PosX;
	m_PosY = b_PosY;
	m_Health = b_Health;
	m_Damage = b_Damage;
	m_Side = b_Side;
}

Bullet::~Bullet()
{
}