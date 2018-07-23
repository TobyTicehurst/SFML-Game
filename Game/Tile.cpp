#include "Tile.h"
#include <iostream>

Tile::Tile(sf::Vector2f& position, Renderable& renderable) :
	Entity(position, renderable),
	m_fixedObjectType (FixedObjectType::NONE),
	m_fixedObjectIndex (-1),
	m_organelleIndex (-1)
{}

void Tile::setFixedObjectType(FixedObjectType newType) {
	m_fixedObjectType = newType;
}

FixedObjectType Tile::getFixedObjectType() {
	return m_fixedObjectType;
}

