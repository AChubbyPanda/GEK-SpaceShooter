#include "MenuSystem.h"

void MenuSystem::MainMenu(int width, int height)
{
	do
	{
		std::cout << "1. Play Game" << std::endl;
		std::cout << "2. ScoreBoard" << std::endl;
		std::cout << "3. Quit" << std::endl;
		

		std::cin >> Choice;

		switch (Choice)
		{
			case 1:
				LauchGame();
				break;
			case 2:
				break;
			case 3:
				return;
		}
	} 
	while (Choice != 3);
}

void MenuSystem::LauchGame()
{
	World world;

	
}

MenuSystem::MenuSystem()
{
	
}

MenuSystem::~MenuSystem()
{
}



