#include "SpriteManager.h"

SpriteManager::SpriteManager(const sf::Texture& fail) :
	m_fail(fail)
{}

sf::Sprite& SpriteManager::get(const std::string& name) {
	if (!exists(name))
		add(name, m_fail);

	return m_sprites.at(name);
}

bool SpriteManager::exists(const std::string& name) const {
	return m_sprites.find(name) != m_sprites.end();
}

void SpriteManager::add(const std::string& name, const sf::Texture& texture){
	sf::Sprite sprite(texture);
	sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	m_sprites.insert(std::make_pair(name, sprite));
}