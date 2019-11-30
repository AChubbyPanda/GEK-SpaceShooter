#include "World.h"

bool World::Initialise(int width, int height)
{
	m_Viz = std::make_shared< Visualisation >();

	//Load Level
	m_Viz->CreateSprite("Data\\purple.png", "BackGround");
	m_Viz->CreateSprite("Data\\PNG\\PlayerShip2_orange.png", "PlayerGraphic");
	m_Viz->CreateSprite("Data\\PNG\\Lasers\\laserRed02.png", "PlayerLaser");
	m_Viz->CreateSprite("Data\\PNG\\Enemies\\enemyGreen4.png", "EnemyGraphicGreen");
	m_Viz->CreateSprite("Data\\PNG\\Lasers\\laserGreen04.png", "EnemyLaserGreen");

	////////////////
	////////////////
	//Pushbacks having issues, unsure why
	Player* background = new Player("BackGround", 0, 0, 1, 0, SideNeutral);
	//m_Entity.push_back(background);

	Player* player = new Player ("PlayerGraphic",100,100,20,1, eSidePlayer);
	//m_Entity.push_back(player);

	for (int i = 0; m_Entity.size() < 101; i++)
	{
		Bullet* playerBullet = new Bullet("PlayerLaser", 0, 0, 1, 2, eSidePlayer);
		//m_Entity.push_back(playerBullet);
		i++;
	}
	
	return false;
}

void World::run()
{
	while (HAPI.Update())
	{
		m_Viz->Draw(1,100,100);
	}
}
