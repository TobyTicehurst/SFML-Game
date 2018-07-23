#include "RenderableMap.h"

RenderableMap::RenderableMap(const sf::Texture& fail) :
	m_fail(fail)
{}

Renderable& RenderableMap::get(const std::string& name)
{
	if (!exists(name))
		add(name, m_fail);

	return m_renderables.at(name);
}

bool RenderableMap::exists(const std::string& name) const {
	return m_renderables.find(name) != m_renderables.end();
}

void RenderableMap::add(const std::string& name, const sf::Texture& texture) {

	Renderable renderable(texture);
	m_renderables.insert(std::make_pair(name, renderable));
}