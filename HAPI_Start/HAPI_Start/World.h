#pragma once
#include <HAPI_lib.h>
#include <vector>
#include "Visualisation.h"

class Visualisation;

class World
{
private:
	//int width{ 720 },height{ 720 };
	//Gets the data needed from the create sprite.
	std::shared_ptr< Visualisation > m_Viz;
	std::vector <std::shared_ptr<Entity>> m_Entity;

public:
	bool Initialise();
	void run();
};

