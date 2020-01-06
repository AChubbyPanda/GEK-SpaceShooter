#ifndef Player_h //This is used when more than one header file is compiling the same header file.
#define Player_h //This is used when more than one header file is compiling the same header file.

#include "Entity.h"
#include "Control.h"

#include <string>

class Player : public Entity, public Control
{
private:
	int p_Score;

public:
	const void TakeDamage() override;
	const int GetScore();
	void GetInPut();

	void Update() override final;
	ESide GetSide() const override final;

	Player(std::string EntityName,  int playerHealth, int playerDamage);
	~Player();
};
#endif // Player_h //This is used when more than one header file is compiling the same header file.