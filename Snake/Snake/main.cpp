#include <iostream>
#include <string>
#include  "Renderer.h"

int main() {
	
	Renderer render;

	std::cout << "Welcome to Snake!" << std::endl;

	while (1) {
		render.InitGame();
	}

	system("pause");
	return 0;
}