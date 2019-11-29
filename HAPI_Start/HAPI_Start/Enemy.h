#pragma once
#include<string>
#include"Base.h"

class Enemy : public Base
{
private:
	int m_Points;
public:
	const void TakeDamage() override;
	Enemy(const std::string e_Name, int e_PosX, int e_PosY, int e_Health, int e_Damage, const ESide e_Side, int e_Points);
	~Enemy();
};

