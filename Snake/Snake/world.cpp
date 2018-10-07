#include <iostream>
#include <string>
#include <array>
#include "Entity.h"
#include "Renderer.h"
#include "world.h"

world::world() {
	tick_timer = clock();

	Entity* food = new Entity(FOOD, 2, 2, NULL);
	entities.push_back(food);

}

world::~world() { }

std::vector<std::vector<EntityType>>* world::InitField(EntityType entity, unsigned int fieldSize) {
	std::vector<EntityType> vec(fieldSize, entity);
	return { fieldSize, vec };
}

void world::SetWalls(std::vector<std::vector<EntityType>>& printField) {
	for (size_t j = 0; j < printField.size(); j++) {
		for (size_t i = 0; i < printField.size(); i++) {
			if (j == 0 || j == printField.size() - 1 || i == 0 || i == printField.size() - 1)
				printField[i][j] = WALL;
		}
	}
}

// If position are out of field bounds, player will be set in the middle of it.
void world::SetPlayer(std::vector<std::vector<EntityType>>& printField, int x, int y) {
	const int size = printField.size();
	if (x > 0 || x <= size || y > 0 || y <= size) {
		const int halfSize = std::round(size / 2);
		printField[halfSize][halfSize] = SNAKE;
	}
	else {
		printField[x][y] = SNAKE;
	}
}


bool world::Tick()
{
	bool ret = true;

	GameLoop();

	return ret;
}

void world::GameLoop()
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

void world::InitGame() {
	field = InitField(ENTITY, 11);
	SetWalls(field);
	SetPlayer(field, -1, -1);
}