#pragma once

#include <HAPI_lib.h>
#include <Vector>
#include "Visualisation.h"

using namespace HAPISPACE;

class Entity
{
private:
	unsigned int textureID;
	std::vector <Entity*> m_Entity;

public:

	Entity();
	~Entity();
};

