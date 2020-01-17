#pragma once
#include<string>
#include "Entity.h"
#include "Path.h"
class Enemy : public Entity
{
private:
	float speed = 1.0f;
	int points;
	int pathType = 0;
	int pathIndex = 0;
	float pathStartTime;
	bool initialised = false;

public:
	const void takeDamage() override;
	void init();
	void update() override final;
	void move();
	int getSide() const override final;
	Enemy(std::string entityName, int enemyHealth, int enemyDamage, int enemyPoints);
	~Enemy();
};

