#pragma once
#include "Widget.h"
#include "SFML\Graphics.hpp"
#include <functional>
#include <string>

namespace GUI {

// Button is a widget that when clicked will activate a function it owns
class Button : public Widget {

public:

	// constructor
	Button(sf::Vector2f position, Renderable& renderable, const std::string& text, const sf::Font& font, std::function<void(void)> function);

	// tests if button was clicked
	void input(const sf::Event& e, const sf::Vector2f mouseWorldPosition) override;

	// adds the button to the draw list
	void draw(Renderer& renderer) const override;


private:

	// calls m_function
	void activate() const;

	// text displayed on the button
	sf::Text m_text;

	// function to be called when the button is activated
	std::function<void(void)> m_function = []() {};
};

}