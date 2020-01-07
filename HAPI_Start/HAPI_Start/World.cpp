#include "World.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "BackGround.h"
#include "Visualisation.h"
#include <memory>

World::World()
	: m_Viz{nullptr}
	
{
}

World::~World()
{
	delete m_Viz;

	for (auto p : m_EntityVector)
	{
		delete p;
	};
}

bool World::LoadLevel()
{
	////Load all sprites
	if (!m_Viz->createSprite("PlayerGraphic", "Data\\PNG\\playerShip2_orange.png"))
	{
		HAPI.UserMessage("Image Path not found", "Error");
		return false;
	};
	
	if (!m_Viz->createSprite("BackGround", "Data\\purple.png"))
	{
		HAPI.UserMessage("Image Path not found", "Error");
		return false;
	};

	if (!m_Viz->createSprite("PlayerLaser", "Data\\PNG\\Lasers\\laserRed02.png"))
	{
		HAPI.UserMessage("Image Path not found", "Error");
		return false;
	};

	if (!m_Viz->createSprite("EnemyGraphicGreen", "Data\\PNG\\Enemies\\enemyGreen4.png"))
	{
		HAPI.UserMessage("Image Path not found", "Error");
		return false;
	};

	if (!m_Viz->createSprite("EnemyLaserGreen", "Data\\PNG\\Lasers\\laserGreen04.png"))
	{
		HAPI.UserMessage("Image Path not found", "Error");
		return false;
	};

	Player *newPlayer = new Player("PlayerGraphic", 20,1);
	m_EntityVector.push_back(newPlayer);

	newPlayer->SetPosition(Vector2(100,100));

	BackGround *newBackGround = new BackGround("BackGround");
	m_EntityVector.push_back(newBackGround);

	newBackGround->SetPosition(Vector2(0, 0));

	for (int i = 0; m_EntityVector.size() < 102; i++)
	{
		//need to look at the spawn location of the bullets
		Enemy* newEnemy = new Enemy("EnemyGraphicGreen",9,2,rand() % 100 + 25);
		m_EntityVector.push_back(newEnemy);
		i++;
	}

	for (int i = 0; m_EntityVector.size() < 202; i++)
	{
		//need to look at the spawn location of the bullets
		Bullet *playerBullet = new Bullet("PlayerLaser",1, 3);
		m_EntityVector.push_back(playerBullet);
		i++;
	}

	for (int i = 0; m_EntityVector.size() < 302; i++)
	{
		//need to look at the spawn location of the bullets
		Bullet* enemyBullet = new Bullet("EnemyLaserGreen", 1, 2);
		m_EntityVector.push_back(enemyBullet);
		i++;
	}

	return true;
}

void World::Update()
{
	m_Viz->vizUpdate();

	for (auto p : m_EntityVector)
	{
		p->Update();
	}

	for (auto p : m_EntityVector)
	{
		p->Render(*m_Viz);
	}
}

void World::Run()
{
	m_Viz = new Visualisation;

	if (!m_Viz->vizInitialise(720, 720))
	{
		return;
	}


	if (!LoadLevel())
	{
		return;
	}
}


