#include "Button.h"

double TEXT_OFFSET{ 0.2f };	// Text is too low, not really sure what's causing it

namespace GUI {

// constructor
Button::Button(sf::Vector2f position, Renderable& renderable, const std::string& text, const sf::Font& font, std::function<void(void)> function) :
	Widget(position, renderable),
	m_text{ text, font },
	m_function{ function }
{
	m_text.setOrigin(m_text.getLocalBounds().width / 2, m_text.getLocalBounds().height / 2);
	m_text.setPosition(position.x, -1 * position.y - m_text.getCharacterSize() * TEXT_OFFSET);
	m_text.setFillColor(sf::Color::White);
}

// calls m_function if the button was clicked
void Button::input(const sf::Event& e, const sf::Vector2f mouseWorldPosition) {

	// if the button was clicked activate m_function
	if (clicked(mouseWorldPosition, e))
		activate();
}

// draws entity then text
void Button::draw(Renderer& renderer) const {

	renderer.draw(&m_entity);
	renderer.draw(&m_text);
}

// calls m_function
void Button::activate() const {
	m_function();
}

}