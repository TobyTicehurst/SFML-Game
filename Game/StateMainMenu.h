#pragma once
#include "StateBase.h"
#include "MainMenu.h"

class StateMainMenu : public StateBase
{

public:
	StateMainMenu(Game* const game);
	~StateMainMenu();
	//GUI::MainMenu m_mainMenu;


	//temp stuff
	sf::Texture texture;


	virtual void input(sf::Event evnt) override;		
	virtual void update() override;		
	virtual void draw(Renderer& renderer) override;

private:
	sf::Texture& m_background;

	// private and deleted copy and move constructors to avoid pointer invalidation
	StateMainMenu(const StateMainMenu& s) = delete;
	StateMainMenu& operator = (const StateMainMenu &s) = delete;

};

