#pragma once
#include "Entity.h"

class BackGround : public Entity
{
	const void takeDamage() override final;
	void update() override final;
	ESide getSide() const override final;

public:
	BackGround(std::string entityName);
	~BackGround();
};

