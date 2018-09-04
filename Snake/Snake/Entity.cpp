#include "Entity.h"

Entity::Entity(EntityType type, int xpos, int ypos, Entity* parent = NULL) :
	type(type), xpos(xpos), ypos(ypos), parent(parent)
{
	type = ENTITY;

	if (parent != NULL)
		parent->container.push_back(this);

}

Entity::~Entity()
{
}

void Entity::Tick() {
}

void Entity::MoveToParent() {
	this->xpos = parent->xpos;
	this->ypos = parent->ypos;
}

void Entity::ChangeParentTo(Entity* new_parent)
{
	if (parent != NULL)
		parent->container.remove(this);

	parent = new_parent;

	if (parent != NULL)
		parent->container.push_back(this);
}