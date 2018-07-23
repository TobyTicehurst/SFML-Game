#pragma once
#include <vector>

class Tile;

class Organelle
{
public:

	Organelle(int numberOfMembranes);
	~Organelle();

	void addTiles(std::vector <Tile*>& tiles);

	void update();

	int m_numberOfMembranes;
	int m_Resource;

	int outerOrganelleIndex;
	std::vector <int> innerOrganelleInicies;

	std::vector <Tile*> m_tiles;
	// need a 

};

