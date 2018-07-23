#pragma once
#include <SFML\Graphics.hpp>
class Tile;

class FixedObject
{
public:
	FixedObject(const sf::Vector2i& position) :
		m_position(position)
	{ }
	sf::Vector2i m_position;
};
