#pragma once
#include<string>
#include "Entity.h"
#include "Entity.h"

class Bullet : public Entity
{
private:

public:
	const void TakeDamage() override final;
	void Update() override final;
	ESide GetSide() const override final;
	//bool IsDead() override;
	Bullet(std::string EntityName, int bulletHealth, int bulletDamage);
	//Bullet(std::string EntityName);
	~Bullet();
};

