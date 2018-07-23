#pragma once
#include "SFML\Graphics.hpp"
#include <vector>
#include "Entity.h"


// Renderer is the drawing interface between entities and the window
class Renderer {

public:

	// constructor
	Renderer() = default;

	// adds to m_drawables
	void draw(const sf::Drawable* drawable);

	// draws to window then clears m_drawables
	void render(sf::RenderWindow& window);

private:
	std::vector<const sf::Drawable*> m_drawables;
};

