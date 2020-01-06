#include "Entity.h"
#include "Base.h"
#include "Visualisation.h"
#include "LoadTexture.h"

//void Entity::Render(const Rectangle& screenRect, BYTE screen, int posX, int posY)
//{
//}

void Entity::SetPosition(Vector2 newPos)
{
	m_Position = newPos;
}

void Entity::Render(Visualisation& Viz)
{
	Viz.Draw(m_EntityName, (int)m_Position.x, (int)m_Position.y);
}

//Entity::Entity(const std::string e_Name, int e_PosX, int e_PosY, int e_Health, int e_Damage, const ESide e_Side)
//	: m_TexturePointer{nullptr}
//	, TexWidth{0}
//	, TexHeight{0}
//	, m_TextureRect{TexWidth, TexHeight}
//	, m_alive {true}
//{
//}

Entity::Entity(std::string EntityName) 
	: m_EntityName(EntityName)
	, m_TextureRect{ m_TexWidth ,m_TexHeight }
	, m_alive{ true }
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
