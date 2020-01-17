#include "Bullet.h"

const void Bullet::takeDamage()
{
	int temp = m_Health - m_Damage;
	m_Health = temp;

	if (m_Health <= 0)
	{
		setDead();
	}
}

void Bullet::update()
{
	if (side = (int)ESprites::ESpritesPlayerLaser)
	{
		m_Position.x += speed;
	}

	/*if (side = (int)ESprites::ESpritesEnemyLaserGreen)
	{
		m_Position.x -= speed;
	}*/
}

int Bullet::getSide() const
{
	return side;
}

Bullet::Bullet(std::string entityName, int bulletHealth, int bulletDamage, int side)
	: Entity(entityName)
	, speed {5}
	, side { side }
{
	m_Health = bulletHealth;
	m_Damage = bulletDamage;
}

Bullet::~Bullet()
{
}