#pragma once
#include <HAPI_lib.h>
#include <vector>
#include "Visualisation.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Entity.h"

class Visualisation;
class Entity;

class World
{
private:
	//Gets the data needed from the create sprite.
	std::shared_ptr< Visualisation > m_Viz;
	std::vector <std::shared_ptr<Entity>> m_Entity;

public:
	bool Initialise(int width, int height);
	void run();
};

