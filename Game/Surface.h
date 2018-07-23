#pragma once
#include <vector>
#include "GlobalVariables.h"
#include "Tile.h"

#include "Mappings.h"
#include "Renderer.h"
#include "Organelle.h"
#include "Membrane.h"
#include "ObjectStorage.h" // use getRaw when directly accessing objects and the [] operator when using indicies

class Surface
{
public:
	// ToDo make all function calls &
	// add a get fixed object funtion in tile
	// change membranes to surroundingMembranes
	Surface(Renderable& tileRenderable);

	// Rendering	////////////////////////////////////////////////////////
	void draw(Renderer& renderer);
	/////////////////////////////////////////////////////////////////////////


	Tile& getTile(const sf::Vector2i& coords);
	Tile& getTile(const int x, const int y);

	void addMembrane(const sf::Vector2i& coords);

	const unsigned int createOrganelle(int numberOfMembranes);
	void createChild();

	sf::Vector2i getAdjacentTile(const sf::Vector2i& coords, const char index);
	void deleteMembrane(const sf::Vector2i& coords);
	//void createMembrane(const sf::Vector2i& coords);
	

private:

	// Rendering //////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////


	// private so index checking can be done by getters

	// null ptr for the highest surface
	//Surface *m_parent;

	// have a vector of pointers to the start of each vector of fixed objects

	ObjectStorage <Membrane> m_membranes;
	ObjectStorage <Organelle> m_organelles;
	//std::vector <Organelle> m_organelles;
	std::vector <Tile> m_tiles;
	std::vector <Surface*> m_children;
};
