#pragma once
#include "Window.h"
#include "Renderer.h"
#include "GUI.h"
#include "StateMachine.h"
#include "StateMainMenu.h"
#include "ResourceMap.h"
#include "RenderableMap.h"
#include "ptr.h"	// using ptr = std::unique_ptr<T>
#include "NonCopyable.h"
#include <iostream>

// Game is a high level class which facilitates the communication between other high level objects
// It also contains the main game loop (input, update, draw)
// Game should never be copied or moved or changed in any way after its creation
class Game : public NonCopyable {

public:

	// constructor
	Game();

	// main game loop
	void run() const;

	// getters

	const Window&				getWindow()			const { return *m_window; }
	StateMachine&				getState()			const { return *m_state; }
	GUI::GUI&					getGUI()			const { return *m_GUI; }
	ResourceMap<sf::Texture>&	getTextures()		const { return *m_textures; }
	ResourceMap<sf::Font>&		getFonts()			const { return *m_fonts; }
	RenderableMap&			getRenderables()	const { return *m_renderables; }

private:

	// handles sf::Events
	inline void input() const;

	// updates state
	inline void update() const;

	// handles drawing and rendering
	inline void draw() const;


	// window is an sf::RenderWindow
	// handles window and view events
	ptr <Window> m_window;

	// Master Renderer
	ptr <Renderer> m_renderer;

	// Game State
	ptr <StateMachine> m_state;

	// GUI manager
	ptr <GUI::GUI> m_GUI;

	// Texture storage
	ptr <ResourceMap<sf::Texture>> m_textures;

	// Font storage
	ptr <ResourceMap<sf::Font>> m_fonts;

	// Renderable storage
	ptr <RenderableMap> m_renderables;


	// loading screen

	inline void loadResources() const;
	inline void loadRenderables() const;

	// useful
	void printMousePosition() const;

};
