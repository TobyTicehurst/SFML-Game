#pragma once
#include "SFML\Graphics.hpp"
#include "GlobalVariables.h"


namespace Mappings {
	sf::Vector2i WorldToTile(const sf::Vector2f& worldCoords);
	sf::Vector2f TileToWorld(const sf::Vector2i& tileCoords);
}

