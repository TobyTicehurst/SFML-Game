#pragma once
#include "SFML\Graphics.hpp"

class Config		
{
public:
	Config();
	
	bool fullscreen;
	sf::Vector2u windowSize;

	// view
	int scrollSpeed;
	double minZoom;
	double maxZoom;


};

