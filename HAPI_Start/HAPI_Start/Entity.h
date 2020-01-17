#ifndef Entity_h
#define Entity_h

#include <HAPI_lib.h>
#include <Vector>
#include "Rectangle.h"
#include "Vector2.h"
#include <string>
#include "LoadTexture.h"

enum class ESprites
{
	ESpritesBackGround,
	ESpritesPlayerGraphic,
	ESpritesEnemyGraphicGreen,
	ESpritesPlayerLaser,
	ESpritesEnemyLaserGreen
};

enum class ESide
{
	eSidePlayer,
	eSideEnemy,
	eSideNeutral
};

class Visualisation;

class Entity : public Texture

{
private:
	Rectangle textureRect;
	bool m_Alive;

protected:
	int m_PosX;
	int m_PosY;
	
	unsigned int m_Health;
	unsigned int m_Damage;

	Vector2 m_Position;
	std::string m_EntityName;

public:
	void setPosition(Vector2 newPos);
	const virtual void takeDamage() = 0;
	void render(Visualisation& Viz);
	virtual void update() = 0;
	virtual int getSide() const = 0;
	void setAlive();
	void setDead();
	bool isAlive() { return m_Alive; };

	Entity(std::string spriteName);
	virtual ~Entity();
};

#endif // Entity_h