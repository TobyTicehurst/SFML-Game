#pragma once
#include "SFML\Graphics.hpp"

class Game;
class Renderer;

class StateBase
{
public:
	StateBase(Game* const game)
		: m_pGame(game)
	{}
	virtual ~StateBase() = default;

	virtual void input(sf::Event evnt) = 0;
	virtual void update() = 0;
	virtual void draw(Renderer& renderer) = 0;

protected:
	Game* const m_pGame;
};

