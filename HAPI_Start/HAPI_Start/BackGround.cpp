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

ESide BackGround::getSide() const
{
	return ESide::eSideNeutral;
}