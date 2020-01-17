#include "Entity.h"
#include "Visualisation.h"
#include "LoadTexture.h"

void Entity::setPosition(Vector2 newPos)
{
	m_Position = newPos;
}

void Entity::render(Visualisation& Viz)
{
	if (m_Alive != false)
	{
		Viz.vizDraw(m_EntityName, (int)m_Position.x, (int)m_Position.y);
	}
}

void Entity::setAlive()
{
	m_Alive = true;
}

void Entity::setDead()
{
	m_Alive = false;
}

Entity::Entity(std::string entityName) 
	: m_EntityName(entityName)
	, textureRect{ m_PosX, m_PosY, texWidth, texHeight }
	, m_Alive{ false }
	, m_PosX{ 0 }
	, m_PosY{ 0 }
	, m_Health{ 0 }
	, m_Damage{ 0 }
{
}

Entity::~Entity()
{
	
}
