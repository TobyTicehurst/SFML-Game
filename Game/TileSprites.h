#pragma once
#include <SFML/Graphics.hpp>
#include "GlobalVariables.h"
#include <iostream>

class TileSprites
{
public:
	TileSprites();
	//sf::VertexArray hexagonOutline;
	//sf::Texture squaretiles;
	sf::ConvexShape Sprites[16];
	//void HexagonTileSprites::createHexagonSprites();
};

