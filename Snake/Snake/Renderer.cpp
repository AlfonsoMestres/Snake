#include <iostream>
#include <array>
#include "Renderer.h"

Renderer::Renderer() { }

Renderer::~Renderer() { }

void Renderer::PrintField(std::vector<std::vector<EntityType>> printField) {
	for (size_t j = 0; j < printField.size(); j++)
	{
		for (size_t i = 0; i < printField.size(); i++)
		{
			std::cout << '[' << (char)printField[i][j] << "]";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
