#pragma once
#include "SFML\Graphics.hpp"
#include "Renderable.h"

class Entity : public sf::Drawable
{
public:
	Entity(sf::Vector2f& position, Renderable& renderable);

	// some entities also own entities and so can override this
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	// get entity position
	sf::Vector2f getPosition() const;

	// get entity bounds
	sf::Rect<float> getBounds() const;

	// test if a point is contained within the bounds of the object
	bool contains(const sf::Vector2f point) const;

	// move the entity a distance
	void translate(const sf::Vector2f distance);

protected:

	// Absolute position
	// world or GUI position
	sf::Vector2f m_position;

	// renderable
	Renderable& m_renderable;
	
};

