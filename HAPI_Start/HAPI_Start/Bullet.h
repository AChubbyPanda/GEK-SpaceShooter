#pragma once
#include<string>
#include"Base.h"

class Bullet : public Base
{
private:

public:
	const void TakeDamage() override;
	bool IsDead() override;
	Bullet(const std::string b_Name, int b_PosX, int b_PosY, int b_Health, int b_Damage, const ESide b_Side);
	~Bullet();
};

