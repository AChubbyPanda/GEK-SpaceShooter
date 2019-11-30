#pragma once
#include<string>
#include<iostream>
#include <HAPI_lib.h>
#include "World.h"

using namespace HAPISPACE;

class MenuSystem
{
private:
	int Choice;

public:
	void MainMenu(int width, int height);
	void LauchGame();
	MenuSystem();
	~MenuSystem();
};

