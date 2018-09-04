#include <iostream>
#include <string>
#include <array>
#include "Entity.h"
#include "Renderer.h"

Renderer::Renderer()
{
	tick_timer = clock();
}


Renderer::~Renderer()
{
}

std::vector<std::vector<EntityType>> Renderer::InitField(EntityType entity, unsigned int fieldSize) {
	std::vector<EntityType> vec(fieldSize, entity);
	return { fieldSize, vec };
}

std::vector<std::vector<EntityType>> Renderer::SetWalls(std::vector<std::vector<EntityType>> printField) {
	for (size_t j = 0; j < printField.size(); j++) {
		for (size_t i = 0; i < printField.size(); i++) {
			if (j == 0 || j == printField.size() - 1  || i == 0 || i == printField.size() - 1)
				printField[i][j] = WALL;
		}
	}

	return printField;
}

std::vector<std::vector<EntityType>> SetPlayer(std::vector<std::vector<EntityType>> printField) {
	return printField;
}

bool Renderer::Tick()
{
	bool ret = true;

	GameLoop();

	return ret;
}

void Renderer::GameLoop()
{
	clock_t now = clock();

	if ((now - tick_timer) / CLOCKS_PER_SEC > TICK_FREQUENCY)
	{
		//List ticking every element that needs to tick
		for (std::list<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
			(*it)->Tick();

		tick_timer = now;
	}
}

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

void Renderer::InitGame() {
	field = InitField(ENTITY,10);
	field = SetWalls(field);
	field = SetPlayer(field);
	PrintField(field);
	system("pause");
}