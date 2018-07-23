#pragma once
#include "Widget.h"

namespace GUI {
	class GUITest : public Widget
	{
	public:
		GUITest(const sf::Texture& texture, const sf::Vector2f& position, const sf::Vector2f& size);

		virtual GUITest* clone();
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	};

}