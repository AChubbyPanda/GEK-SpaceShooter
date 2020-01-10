#include "Bullet.h"

const void Bullet::takeDamage()
{
	int temp = m_Health - m_Damage;
	m_Health = temp;
}

void Bullet::update()
{
}

ESide Bullet::getSide() const
{
	return ESide();
}

//bool Bullet::IsDead()
//{
//	return true;
//}

Bullet::Bullet(std::string entityName, int bulletHealth, int bulletDamage)
	: Entity(entityName)
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