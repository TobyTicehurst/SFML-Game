/// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// change from tiles having a reference to an organelle to organelles having a vector of references to tiles
/// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

// create the organelle without its tiles
// change the membranes pointers
// add the tiles later


// possible solution
// create the organelles and store pointers in the vector and tiles and membranes
// later add them to arrays 


#include "Surface.h" 
#include <iostream>
#include "Membrane.h"

Surface::Surface(Renderable& tileRenderable)

{

	m_tiles.reserve(WORLD_SIZE * WORLD_SIZE);
	for (unsigned int i = 0; i < m_tiles.capacity(); ++i)
		m_tiles.emplace_back(sf::Vector2f(i / WORLD_SIZE, i % WORLD_SIZE), tileRenderable);
	/*
	for (unsigned int i = 0; i < m_tiles.size(); i++) {
		if (i % WORLD_SIZE == 0
			|| i % WORLD_SIZE == WORLD_SIZE - 1
			|| i < WORLD_SIZE
			|| i >(WORLD_SIZE - 1) * WORLD_SIZE) {
			addMembrane(sf::Vector2i(i % WORLD_SIZE, i / WORLD_SIZE));
		}
	}

	createOrganelle(WORLD_SIZE * 4 - 4);
	*/
	//scanLineFloodFill(sf::Vector2i(1, 1));
}

// Rendering	////////////////////////////////////////////////////////////////////////////////////////////////////

void Surface::draw(Renderer& renderer) {
	// draw the world
	//for (auto& tile : m_tiles)
		//renderer.draw(tile);
	/*
	// Draw Fixed Objects
	for (unsigned int i = 0; i < m_membranes.getRaw().size(); i++) {
		if (true) {
			sf::Vector2f position = Mappings::TileToWorld(m_membranes.getRaw()[i].m_position);
			//target.drawMembrane(position);
		}
	}
	*/
	// draw tiles
	//for (auto& e : m_tiles)
		//e.draw(target, states);

	// draw membranes
	//for (auto& e : m_membranes)
		//e.draw(target, states);
	
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Tile& Surface::getTile(const sf::Vector2i& coords) {
	if (coords.x >= 0 && coords.x < WORLD_SIZE && coords.y >=0 && coords.y < WORLD_SIZE) {
		return m_tiles[coords.x + coords.y * WORLD_SIZE];
	}
	// add error catching
	// use std::Vector at() ?
}
Tile& Surface::getTile(const int x, const int y) {
	if (x >= 0 && x < WORLD_SIZE && y >= 0 && y < WORLD_SIZE) {
		return m_tiles[x + y * WORLD_SIZE];
	}
}



const unsigned int Surface::createOrganelle(int numberOfMembranes) {
	return m_organelles.addObject(new Organelle(numberOfMembranes));
}


void Surface::createChild() {
	//m_children.push_back(new Surface());
}


void Surface::deleteMembrane(const sf::Vector2i& coords) {
	// ToDo possible error checking
	if (getTile(coords).getFixedObjectType() != FixedObjectType::MEMBRANE)
		return;

	m_membranes.destroyObject(getTile(coords).m_fixedObjectIndex);
	getTile(coords).m_fixedObjectIndex = -1;
	getTile(coords).setFixedObjectType(FixedObjectType::NONE);
}

void Surface::addMembrane(const sf::Vector2i& coords) {
	getTile(coords).m_fixedObjectIndex = m_membranes.addObject(new Membrane(coords));
	getTile(coords).setFixedObjectType(FixedObjectType::MEMBRANE);
}


sf::Vector2i Surface::getAdjacentTile(const sf::Vector2i& coords, const char index) {
	// ToDo check its not too close to the edge
	// for different map types this will change
	// index starts at the top left hexagon and goes clockwise

	if (index / 6 == 0) {
		if (index == 0)
			return sf::Vector2i(coords.x + (coords.y % 2 ? 1 : 0), coords.y - 1);
		else if (index == 1)
			return sf::Vector2i(coords.x + 1, coords.y);
		else if (index == 2)
			return sf::Vector2i(coords.x + (coords.y % 2 ? 1 : 0), coords.y + 1);
		else if (index == 3)
			return sf::Vector2i(coords.x - 1 + (coords.y % 2 ? 1 : 0), coords.y + 1);
		else if (index == 4)
			return sf::Vector2i(coords.x - 1, coords.y);
		else if (index == 5)
			return sf::Vector2i(coords.x - 1 + (coords.y % 2 ? 1 : 0), coords.y - 1);
	}
	else {
		if (index == 6)
			return sf::Vector2i(coords.x, coords.y - 2);
		else if (index == 7)
			return sf::Vector2i(coords.x + 1 + (coords.y % 2 ? 1 : 0), coords.y - 1);
		else if (index == 8)
			return sf::Vector2i(coords.x + 1 + (coords.y % 2 ? 1 : 0), coords.y + 1);
		else if (index == 9)
			return sf::Vector2i(coords.x, coords.y + 2);
		else if (index == 10)
			return sf::Vector2i(coords.x - 2 + (coords.y % 2 ? 1 : 0), coords.y + 1);
		else if (index == 11)
			return sf::Vector2i(coords.x - 2 + (coords.y % 2 ? 1 : 0), coords.y - 1);
	}
}
/*
void Surface::createMembrane(const sf::Vector2i& coords) {
	// Tests relevent tiles to see if placing a membrane at coords will create either an organelle with no centre or an organelle with more than 2 adjacent membranes. 
	// More than 2 adjacent membranes is illegal for now to avoid branching and touching organelles. // ToDo: for later, highlight possible positions?
	// currentIndex is the index of adjacent membranes[1] for the next function
	std::vector<sf::Vector2i> adjacentMembranes;
	int currentIndex;
{
	bool skip = false;
	for (int i = 0; i < 6; i++) {
		if (!skip) {
			if (getTile(getAdjacentTile(coords, i)).getFixedObjectType() == FixedObjectType::MEMBRANE) {
				// when i = 5 dont need to test 1 but it complicates the code
				if (getTile(getAdjacentTile(coords, (i + 1) % 6)).getFixedObjectType() == FixedObjectType::MEMBRANE
					|| (getTile(getAdjacentTile(coords, i + 6)).getFixedObjectType() == FixedObjectType::MEMBRANE
						&&	getTile(getAdjacentTile(coords, (i + 1) % 6 + 6)).getFixedObjectType() == FixedObjectType::MEMBRANE)
					|| (i == 0
						&& getTile(getAdjacentTile(coords, 5)).getFixedObjectType() == FixedObjectType::MEMBRANE))
				{
					std::cout << "Illegal membrane placement! Placing a membrane here will cause either a membrane to have 3 or more neighbours or create an organelle with no centre.\n";
					return;
				}
				else {
					skip = true;
					adjacentMembranes.push_back(getAdjacentTile(coords, i));
					currentIndex = i;
				}
			}
		}
		else
			skip = false;
		if (adjacentMembranes.size() == 3) {
			std::cout << "Cannot place a membrane with more than 3 neighbours!\n";
			return;
		}
	}

	// change the tile type if it hasn't returned yet
	addMembrane(coords);
	

	// if there are 2 neighbouring membranes, a closed loop and so an organelle could have been formed
	if (adjacentMembranes.size() != 2) { // can only be 0, 1 or 2
		return;
	}
}
	/// New Function ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// follows the path of the membranes to see if it forms a loop. If it does, a new organelle is formed.
	// A ScanLineFloodFill algorithm is executed to see which tiles are in the new organelle. ToDo: membranes in the organelle
int organelleIndex;
sf::Vector2i min; sf::Vector2i max;
sf::Vector2i startCoords = adjacentMembranes[1];
std::vector <Membrane*> organelleMembranes{ &m_membranes[getTile(coords).m_fixedObjectIndex],
											&m_membranes[getTile(adjacentMembranes[0]).m_fixedObjectIndex],
											&m_membranes[getTile(adjacentMembranes[1]).m_fixedObjectIndex] };
{
	// redefine currentIndex for this function
	int index = currentIndex;
	sf::Vector2i finalCoords = adjacentMembranes[0];
	sf::Vector2i currentCoords = startCoords;
	min = currentCoords; max = currentCoords;

	int dontLoopForever = 0; int maxLoop = 1000;
	while (dontLoopForever < maxLoop) {
		dontLoopForever++;

		for (int i = -1; i < 2; i++) {
			if (getTile(getAdjacentTile(currentCoords, (((i + currentIndex) % 6) + 6) % 6)).getFixedObjectType() == FixedObjectType::MEMBRANE) {
				currentCoords = getAdjacentTile(currentCoords, (((i + currentIndex) % 6) + 6) % 6);
				organelleMembranes.push_back(&m_membranes[getTile(currentCoords).m_fixedObjectIndex]);
				currentIndex += i;

				// bounds of the organelle
				if (currentCoords.x < min.x)
					min.x = currentCoords.x;
				else if (currentCoords.x > max.x)
					max.x = currentCoords.x;
				if (currentCoords.y < min.y)
					min.y = currentCoords.y;
				else if (currentCoords.y > max.y)
					max.y = currentCoords.y;

				break;
			}
			else if (i == 1)
				return;
		}
		if (currentCoords == finalCoords)
			break;
	}
	if (dontLoopForever >= maxLoop) {
		std::cout << "Error: long loop\n";
		return;
	}
	
	// redefine startCoords for the next function
	startCoords = getAdjacentTile(startCoords, (index + (((currentIndex - index > 0 ? 2 : -2)) % 6) + 6) % 6);

	// create new organelle
	// if the organelle needs to know about its membranes here's the place to do it
	organelleIndex = createOrganelle(organelleMembranes.size() - 1);
	for (unsigned int i = 0; i < organelleMembranes.size(); i++)
		getTile(organelleMembranes[i]->m_position).m_organelleIndex = organelleIndex;
}
	/// ScanLineFloodFill ////////////////////////////////////////////////////////////////////////////////////////
	// calculates the tiles inside the new organelle
	// ToDo inner organelle
	// if you come across a membrane which has an inner organelle thats not m_organelles.back()
	// then set its outer organelle to m_organelle.back()

	if (min.x < 0 || max.x > WORLD_SIZE - 1 || min.y < 0 || max.y > WORLD_SIZE - 1)
		std::cout << "FloodFill: Illegal bounds\n";

	std::vector <bool> testedTiles((max.x - min.x + 1) * (max.y - min.y + 1), false);

	struct Range {
		int xMin;
		int xMax;
		int y;
		//int width;
		//bool extendLeft = true;
		//bool extendRight = true;
	};

	std::vector <Range> ranges;
	Range initial{ startCoords.x, startCoords.x, startCoords.y };
	ranges.push_back(initial);

	// (x, y) - (xMin, yMin), then * by the length of a row (xMax - xMin + 1)
	// testedTiles[x - xMin + (y - yMin) * (xMax - xMin + 1)]
	testedTiles[startCoords.x - min.x + (startCoords.y - min.y) * (max.x - min.x + 1)] = true;

	int dontLoopForever = 0; int maxLoop = 100;
	while (!ranges.empty() && dontLoopForever < maxLoop) {
		dontLoopForever++;
		Range r = ranges.back();
		ranges.pop_back();

		if (r.xMin < min.x)
			r.xMin = min.x;
		if (r.xMax > max.x - 1)
			r.xMax = max.x - 1;

		// extend left
		// while in range and not tested yet, if blanck add, else, if inner then change
		if (true) {
			while (r.xMin > min.x && !testedTiles[r.xMin - 1 - min.x + (r.y - min.y) * (max.x - min.x + 1)]) {
				if (getTile(r.xMin - 1, r.y).getFixedObjectType() != FixedObjectType::MEMBRANE) {
					testedTiles[r.xMin - 1 - min.x + (r.y - min.y) * (max.x - min.x + 1)] = true;
					r.xMin--;
				}
				else {
					if (getTile(r.xMin - 1, r.y).m_organelleIndex != organelleIndex)
						m_organelles[getTile(r.xMin - 1, r.y).m_organelleIndex].outerOrganelleIndex = organelleIndex;
						//m_membranes[getTile(r.xMin - 1, r.y).m_fixedObjectIndex].m_outerOrganelleIndex = organelleIndex;
					break;
					
				}
			}
		}

		// extend right
		if (true) {
			while (r.xMax < max.x - 1 && !testedTiles[r.xMax + 1 - min.x + (r.y - min.y) * (max.x - min.x + 1)]) {
				if (getTile(r.xMax + 1, r.y).getFixedObjectType() != FixedObjectType::MEMBRANE) {
					testedTiles[r.xMax + 1 - min.x + (r.y - min.y) * (max.x - min.x + 1)] = true;
					r.xMax++;
				}
				else {
					if (getTile(r.xMax + 1, r.y).m_organelleIndex != organelleIndex)
						m_organelles[getTile(r.xMax + 1, r.y).m_organelleIndex].outerOrganelleIndex = organelleIndex;
					break;
				}
			}
		}

		for (unsigned int i = 0; i < 2; i++) {
			int newY;
			if (i == 0 && r.y < max.y)
				newY = r.y + 1;
			else if (i == 1 && r.y > min.y)
				newY = r.y - 1;
			else
				continue;
			int newxMin;
			int tempXMin = r.xMin + (newY % 2 ? -1 : 0);
			int tempXMax = r.xMax + (newY % 2 ? 0 : 1);

			bool searchForFloor = true;

			for (int x = tempXMin; x <= tempXMax; x++) {
				if (searchForFloor && !testedTiles[x - min.x + (newY - min.y) * (max.x - min.x + 1)]) {
					if (getTile(x, newY).getFixedObjectType() != FixedObjectType::MEMBRANE) {
						testedTiles[x - min.x + (newY - min.y) * (max.x - min.x + 1)] = true;
						if (searchForFloor) {
							newxMin = x;
							searchForFloor = false;
						}
					}
					else if (getTile(x, newY).m_organelleIndex != organelleIndex)
						m_organelles[getTile(x, newY).m_organelleIndex].outerOrganelleIndex = organelleIndex;
				}
				else if (!searchForFloor &&
						(testedTiles[x - min.x + (newY - min.y) * (max.x - min.x + 1)]
						|| getTile(x, newY).getFixedObjectType() == FixedObjectType::MEMBRANE)) {
					Range temp{ newxMin, x - 1, newY };
					ranges.push_back(temp);
					searchForFloor = true;
				}
				if (x == tempXMax) {
					if (!searchForFloor) {
						Range temp{ newxMin, x, newY };
						ranges.push_back(temp);
					}
				}
			}
		}
	}
	
	if (dontLoopForever >= maxLoop) {
		std::cout << "Error: long loop\n";
		return;
	}

	std::vector <Tile*> tiles;
	for (unsigned int i = 0; i < testedTiles.size(); i++) {
		if (testedTiles[i]) {
			Tile& tile = getTile(min.x + i % (max.x - min.x + 1), min.y + i / (max.x - min.x + 1));
			tiles.push_back(&tile);
			tile.setTileType(TileType::BUILDING);
			tile.m_organelleIndex = organelleIndex;
		}
	}
	m_organelles.getRaw().back().addTiles(tiles);
}

*/