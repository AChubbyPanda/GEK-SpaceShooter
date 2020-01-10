#include "World.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "BackGround.h"
#include "Visualisation.h"
#include <memory>

World::World()
	: viz{nullptr}
	
{
}

World::~World()
{
	delete viz;

	for (auto p : entityVector)
	{
		delete p;
	};
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
	entityVector.push_back(newBackGround);
	newBackGround->setPosition(Vector2(0, 0));
	newBackGround->setAlive();

	Player *newPlayer = new Player("PlayerGraphic", 20,1);
	entityVector.push_back(newPlayer);
	newPlayer->setPosition(Vector2(100, 100));
	newPlayer->setAlive();

	for (int i = 0; entityVector.size() < 102; i++)
	{
		Enemy* newEnemy = new Enemy("EnemyGraphicGreen",9,2,rand() % 100 + 25);
		entityVector.push_back(newEnemy);
		i++;
	}

	for (int i = 0; entityVector.size() < 202; i++)
	{
		//need to look at the spawn location of the bullets
		Bullet *playerBullet = new Bullet("PlayerLaser",1, 3);
		entityVector.push_back(playerBullet);
		i++;
	}

	for (int i = 0; entityVector.size() < 302; i++)
	{
		//need to look at the spawn location of the bullets
		Bullet* enemyBullet = new Bullet("EnemyLaserGreen", 1, 2);
		entityVector.push_back(enemyBullet);
		i++;
	}

	return true;
}

void World::update()
{
	viz->vizUpdate();

	for (auto p : entityVector)
	{
	p->update();
	}

	for (auto p : entityVector)
	{
		p->render(*viz);
	}
}

void World::run()
{
	viz = new Visualisation;

	if (!viz->vizInitialise(1536, 720))
	{
		return;
	}


	if (!loadLevel())
	{
		return;
	}
}


