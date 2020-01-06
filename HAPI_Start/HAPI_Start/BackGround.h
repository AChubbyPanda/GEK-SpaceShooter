#pragma once
#include "Entity.h"

class BackGround : public Entity
{
	const void TakeDamage() override final;
	void Update() override final;
	ESide GetSide() const override final;

public:
	BackGround(std::string EntityName);
	~BackGround();
};

