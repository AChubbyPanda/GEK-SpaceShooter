#pragma once
#include<string>
#include "Entity.h"
#include "Entity.h"

class Bullet : public Entity
{
private:
	int speed;
	int side;
public:
	const void takeDamage() override final;
	void update() override final;
	int getSide() const override final;
	Bullet(std::string entityName, int bulletHealth, int bulletDamage, int side);
	//Bullet(std::string EntityName);
	~Bullet();
};

