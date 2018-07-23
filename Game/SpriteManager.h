#pragma once
#include "SFML\Graphics.hpp"
#include <unordered_map>
#include <string>
#include <iostream>

class SpriteManager
{
public:
	SpriteManager(const sf::Texture& fail);

	sf::Sprite& get(const std::string& name);

	bool exists(const std::string& name) const;

	void add(const std::string& name, const sf::Texture& texture);

private:
	const sf::Texture& m_fail;
	std::unordered_map<std::string, sf::Sprite> m_sprites;
};

