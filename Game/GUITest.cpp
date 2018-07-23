#include "GUITest.h"



GUI::GUITest::GUITest(const sf::Texture& texture, const sf::Vector2f& position, const sf::Vector2f& size) :
	Widget(texture, position, size)
{
}

GUI::GUITest* GUI::GUITest::clone() { return new GUITest(*this); }

void GUI::GUITest::draw(sf::RenderTarget& target, sf::RenderStates states) const {}
