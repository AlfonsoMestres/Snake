#pragma once

#include <list>
#include <vector>
#include <time.h>

#include "Entity.h"

#define TICK_FREQUENCY 0.5f

class Entity;

class Renderer
{
public:
	Renderer();
	~Renderer();

	bool Tick();
	void GameLoop();
	void InitGame();
	void PrintField(std::vector<std::vector<EntityType>> printField);
	std::vector<std::vector<EntityType>> InitField(EntityType entity, unsigned int mazeSize);
	std::vector<std::vector<EntityType>> SetWalls(std::vector<std::vector<EntityType>> printField);
	std::vector<std::vector<EntityType>> SetPlayer(std::vector<std::vector<EntityType>> printField);

	std::vector<std::vector<EntityType>> field;

private:
	clock_t tick_timer;
	std::list<Entity*> entities;

};

