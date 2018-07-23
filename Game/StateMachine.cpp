#include "StateMachine.h"



StateMachine::StateMachine() 
	//m_state{ std::make_unique<StateMainMenu>(game) }
{}
/*
void StateMachine::play(Game* const game) {
	changeState<StatePlaying>(game);
}

void StateMachine::mainMenu(Game* const game) {
	changeState<StateMainMenu>(game);
}
*/
void StateMachine::input(sf::Event e) {
	m_state->input(e);
}

void StateMachine::update() {
	m_state->update();
}

void StateMachine::draw(Renderer& renderer) {
	m_state->draw(renderer);
}
