#pragma once
#include "SFML\Graphics.hpp"
#include "Renderable.h"
#include <unordered_map>
#include <iostream>


// this is a temp solution
class RenderableMap {

public:

	RenderableMap(const sf::Texture& fail);

	Renderable& get(const std::string& name);

	bool exists(const std::string& name) const;

	void add(const std::string& name, const sf::Texture& texture);

private:

	const sf::Texture& m_fail;
	std::unordered_map<std::string, Renderable> m_renderables;
};
