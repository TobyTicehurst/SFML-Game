#pragma once
#include "StateBase.h"
#include "Surface.h"



class StatePlaying : public StateBase
{

public:
	StatePlaying(Game* const game);

	void virtual input(sf::Event evnt) override;
	void virtual update() override;
	void virtual draw(Renderer& renderer) override;

	Surface m_surface;
	sf::Vector2i m_mouseTile;

};