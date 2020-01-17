#ifndef Player_h //This is used when more than one header file is compiling the same header file.
#define Player_h //This is used when more than one header file is compiling the same header file.

#include "Entity.h"
#include "World.h"

#include <string>

class Player : public Entity
{
private:
	int score;
	int speed;
	int lifes;
	int respawnHealth;
public:
	const void takeDamage() override;
	const int getScore();

	void playerMovement();
	void fireBullet(int x, int y);
	int getPositionX();
	int getPositionY();
	void update() override final;
	int getSide() const override final;
	Player(std::string entityName, int playerHealth, int playerDamage);
	~Player();
};
#endif // Player_h //This is used when more than one header file is compiling the same header file.