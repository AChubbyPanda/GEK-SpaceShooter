#pragma once
#include <HAPI_lib.h>
#include <vector>
#include"Vector2.h"
#include "Visualisation.h"

class Visualisation;

class World
{
private:
	static World* world;
	World();
	Visualisation* viz;

	std::vector<std::vector<Entity*>>entityVector;
	bool loadLevel();

public:
	~World();
	static World* getInstance();
	void run();
	void update();
	Entity* getEntity(int type);
};

