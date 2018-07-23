#include "GUI.h"


namespace GUI {
	
// constructor
GUI::GUI(const Window& window)
{}

void GUI::input(const sf::Event& e, const Window& window) {

	for (auto panel : m_panels)
		panel->input(e, window.getMouseWorldPosition());
}

void GUI::update() {

	// delete any panels which need to be deleted
	for (auto panel : m_deletedPanels) {
		m_panels.remove(panel);
	}

	m_deletedPanels.clear();
}

void GUI::draw(Renderer& renderer) {

	// draw every panel
	for (auto panel : m_panels)
		panel->draw(renderer);
}

// adds a panel to m_deletedPanels to be later deleted in update()
void GUI::remove(Panel* panel) {
	m_deletedPanels.push_back(panel);
}

}