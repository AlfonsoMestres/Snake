#pragma once
#include <list>
#include <vector>
#include <time.h>

#include "Entity.h"

#define TICK_FREQUENCY 0.5f

class world
{
public:
	world();
	virtual ~world();

	bool Tick();
	void GameLoop();
	void InitGame();

	std::vector<std::vector<EntityType>>* field;
	std::vector<std::vector<EntityType>>* InitField(EntityType entity, unsigned int mazeSize);
	void SetWalls(std::vector<std::vector<EntityType>>& printField);
	void SetPlayer(std::vector<std::vector<EntityType>>& printField, int x, int y);

private:
	clock_t tick_timer;
	std::list<Entity*> entities;
};

