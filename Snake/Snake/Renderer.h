#pragma once

#include <list>
#include <vector>
#include "Entity.h"

class Renderer
{
public:
	Renderer();
	virtual ~Renderer();

	void PrintField(std::vector<std::vector<EntityType>> printField);

};

