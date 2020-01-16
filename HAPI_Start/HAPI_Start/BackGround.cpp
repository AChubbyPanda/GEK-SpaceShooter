#include "BackGround.h"

BackGround::BackGround(std::string entityName)
	: Entity(entityName)
{
}

BackGround::~BackGround()
{
}

const void BackGround::takeDamage()
{
}

void BackGround::update()
{
}

int BackGround::getSide() const
{
	return (int)ESide::eSideNeutral;
}