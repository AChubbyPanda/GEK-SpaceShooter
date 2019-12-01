#include "Entity.h"

Entity::Entity(const std::string e_Name, int e_PosX, int e_PosY, int e_Health, int e_Damage, const ESide e_Side)
:textureID{}
{
}

Entity::~Entity()
{
	//Deletes all stored data in the vector, stops memory leaks.
	for (size_t i = 0; i != m_Entity.size(); i++)
	{
		delete m_Entity[i];
	}
}
