#include "Renderer.h"


// adds to m_drawables
void Renderer::draw(const sf::Drawable* drawable) {
	m_drawables.push_back(drawable);
}

// draws to window then clears m_drawables
void Renderer::render(sf::RenderWindow& window) {

	// draw each of the drawables to the window
	for (auto& drawable : m_drawables) {

		// this will call drawable.draw(window, states)
		window.draw(*drawable);
	}

	// clear for the next tick
	m_drawables.clear();
}