#pragma once
#include <HAPI_lib.h>
#include <vector>
#include"Vector2.h"
#include "Visualisation.h"

class Visualisation;

class World
{
private:
	Visualisation* viz;

	std::vector<Entity*>entityVector;
	bool loadLevel();

public:
	World();
	~World();

	void run();
	void update();
};

