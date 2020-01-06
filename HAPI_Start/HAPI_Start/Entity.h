#ifndef Entity_h
#define Entity_h

#include <HAPI_lib.h>
#include <Vector>
#include "Rectangle.h"
#include "Vector2.h"
#include <string>
#include "LoadTexture.h"

enum class ESide
{
	eSidePlayer,
	eSideEnemy,
	eSideNeutral
};

class Visualisation;

class Entity : public LoadTexture

{
private:
	Rectangle m_TextureRect;
	
protected:
	int m_PosX;
	int m_PosY;

	unsigned int m_Health;
	unsigned int m_Damage;

	Vector2 m_Position;
	std::string m_EntityName;
	bool m_alive;

public:
	void SetPosition(Vector2 newPos);
	//void Render(const Rectangle& screenRect, BYTE screen, int posX, int posY);
	const virtual void TakeDamage() = 0;

	void Render(Visualisation& Viz);
	virtual void Update() = 0;
	virtual ESide GetSide() const = 0;

	//Entity(const std::string e_Name, int e_PosX, int e_PosY, int e_Health, int e_Damage, const ESide e_Side);
	Entity(std::string spriteName);
	virtual ~Entity();
};

#endif // Entity_h