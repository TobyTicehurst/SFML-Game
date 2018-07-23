#pragma once
#include <SFML/Graphics.hpp>
#include "GlobalVariables.h"
#include "Entity.h"

class FixedObject;
class Organelle;

enum class FixedObjectType { NONE, DEBUG, MEMBRANE };

class Tile : public Entity
{
public:
	Tile(sf::Vector2f& position, Renderable& renderable);

	void setFixedObjectType(FixedObjectType newType);
	FixedObjectType getFixedObjectType();

	unsigned int m_fixedObjectIndex;
	unsigned int m_organelleIndex;
private:
	FixedObjectType m_fixedObjectType;
};
