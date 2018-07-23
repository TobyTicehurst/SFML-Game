#include "GUIEntity.h"


namespace GUI {

// constructor
GUIEntity::GUIEntity(sf::Vector2f& position, Renderable& renderable) :
	Entity(position, renderable)
{}

// Reach here from Renderer.render
// target will be the window
void GUIEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const {

	// add position to the states
	states.transform.translate(m_position.x, -1 * m_position.y);

	// pass drawing on to renderable which deals with textures
	m_renderable.draw(target, states);
}

}