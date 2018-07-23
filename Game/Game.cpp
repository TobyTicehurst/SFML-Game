#include "Game.h"


Game::Game() :
	m_textures{		std::make_unique<ResourceMap<sf::Texture>>("Textures", "png") },
	m_fonts{		std::make_unique<ResourceMap<sf::Font>>("Fonts", "ttf") },
	m_renderables{	std::make_unique<RenderableMap>( m_textures->get("Error") ) },
	m_window{		std::make_unique<Window>() },
	m_renderer{		std::make_unique<Renderer>() },
	m_GUI{			std::make_unique<GUI::GUI>(*m_window) },
	m_state{		std::make_unique<StateMachine>() }	
{
	// loading screen
	loadResources();
	loadRenderables();

	// start in the main menu. Change to StatePlaying to start in game
	m_state->changeState<StateMainMenu>(this);
}

void Game::run() const {

	while (m_window->isOpen()) {

		// print the mouse position to the console window
		//printMousePosition();

		// handle events (Window, GUI, State)
		input();

		// update (State, GUI)
		update();

		// Draw the world (State, GUI, via Window)
		draw();
	}

}

// handle events
void Game::input() const {

	// Eventually need own events system
	sf::Event e;

	// collect events from the window
	while (m_window->pollEvent(e)) {
		
		// window inputs, changing size/close etc.
		m_window->input(e);

		// GUI inputs, clicking buttons/widgets
		// needs window for mouse position
		m_GUI->input(e, getWindow());

		// state inputs, 
		m_state->input(e);
	}
}

// update the state and GUI
void Game::update() const {

	// update tick, StatePlaying mostly
	m_state->update();

	// update GUI, delete panels
	m_GUI->update();
}

// handles drawing and rendering
void Game::draw() const {

	// prepare the window for drawing
	m_window->prepare();

	// have the state send all objects to the renderer
	m_state->draw(*m_renderer);

	m_GUI->draw(*m_renderer);

	// have the renderer draws these objects to the window (non const)
	m_renderer->render(*m_window);

	// window then displays these
	m_window->display();
}


void Game::loadResources() const {
	// load Textures
	m_textures->add("Background");
	m_textures->add("Debug");
	m_textures->add("Button");
	m_textures->add("Main_Menu_Panel");
	m_textures->add("Hex_1");
	// load Font
	m_fonts->add("Arial");
}


void Game::loadRenderables() const {

	m_renderables->add("Background", m_textures->get("Background"));
	m_renderables->add("Debug", m_textures->get("Debug"));
	m_renderables->add("Button", m_textures->get("Button"));
	m_renderables->add("Main_Menu_Panel", m_textures->get("Main_Menu_Panel"));
	m_renderables->add("Hex_1", m_textures->get("Hex_1"));
}


void Game::printMousePosition() const {
	sf::Vector2f mousePosition{ getWindow().getMouseWorldPosition() };

	std::cout << "Mouse Position: " << mousePosition.x << ", " << mousePosition.y << std::endl;
}