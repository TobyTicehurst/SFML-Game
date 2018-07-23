#include "Panel.h"

// TODO put these in a text file or as arguments with defaults
double BORDER_SPACING = 10.0f;
double WIDGET_SPACING = 5.0f;

namespace GUI {

// constructor
Panel::Panel(sf::Vector2f& position, Renderable& renderable, std::vector< Widget* >* widgets) :
	m_entity{position, renderable},
	m_widgets{ widgets },	
	m_borderSpacing{ BORDER_SPACING },
	m_widgetSpacing{ WIDGET_SPACING }
{}

Panel::~Panel() {

	for (auto& widget : *m_widgets)
		delete widget;

	delete m_widgets;
}

// deal with events
void Panel::input(const sf::Event& e, const sf::Vector2f mouseWorldPosition) {

	// TODO deal with window resize events

	// each widget deal with events
	for (auto& widget : *m_widgets)
		widget->input(e, mouseWorldPosition);
}

void Panel::draw(Renderer& renderer) const {

	// add to render list
	renderer.draw(&m_entity);

	// draw each widget
	for (auto& widget : *m_widgets)
		widget->draw(renderer);
}

}

