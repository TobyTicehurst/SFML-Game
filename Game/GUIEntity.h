#pragma once
#include "Entity.h"
#include "SFML\Graphics.hpp"
#include "Renderable.h"


namespace GUI {

// entity that draws via the GUI rather than directly to the world (via a surface)
// a factor of PIXELS_PER_TILE difference in drawn position
class GUIEntity : public Entity {

public:

	// constructor
	GUIEntity(sf::Vector2f& position, Renderable& renderable);

	// override Entity::draw
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

}