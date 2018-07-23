#pragma once
#include "FixedObject.h"

class Organelle;

class Membrane : public FixedObject
{
public:
	Membrane(const sf::Vector2i& position);
	// is this even needed? could be accessed via position-tile-organelle-outerOrganelle
	//unsigned int m_outerOrganelleIndex;
private:
	
};

