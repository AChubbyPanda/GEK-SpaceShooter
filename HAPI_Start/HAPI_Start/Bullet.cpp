#include "Bullet.h"

const void Bullet::TakeDamage()
{
	int temp = m_Health - m_Damage;
	m_Health = temp;
}

void Bullet::Update()
{
}

ESide Bullet::GetSide() const
{
	return ESide();
}

//bool Bullet::IsDead()
//{
//	return true;
//}

Bullet::Bullet(std::string EntityName, int bulletHealth, int bulletDamage)
	: Entity(EntityName)
{
	m_Health = bulletHealth;
	m_Damage = bulletDamage;
}

//Bullet::Bullet(std::string EntityName)
//	: Entity(EntityName)
//{
//}

Bullet::~Bullet()
{
}