#include "Organelle.h"



Organelle::Organelle(int numberOfMembranes) :
	m_numberOfMembranes(numberOfMembranes),
	m_Resource(0)

{

}


Organelle::~Organelle()
{
}

void Organelle::addTiles(std::vector <Tile*>& tiles) {
	m_tiles = tiles;
}

void Organelle::update() {

}