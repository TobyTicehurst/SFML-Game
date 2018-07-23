#include "Widget.h"


namespace GUI {

Widget::Widget(sf::Vector2f& pos, Renderable& renderable) :
	m_entity{ pos, renderable }
{}

// true if mouse is inside the widget
bool Widget::mouseOver(const sf::Vector2f& mousePosition) const {
	return m_entity.contains(mousePosition);
}

// true if mouseOver and left mouse button was pressed
bool Widget::clicked(const sf::Vector2f& mousePosition, const sf::Event& e) const {

	return 
		mouseOver(mousePosition) && 
		e.type == sf::Event::MouseButtonReleased && 
		e.mouseButton.button == sf::Mouse::Left;
}

}