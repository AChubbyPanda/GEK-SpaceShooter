#include "World.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "BackGround.h"
#include "Visualisation.h"
#include <memory>
#include "Entity.h"

World* World::world = NULL;

World::World()
	: viz{nullptr}
	, entityVector{ 5 }
{
	
}

World::~World()
{
	delete viz;

	//Deletes all stored data in the vector, of vectors stops memory leaks.
	for (size_t i = 0; i != entityVector.size(); i++)
	{
		for (size_t j = 0; j < entityVector [i].size(); j++)
		{
			delete entityVector[i][j];
		}
	}
}

World* World::getInstance()
{
	if (world == NULL)
	{
		world = new World();
	}
	return world;
}

bool World::loadLevel()
{
	////Load all sprites
	if (!viz->createSprite("PlayerGraphic", "Data\\PNG\\playerShip2_orange.png"))
	{
		HAPI.UserMessage("Image Path not found", "Error");
		return false;
	};
	
	if (!viz->createSprite("BackGround", "Data\\purple.png"))
	{
		HAPI.UserMessage("Image Path not found", "Error");
		return false;
	};

	if (!viz->createSprite("PlayerLaser", "Data\\PNG\\Lasers\\laserRed02.png"))
	{
		HAPI.UserMessage("Image Path not found", "Error");
		return false;
	};

	if (!viz->createSprite("EnemyGraphicGreen", "Data\\PNG\\Enemies\\enemyGreen4.png"))
	{
		HAPI.UserMessage("Image Path not found", "Error");
		return false;
	};

	if (!viz->createSprite("EnemyLaserGreen", "Data\\PNG\\Lasers\\laserGreen04.png"))
	{
		HAPI.UserMessage("Image Path not found", "Error");
		return false;
	};

	BackGround* newBackGround = new BackGround("BackGround");
	entityVector[(int)ESprites::ESpritesBackGround].push_back(newBackGround);
	newBackGround->setPosition(Vector2(0, 0));
	newBackGround->setAlive();
	
	Player *newPlayer = new Player("PlayerGraphic", 20,1);
	entityVector [(int)ESprites::ESpritesPlayerGraphic].push_back (newPlayer);
	newPlayer->setPosition(Vector2(100, 100));
	newPlayer->setAlive();
	const int k_numEnemy = 100;

	for (int i = 0; i < k_numEnemy; i++)
	{
		Enemy* newEnemy = new Enemy("EnemyGraphicGreen", 9, 2, rand() % 100 + 25);
		entityVector[(int)ESprites::ESpritesEnemyGraphicGreen].push_back(newEnemy);
	}
	
	const int k_numPlayerBullet = 100;

	for (int i = 0; i < k_numPlayerBullet; i++)
	{
		Bullet* playerBullet = new Bullet("PlayerLaser", 1, 3, (int)ESide::eSidePlayer);
		entityVector[(int)ESprites::ESpritesPlayerLaser].push_back(playerBullet);
	}

	const int k_numEnemyBullet = 100;

	for (int i = 0; i < k_numEnemyBullet; i++)
	{
		Bullet* enemyBullet = new Bullet("EnemyLaserGreen", 1, 2, (int)ESide::eSideEnemy);
		entityVector[(int)ESprites::ESpritesEnemyLaserGreen].push_back(enemyBullet);
	}

	return true;
}

void World::update()
{
	viz->vizUpdate();
	for (size_t i = 0; i != entityVector.size(); i++)
	{
		for (size_t j = 0; j < entityVector[i].size(); j++)
		{
			entityVector[i][j]->update();
		}
	}

	for (size_t i = 0; i != entityVector.size(); i++)
	{
		for (size_t j = 0; j < entityVector[i].size(); j++)
		{
			entityVector[i][j]->render(*viz);
		}
	}
}

void World::getPool()
{
	for (int i = (int)ESprites::ESpritesPlayerLaser; i != entityVector.size(); i++)
	{
	}
}

void World::run()
{
	viz = new Visualisation;

	if (!viz->vizInitialise(1080, 720))
	{
		return;
	}


	if (!loadLevel())
	{
		return;
	}
}
