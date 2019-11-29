#pragma once
#include <HAPI_lib.h>
#include <vector>
#include "Visualisation.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

class Visualisation;
class Entity;

class World
{
private:
	std::shared_ptr< Visualisation > m_Viz;

public:
	bool Initialise(int width, int height);
	void run();
};

