#include "StateMainMenu.h"
#include "Game.h"
#include "StatePlaying.h"
#include <vector>
#include <string>


StateMainMenu::StateMainMenu(Game* const game) :
	StateBase(game),
	//m_mainMenu(game->getRenderables().get("Main_Menu_Panel"), game->getRenderables().get("Button"), game->getFonts().get("Arial"), game),
	m_background{ game->getTextures().get("Background") }
{
	GUI::MainMenu* test = game->getGUI().add<GUI::MainMenu>(game->getRenderables().get("Main_Menu_Panel"), game->getRenderables().get("Button"), game->getFonts().get("Arial"), game);
}

StateMainMenu::~StateMainMenu() {
	std::cout << "Called StateMainMenu Destructor\n";
}

void StateMainMenu::input(sf::Event evnt) {

	switch (evnt.type) {

	case sf::Event::KeyReleased:
		switch (evnt.key.code) {

		case sf::Keyboard::P:
			//m_pGame->changeState <StatePlaying>();
			break;
		}
		break;

	case sf::Event::MouseButtonReleased:
		switch (evnt.mouseButton.button) {

		case sf::Mouse::Left:
			//m_mainMenu.input(evnt, m_pGame->getMouseWorldPosition());
			break;
		}
		break;
	}

}

void StateMainMenu::update() {
//	m_mainMenu.update();

}

void StateMainMenu::draw(Renderer& renderer) {
	/*
	m_background.setRepeated(true);
	sf::Sprite background(m_background, sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(m_background.getSize().x * 3, m_background.getSize().y)));
	background.setOrigin(background.getLocalBounds().width / 2, background.getLocalBounds().height / 2);
	double scale{ double( m_pGame->getCamera().getView().getSize().y ) / double( m_background.getSize().y ) };
	background.setScale(scale, scale);
	renderer.draw(background);
	*/
	//m_mainMenu.draw(renderer);

}

