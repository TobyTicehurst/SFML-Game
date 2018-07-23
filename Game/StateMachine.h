#pragma once
#include "ptr.h"
#include "StateBase.h"
//#include "StatePlaying.h"
//#include "StateMainMenu.h"
#include "NonCopyable.h"


// 
class StateMachine : public NonCopyable {

public:
	StateMachine();

	// changes the game state to type T
	template<typename T>
	void changeState(Game* const game) {
		if(m_state)
			m_state.reset();
		m_state = std::make_unique<T>(game);
	}

	//void play(Game* const game);
	//void mainMenu(Game* const game);

	void input(sf::Event e);
	void update();
	void draw(Renderer& renderer);


private:

	// Game State
	ptr <StateBase> m_state;

};


