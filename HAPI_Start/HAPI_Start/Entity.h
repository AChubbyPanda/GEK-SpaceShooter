#pragma once

#include <HAPI_lib.h>
#include <Vector>
#include "Visualisation.h"
#include "Player.h"

using namespace HAPISPACE;

class Entity
{
private:
	unsigned int textureID;
	std::vector <Entity*> m_Entity;

public:
	Entity(const std::string e_Name, int e_PosX, int e_PosY, int e_Health, int e_Damage, const ESide e_Side);
	~Entity();
};

