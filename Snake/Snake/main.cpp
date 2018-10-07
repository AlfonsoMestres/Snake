#include <iostream>
#include <string>

#include "Renderer.h"
#include  "world.h"

int main() {
	
	world world;
	Renderer rend;

	std::cout << "Welcome to Snake!" << std::endl;
	world.InitGame();

	while (1) {
		rend.PrintField(world.field);
		world.Tick();
	}

	system("pause");
	return 0;
}