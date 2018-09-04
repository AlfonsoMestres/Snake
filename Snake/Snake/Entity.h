#pragma once
#include <string>
#include <list>

enum EntityType {
	ENTITY = ' ',
	SNAKE = 'O',
	FOOD = 'W',
	WALL = 'X'
};

class Entity
{
public:
	Entity(EntityType type, int xpos, int ypos, Entity* parent);
	~Entity();

	void MoveToParent();
	void ChangeParentTo(Entity* new_parent);
	void Tick();


	int xpos, ypos;
	EntityType type;
	Entity* parent;
	std::list<Entity*> container;

};
