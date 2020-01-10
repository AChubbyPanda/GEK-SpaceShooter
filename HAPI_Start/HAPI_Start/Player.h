#ifndef Player_h //This is used when more than one header file is compiling the same header file.
#define Player_h //This is used when more than one header file is compiling the same header file.

#include "Entity.h"

#include <string>

class Player : public Entity
{
private:
	int score;
	int speed;

public:
	const void takeDamage() override;
	const int getScore();

	void playerMovement();
	void fireBullet(std::string entityName);
	void update() override final;
	ESide getSide() const override final;
	Player(std::string entityName, int playerHealth, int playerDamage);
	~Player();
};
#endif // Player_h //This is used when more than one header file is compiling the same header file.