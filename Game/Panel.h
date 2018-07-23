#pragma once
#include <vector>
#include "GUIEntity.h"
#include "Widget.h"
#include "Renderer.h"


namespace GUI {

// class for storing and updating widgets
class Panel {

public:

	// constructor
	Panel(sf::Vector2f& position, Renderable& renderable, std::vector< Widget* >* widgets);

	// destructor
	virtual ~Panel();

	void input(const sf::Event& e, const sf::Vector2f mouseWorldPosition);

	// render the panel and its widgets
	void draw(Renderer& renderer) const;

protected:

	// entity
	GUIEntity m_entity;

	// list of widgets
	std::vector< Widget* >* m_widgets;

	// spacing around the egde of the panel
	const double m_borderSpacing;

	// spacing between buttons for example
	const double m_widgetSpacing;
};

}