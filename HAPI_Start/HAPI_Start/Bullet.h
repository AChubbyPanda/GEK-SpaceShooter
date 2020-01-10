#pragma once
#include<string>
#include "Entity.h"
#include "Entity.h"

class Bullet : public Entity
{
private:

public:
	const void takeDamage() override final;
	void update() override final;
	ESide getSide() const override final;
	Bullet(std::string entityName, int bulletHealth, int bulletDamage);
	//Bullet(std::string EntityName);
	~Bullet();
};

