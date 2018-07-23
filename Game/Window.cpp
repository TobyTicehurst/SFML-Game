#include "Window.h"


// constructor
Window::Window() :
	sf::RenderWindow(),
	m_config(),
	m_fullscreen{ m_config.fullscreen },
	m_initialSize{ m_config.windowSize },
	m_nextView{ sf::Vector2f{ 0.0f, 0.0f },  sf::Vector2f{ m_config.windowSize } }
{
	createWindow();
}


// creates a new window with the correct settings
// called when initialising the window and when switching betweeen fullscreen and windowed mode
void Window::createWindow() {
	sf::ContextSettings settings(8, 2, 3);

	if (m_fullscreen) {
		create(sf::VideoMode::getDesktopMode(), "Game", sf::Style::Fullscreen, settings);
	}
	else {
		sf::VideoMode videoMode(m_initialSize.x, m_initialSize.y);
		create(videoMode, "Game", sf::Style::Default, settings);
	}
}


// deals with window events
void Window::input(sf::Event& e) {

	switch (e.type) {

	case sf::Event::Closed:
		close();
		break;

	case sf::Event::Resized:
		resize();
		break;

	case sf::Event::KeyPressed:
		switch (e.key.code) {

		case sf::Keyboard::Escape:
			close();
			break;

		case sf::Keyboard::Return:
			fullscreen();
			break;
		}
		break;
	}
}


// switches between fullsceen and windowed mode
// a new window is created each time
void Window::fullscreen() {
	m_fullscreen = !m_fullscreen;
	createWindow();
}


// called when the window is resized
// will ensure the aspect ratio of the window is couteracted to keep the image square
void Window::resize() {
	m_nextView.setSize(m_nextView.getSize().y * getAspectRatio(), m_nextView.getSize().y);
}


// window's aspect ratio
double Window::getAspectRatio() const {
	return double(getSize().x) / double(getSize().y);
}


// called before any rendering is done
// clears all pixels to black and then applies the view
void Window::prepare() {

	// clear the window to black
	clear(sf::Color::Black);

	// set the view
	setView(m_nextView); 
}


// move the view using wasd
void Window::moveView() {

	// camera scrolling
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		m_nextView.move(-1 * m_zoom * m_config.scrollSpeed, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		m_nextView.move(m_zoom * m_config.scrollSpeed, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		m_nextView.move(0.0f, -1 * m_zoom * m_config.scrollSpeed);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		m_nextView.move(0.0f, m_zoom * m_config.scrollSpeed);
}


// zoom in and out using the scroll wheel
// zoom is focused on the mouse
void Window::zoomView(int mouseWheelDelta) {

	// initial mouse position
	sf::Vector2f startMousePosition{ getMouseWorldPosition() };

	// change the zoom
	m_zoom -= mouseWheelDelta;

	// minimum and maximum zoom
	if (m_zoom < m_config.minZoom)	m_zoom = m_config.minZoom;
	if (m_zoom > m_config.maxZoom)	m_zoom = m_config.maxZoom;

	// change the view's size
	m_nextView.setSize(m_initialSize.x * m_zoom * getAspectRatio(), m_initialSize.y * m_zoom);

	// ensure the mouse position doesn't move
	m_nextView.move(startMousePosition.x - getMouseWorldPosition().x, startMousePosition.y - getMouseWorldPosition().y);
}


// world coordinates are window coordiates with y-axis inverted
sf::Vector2f Window::getMouseWorldPosition() const {
	sf::Vector2f position{ mapPixelToCoords(sf::Mouse::getPosition(*this), getView()) };
	return sf::Vector2f{ position.x, -1 * position.y };
}