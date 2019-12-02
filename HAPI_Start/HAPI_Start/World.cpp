#include "World.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include <memory>

bool World::Initialise()
{
	Visualisation::Get()->Initialise();
	m_Viz = std::make_shared< Visualisation >();

	//Load Level
	 m_Viz->CreateSprite("Data\\purple.png", "BackGround");
	 m_Viz->CreateSprite("Data\\PNG\\playerShip2_orange.png", "PlayerGraphic");
	 m_Viz->CreateSprite("Data\\PNG\\Lasers\\laserRed02.png", "PlayerLaser");
	 m_Viz->CreateSprite("Data\\PNG\\Enemies\\enemyGreen4.png", "EnemyGraphicGreen");
	 m_Viz->CreateSprite("Data\\PNG\\Lasers\\laserGreen04.png", "EnemyLaserGreen");

	
	std::shared_ptr<Entity> backGround = std::make_shared<Entity>("BackGround", 0, 0, 1, 0, ESide::eSideNeutral);
	//textureID = m_Entity.size() - 1;
	m_Entity.push_back(backGround);

	//Player* player = new Player ("PlayerGraphic",100,100,20,1, eSidePlayer);
	std::shared_ptr<Player> player = std::make_shared<Player>("PlayerGraphic", 100, 100, 20, 1, ESide::eSidePlayer);
	m_Entity.push_back(player);

	for (int i = 0; m_Entity.size() < 102; i++)
	{
		//need to look at the spawn location of the bullets
		std::shared_ptr<Bullet> playerBullet = std::make_shared<Bullet>("PlayerLaser", 0, 0, 1, 0, ESide::eSidePlayer);
		m_Entity.push_back(playerBullet);
		i++;
	}

	return true;
}

void World::run()
{
	while (HAPI.Update())
	{
		m_Viz->Draw(1, 100, 100);
	}
}
