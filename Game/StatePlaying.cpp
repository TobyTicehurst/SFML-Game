#include "StatePlaying.h"
#include <iostream>
#include "Game.h"


StatePlaying::StatePlaying(Game* const game) :
	StateBase(game),
	m_surface(game->getRenderables().get("Hex_1"))
{
	//m_pGame->getCamera().setZoom(10);
}

void StatePlaying::input(sf::Event evnt) {

	//m_mouseTile = Mappings::WorldToTile(m_pGame->getCamera().getMouseWorldPosition());
	//if (m_surface.getTile(m_mouseTile).m_organelle != nullptr)
		//std::cout << m_surface.getTile(m_mouseTile).m_organelle->m_numberOfMembranes << "\n";

	switch (evnt.type) {

	case sf::Event::KeyReleased:
		switch (evnt.key.code) {

		case sf::Keyboard::M:
			//std::cout << m_surface.getTile(m_mouseTile).m_organelle->m_numberOfMembranes << "\n";
			//std::cout << static_cast<int>(m_surface.getTile(m_mouseTile).getTileType()) << "\n";

			break;
		}
		break;

	case sf::Event::MouseButtonReleased:
		switch (evnt.mouseButton.button) {

		case sf::Mouse::Left:
			//m_surface.createMembrane(m_mouseTile);
			break;

		case sf::Mouse::Right:
			m_surface.deleteMembrane(m_mouseTile);
			break;
		}
		break;

	case sf::Event::MouseWheelMoved:
		//m_pGame->getCamera().zoomCamera(evnt.mouseWheel.delta);
		break;
	}
}

void StatePlaying::update() {
	//m_pGame->getCamera().updateCameraPosition();		// wasd	
}

void StatePlaying::draw(Renderer& renderer) {
	// draw surface
	m_surface.draw(renderer);
	//draw mouse tile
	//m_pGame->m_renderer.drawTile(static_cast<int>(TileType::MOUSE), Mappings::TileToWorld(m_mouseTile));

}
