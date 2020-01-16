#include "Bullet.h"

const void Bullet::takeDamage()
{
	int temp = m_Health - m_Damage;
	m_Health = temp;
}

void Bullet::update()
{
}

int Bullet::getSide() const
{
	return side;
}

//bool Bullet::IsDead()
//{
//	return true;
//}

Bullet::Bullet(std::string entityName, int bulletHealth, int bulletDamage, int side)
	: Entity(entityName)
	, speed {5}
	, side { side }
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