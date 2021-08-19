// PhysicsProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "PhysicsGame.h"

int main()
{
	PhysicsGame* game = new PhysicsGame();

	game->run("Physics Games", 1280, 720, false);

	delete game;

	return 0;
}
