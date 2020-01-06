#pragma once
#include<string>
#include "Entity.h"

class Enemy : public Entity
{
private:
	int m_Points;
public:
	const void TakeDamage() override;
	void Update() override final;
	ESide GetSide() const override final;
	Enemy(std::string EntityName, int enemyHealth, int enemyDamage, int enemyPoints);
	//Enemy(std::string EntityName);
	~Enemy();
};

