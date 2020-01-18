#include "Enemy.h"
#include "Path.h"
#include "World.h"

const void Enemy::takeDamage()
{
	int temp = m_Health - m_Damage;
	m_Health = temp;

	if (m_Health <= 0)
	{
		setDead();
	}
}
 
void Enemy::init()
{
	pathType = Path::getInstance()->randomPath();
	m_Position = Path::getInstance()->getPoint(pathType, 0);
	pathStartTime = HAPI.GetTime();
	setAlive();
	initialised = true;
}

void Enemy::update()
{
	if(initialised)
		move();
}

void Enemy::move()
{
	Vector2 startPoint = Path::getInstance()->getPoint(pathType, pathIndex);
	Vector2 endPoint = Path::getInstance()->getPoint(pathType, pathIndex +1);

	if (m_Position.x == endPoint.x && m_Position.y == endPoint.y)
	{
		pathIndex++;
		return;
	}

	//MoveCode goes here

	float distCovered = (HAPI.GetTime() - pathStartTime) * speed;
	float fractOfJourney = distCovered / 70; //70 because thats the gap of pixels between points.

	m_Position = Path::lerp(startPoint, endPoint, fractOfJourney);
}

int Enemy::getSide() const
{
	return (int)ESide::eSideEnemy;
}


Enemy::Enemy (std::string entityName, int enemyHealth, int enemyDamage, int enemyPoints)
	: Entity(entityName)
	, points{ 0 }
	, pathStartTime{ 0 }
	, speed{ 1.0f }
	, pathType{ 0 }
	, pathIndex{ 0 }
	, initialised{ false }
{
	m_Health = enemyHealth;
	m_Damage = enemyDamage;
	points = enemyPoints;
}

Enemy::~Enemy()
{
}