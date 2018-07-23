/*

#include "Context.h"

Context::Context() :
	m_config()
{
	createWindow();
}

void Context::fullscreen() {
	m_config.fullscreen = !m_config.fullscreen;
	createWindow();
}

void Context::createWindow() {
	sf::ContextSettings settings(8, 2, 3);

	if (m_config.fullscreen) {
		window.create(sf::VideoMode::getDesktopMode(), "Game", sf::Style::Default, settings);
	}
	else {
		sf::VideoMode videoMode(m_config.windowSize.x, m_config.windowSize.y);
		window.create(videoMode, "Game", sf::Style::Default, settings);
	}
}

*/