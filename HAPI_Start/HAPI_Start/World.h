#pragma once
#include <HAPI_lib.h>
#include <vector>
#include"Vector2.h"
#include "Visualisation.h"

class Visualisation;

class World
{
private:
	Visualisation* m_Viz;

	std::vector<Entity*>m_EntityVector;
	bool LoadLevel();

public:
	World();
	~World();

	void Run();
	void Update();
};

