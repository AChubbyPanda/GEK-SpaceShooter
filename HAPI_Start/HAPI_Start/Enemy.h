#pragma once
#include<string>
#include "Entity.h"
#include "Path.h"
class Enemy : public Entity
{
private:
	float speed;
	int points;
	int pathType;
	int pathIndex;
	float pathStartTime;
	bool initialised;

public:
	const void takeDamage() override;
	void init();
	void update() override final;
	void move();
	int getSide() const override final;
	Enemy(std::string entityName, int enemyHealth, int enemyDamage, int enemyPoints);
	~Enemy();
};

