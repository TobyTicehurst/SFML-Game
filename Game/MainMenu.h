#pragma once
#include "Panel.h"
#include "Button.h"
#include "Game.h"
#include "StatePlaying.h" // for play button


namespace GUI {

// MainMenu is the first menu reached when opening the game
class MainMenu : public Panel {

public:

	// constructor
	MainMenu(Renderable& panelSprite, Renderable& buttonSprite, const sf::Font& font, Game* game);
};

}