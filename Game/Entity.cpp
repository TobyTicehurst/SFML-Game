#include "Entity.h"
#include "GlobalVariables.h"

Entity::Entity(sf::Vector2f& position, Renderable& renderable) :
	m_position{ position },
	m_renderable{ renderable }
{}

// Reach here from Renderer.render
// target will be the window
void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const {

	// add position to the states
	states.transform.translate(m_position.x *  float(PIXELS_PER_TILE), -1 * m_position.y * float(PIXELS_PER_TILE));

	// pass drawing on to renderable which deals with textures
	m_renderable.draw(target, states);
}

// get entity position
sf::Vector2f Entity::getPosition() const {
	return m_position;
}

// get entity bounds
sf::Rect<float> Entity::getBounds() const {

	// local relative to origin
	sf::Rect<float> localBounds = m_renderable.getLocalBounds();

	return sf::Rect<float> {
		localBounds.left + m_position.x,
		localBounds.top + m_position.y,
		localBounds.width, 
		localBounds.height
	};
}

// test if a point is contained within the bounds of the object
bool Entity::contains(const sf::Vector2f point) const {
	return getBounds().contains(point);
}

// move the entity a distance
void Entity::translate(const sf::Vector2f distance) {
	m_position += distance;
}