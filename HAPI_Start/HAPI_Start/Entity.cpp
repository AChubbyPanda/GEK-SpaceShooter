#include "Entity.h"
#include "Base.h"
#include "Visualisation.h"
#include "LoadTexture.h"

//void Entity::Render(const Rectangle& screenRect, BYTE screen, int posX, int posY)
//{
//}

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

//Entity::Entity(const std::string e_Name, int e_PosX, int e_PosY, int e_Health, int e_Damage, const ESide e_Side)
//	: m_TexturePointer{nullptr}
//	, TexWidth{0}
//	, TexHeight{0}
//	, m_TextureRect{TexWidth, TexHeight}
//	, m_alive {true}
//{
//}

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
	//Deletes all stored data in the vector, stops memory leaks.
	/*for (size_t i = 0; i != m_Entity.size(); i++)
	{
		delete m_Entity[i];
	}*/
}
