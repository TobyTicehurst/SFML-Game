#include "Renderable.h"
/*
Renderable::Renderable(sf::Texture& texture, sf::IntRect& textureRect, sf::Vector2f& size, sf::Vector2f& origin) :
	m_texture(texture),
	m_vertices{
	sf::Vertex(sf::Vector2f(0.0f,		0.0f)	- origin,	sf::Vector2f(textureRect.left,						textureRect.top)),
	sf::Vertex(sf::Vector2f(size.x,		0.0f)	- origin,	sf::Vector2f(textureRect.left + textureRect.width,	textureRect.top)),
	sf::Vertex(sf::Vector2f(size.x, 	size.y) - origin,	sf::Vector2f(textureRect.left + textureRect.width,	textureRect.top + textureRect.height)),
	sf::Vertex(sf::Vector2f(0.0f,		size.y) - origin,	sf::Vector2f(textureRect.left,						textureRect.top + textureRect.height))
	}
{}
*/

Renderable::Renderable(const sf::Texture& texture) :
	m_texture(texture),
	m_vertices{
	sf::Vertex(sf::Vector2f(-float(texture.getSize().x) / 2, -float(texture.getSize().y) / 2), sf::Vector2f(0.0f,				 0.0f)),
	sf::Vertex(sf::Vector2f(+float(texture.getSize().x) / 2, -float(texture.getSize().y) / 2), sf::Vector2f(texture.getSize().x, 0.0f)),
	sf::Vertex(sf::Vector2f(+float(texture.getSize().x) / 2, +float(texture.getSize().y) / 2), sf::Vector2f(texture.getSize().x, texture.getSize().y)),
	sf::Vertex(sf::Vector2f(-float(texture.getSize().x) / 2, +float(texture.getSize().y) / 2), sf::Vector2f(0.0f,				 texture.getSize().y))
	}
{}

// states contains position (Surface or Window) information 
// target will be the window
void Renderable::draw(sf::RenderTarget& target, sf::RenderStates states) const {

	// add texture to the states
	states.texture = &m_texture;

	// finally draw to the window // TODO, change to sf::trianglestrip etc?
	target.draw(&m_vertices[0], 4, sf::Quads, states);
}

const sf::Vector2f Renderable::getSize() {
	return sf::Vector2f{
		 m_vertices[1].position.x - m_vertices[0].position.x,
		 m_vertices[3].position.y - m_vertices[0].position.y
	};
}

// Returns 2 vector2, position of the top left and the size
sf::Rect<float> Renderable::getLocalBounds() {
	return sf::Rect<float> {
		m_vertices[0].position,
		getSize()
	};
}

// true if point is within the local bounds
// local point = absolute point - absolute entity position
bool Renderable::collision(sf::Vector2f localPoint) {
	return getLocalBounds().contains(localPoint);
}