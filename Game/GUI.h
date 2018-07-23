#pragma once
#include "SFML\Graphics.hpp"
#include "Panel.h"
#include "Window.h" 
#include "Renderer.h"
#include "Bin.h"


namespace GUI {

// GUI owns a bin of panels, dealing with input, update and draw.
class GUI {

public:

	// constructor
	GUI(const Window& window);

	// destructor
	~GUI() {};

	// input, update and draw each panel

	void input(const sf::Event& e, const Window& window);
	void update();
	void draw(Renderer& renderer);

	// add a panel to m_panels
	template<class T, class... Args>
	T* add(Args&&... args) {
		return m_panels.add<T>( std::forward<Args>(args)... );
	}

	// adds a panel to m_deletedPanels to be later deleted in update()
	void remove(Panel* panel);

private:

	// panels to be drawn and updated
	Bin<Panel> m_panels;

	// panels to be deleted
	std::vector<Panel*> m_deletedPanels;
};

}