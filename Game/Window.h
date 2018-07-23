#pragma once
#include "SFML\Graphics.hpp"
#include "Config.h"

class Window : public sf::RenderWindow
{
public:

	// constructor
	Window();

	// deals with events
	void input(sf::Event& e);
	
	// called before any rendering is done
	// clears all pixels to black and then applies the view
	void prepare();

	// world coordinates are window coordiates with y-axis inverted
	sf::Vector2f getMouseWorldPosition() const;

	// move the view using wasd
	void moveView();

	// zoom in and out using the scroll wheel
	// zoom is focused on the mouse
	void zoomView(int mouseWheelDelta);

private:

	// creates a new window with the correct settings
	// called when initialising the window and when switching betweeen fullscreen and windowed mode
	void createWindow();

	// switches between fullsceen and windowed mode
	// a new window is created each time
	void fullscreen();

	// called when the window is resized
	// will ensure the aspect ratio of the window is couteracted to keep the image square
	void resize();

	// window's aspect ratio
	double getAspectRatio() const;



	// config contains all settings
	Config m_config;

	// the view that will be applied once "prepare" is called
	sf::View m_nextView;

	// 1.0 is "normal" zoom
	double m_zoom;

	// true if the window is currently fullscreen
	bool m_fullscreen;

	// the initial/default window and view size
	// unless the window is fullscreen by default
	sf::Vector2u m_initialSize;
};

