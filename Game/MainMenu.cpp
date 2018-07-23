#include "MainMenu.h"


// TODO find a better way to define all the variables


int NUMBER_OF_BUTTONS{ 5 };
sf::Vector2f BUTTON_SIZE(256.0f, 64.0f);
float EDGE_SPACING{ 16.0f };
float BUTTON_SPACING{ 16.0f };

sf::Vector2f MAIN_MENU_SIZE(BUTTON_SIZE.x + 2 * EDGE_SPACING, NUMBER_OF_BUTTONS * BUTTON_SIZE.y + (NUMBER_OF_BUTTONS - 1) * BUTTON_SPACING + 2 * EDGE_SPACING);
sf::Vector2f MAIN_MENU_POSITION(0.0f, 0.0f);

sf::Vector2f BUTTON_POSITION(10.0f, 10.0f);
 
namespace GUI {

// MainMenu constructor
MainMenu::MainMenu(Renderable& panelRenderable, Renderable& buttonRenderable, const sf::Font& font, Game* game) :

	// Panel constructor
	Panel(MAIN_MENU_POSITION, panelRenderable, new std::vector< Widget* > {

		// Play
		new Button(sf::Vector2f(0.0f, 2 * (BUTTON_SIZE.y + BUTTON_SPACING)), buttonRenderable, std::string{ "Continue"	}, font, 
		[=]() { 
			game->getGUI().remove(this); 
			game->getState().changeState<StatePlaying>(game);
		}),

		// New Game (TODO)
		new Button(sf::Vector2f(0.0f, 1 * (BUTTON_SIZE.y + BUTTON_SPACING)), buttonRenderable, std::string{ "New Game"	}, font, [&game]() {std::cout << "New Game!\n";	}),
		
		// Load Game (TODO)	
		new Button(sf::Vector2f(0.0f, 0 * (BUTTON_SIZE.y + BUTTON_SPACING)), buttonRenderable, std::string{ "Load Game"	}, font, [&game]() {std::cout << "Load Game\n";	}),
		
		// Options (TODO)	
		new Button(sf::Vector2f(0.0f, -1 * (BUTTON_SIZE.y + BUTTON_SPACING)), buttonRenderable, std::string{ "Options"	}, font, [&game]() {std::cout << "Options!\n";	}),
		
		// Exit (TODO)	
		new Button(sf::Vector2f(0.0f, -2 * (BUTTON_SIZE.y + BUTTON_SPACING)), buttonRenderable, std::string{ "Exit"		}, font, [&game]() {std::cout << "Exit!\n";		})
})
{}

}

