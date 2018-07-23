#pragma once
#include "SFML\Graphics.hpp"

// only one of these exists per object type
// eg tiles have one renderable between them all but they have an entity each.

class Renderable : public sf::Drawable
{
public:
	//Renderable(sf::Texture& texture, sf::IntRect& textureRect, sf::Vector2f& origin = sf::Vector2f(0.0f, 0.0f));
	Renderable(const sf::Texture& texture);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	const sf::Vector2f getSize();
	sf::Rect<float> getLocalBounds();
	bool collision(sf::Vector2f localPoint);

private:
	const sf::Texture& m_texture;
	sf::Vertex m_vertices[4];

};

