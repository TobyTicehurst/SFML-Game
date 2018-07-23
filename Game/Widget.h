#pragma once
#include "SFML\Graphics.hpp"
#include "GUIEntity.h"
#include "Renderer.h"


namespace GUI {

// Base class for GUI elements
class Widget {

public:

	// constructor
	Widget(sf::Vector2f& pos, Renderable& renderable);

	virtual void input(const sf::Event& e, const sf::Vector2f mouseWorldPosition) = 0;
	virtual void draw(Renderer& renderer) const = 0;

	// true if cursor is inside the widget
	bool mouseOver(const sf::Vector2f& mousePosition) const;

	// true if mouseOver is true and left mouse button was pressed
	bool clicked(const sf::Vector2f& mousePosition, const sf::Event& e) const;

protected:

	// entity contains position and texture via a renderable
	GUIEntity m_entity;

};

}