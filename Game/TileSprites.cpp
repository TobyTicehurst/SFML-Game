#include "TileSprites.h"

TileSprites::TileSprites() {

	// create a default hexagon
	sf::ConvexShape hexagonTile;

	// resize the "circle" to 6 points
	hexagonTile.setPointCount(6);

	// define the points
	hexagonTile.setPoint(0, sf::Vector2f(0.0f, 1.0f));
	hexagonTile.setPoint(1, sf::Vector2f(ROOT3 / 2, 0.5f));
	hexagonTile.setPoint(2, sf::Vector2f(ROOT3 / 2, -0.5f));
	hexagonTile.setPoint(3, sf::Vector2f(0.0f, -1.0f));
	hexagonTile.setPoint(4, sf::Vector2f(-ROOT3 / 2, -0.5f));
	hexagonTile.setPoint(5, sf::Vector2f(-ROOT3 / 2, 0.5f));

	// define position, set position isn't needed
	hexagonTile.setOrigin(sf::Vector2f(0.0f, 0.0f));
	hexagonTile.setPosition(sf::Vector2f(0.0f, 0.0f));
	hexagonTile.setScale(sf::Vector2f(PIXELS_PER_TILE, PIXELS_PER_TILE));
	hexagonTile.setOutlineColor(sf::Color::White);
	hexagonTile.setOutlineThickness(0.02);

	// commented out till textures are needed, not sure on the use of PIXELS_PER_TILE
	/*
	if (!squaretiles.loadFromFile("images/squaretiles.jpeg")) {
	std::cout << "Failed to load texture\n";
	}
	hexagonTile.setTexture(&squaretiles);
	hexagonTile.setTextureRect(sf::IntRect(0, 0, 2 * PIXELS_PER_TILE, 2 * PIXELS_PER_TILE));
	*/


	// create an array of sprites
	for (int i = 0; i < sizeof(Sprites) / sizeof(Sprites[0]); i++)
	{
		Sprites[i] = hexagonTile;
	}


	// define their colour
	Sprites[0].setFillColor(sf::Color::Cyan);
	Sprites[1].setFillColor(sf::Color::Blue);
	Sprites[2].setFillColor(sf::Color::Green);

	/*
	// create the outline (linestrip)
	sf::VertexArray hexagonOutline(sf::LinesStrip, 7);

	// define the points
	hexagonOutline[0].position = sf::Vector2f((ROOT3 / 2) * PIXELS_PER_TILE, 0.0f);
	hexagonOutline[1].position = sf::Vector2f(ROOT3 * PIXELS_PER_TILE, 0.5f * PIXELS_PER_TILE);
	hexagonOutline[2].position = sf::Vector2f(ROOT3 * PIXELS_PER_TILE, 1.5f * PIXELS_PER_TILE);
	hexagonOutline[3].position = sf::Vector2f((ROOT3 / 2) * PIXELS_PER_TILE, 2.0f * PIXELS_PER_TILE);
	hexagonOutline[4].position = sf::Vector2f(0.0f, 1.5f * PIXELS_PER_TILE);
	hexagonOutline[5].position = sf::Vector2f(0.0f, 0.5f * PIXELS_PER_TILE);
	hexagonOutline[6].position = sf::Vector2f((ROOT3 / 2) * PIXELS_PER_TILE, 0.0f);

	// define their colour
	for (int i = 0; i < 7; i++) {
	hexagonOutline[i].color = sf::Color::White;
	}
	*/
}


/*
// define the points
// origin 0,0
hexagonTile.setPoint(0, sf::Vector2f((ROOT3 / 2), 0.0f));
hexagonTile.setPoint(1, sf::Vector2f(ROOT3, 0.5f));
hexagonTile.setPoint(2, sf::Vector2f(ROOT3, 1.5f));
hexagonTile.setPoint(3, sf::Vector2f((ROOT3 / 2), 2.0f));
hexagonTile.setPoint(4, sf::Vector2f(0.0f, 1.5f));
hexagonTile.setPoint(5, sf::Vector2f(0.0f, 0.5f));
*/
