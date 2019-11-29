#pragma once
#ifndef Player_h //This is used when more than one header file is compiling the same header file.
#define player_h //This is used when more than one header file is compiling the same header file.

#include<string>
#include"Base.h"
#include"Control.h"

class Player : public Base, public Control
{
private:
	int p_Score;

public:
	const void TakeDamage() override;
	bool IsDead() override;
	const int GetScore();
	void GetInPut();

	Player(const std::string p_Name, int p_PosX, int p_PosY, int p_Health, int p_Damage, const ESide p_Side);
	~Player();
};
#endif // Player_h //This is used when more than one header file is compiling the same header file.