#pragma once
#include<string>
#include "Entity.h"

class Enemy : public Entity
{
private:
	int points;
public:
	const void takeDamage() override;
	void update() override final;
	int getSide() const override final;
	Enemy(std::string entityName, int enemyHealth, int enemyDamage, int enemyPoints);
	~Enemy();
};

