#include "Mappings.h"

sf::Vector2i Mappings::WorldToTile(const sf::Vector2f& worldCoords) {
	// y and z are sets of lines which define the points of each hexagon, allowing for the yPosition to be calculated
	// conditional to do with the offset of hexagons on odd rows.
	int y = floor(worldCoords.y / PIXELS_PER_TILE + (1 / ROOT3) * worldCoords.x / PIXELS_PER_TILE);
	int z = floor(worldCoords.y / PIXELS_PER_TILE - (1 / ROOT3) * worldCoords.x / PIXELS_PER_TILE);
	int yPos = ceil(float(y + z) / 3);
	int xPos = floor(((yPos % 2) ? 0 : 0.5) + worldCoords.x / (ROOT3 * PIXELS_PER_TILE));
	return sf::Vector2i(xPos, yPos);
}

sf::Vector2f Mappings::TileToWorld(const sf::Vector2i& tileCoords) {
	// j % 2, for the offset odd tiles. root3 and 1.5 for geometry of hexagons. -y to make y-axis go up not down, not yet.
	return sf::Vector2f(PIXELS_PER_TILE * ROOT3 * (tileCoords.x + ((tileCoords.y % 2) ? 0.5 : 0)), PIXELS_PER_TILE * 1.5f * tileCoords.y);
}

