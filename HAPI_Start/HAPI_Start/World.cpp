#include "World.h"

bool World::Initialise(int width, int height)
{
	m_Viz = std::make_shared< Visualisation >();

	m_Viz->CreateSprite("PlayerSprite.tga", "PlayerGraphic");

	Player* player = new Player ("PlayerGraphic",100,100,20,3, eSidePlayer);
	return false;
}

void World::run()
{
	while (HAPI.Update())
	{

	}
}
