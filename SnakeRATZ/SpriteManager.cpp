#include "SpriteManager.h"

sf::Texture SpriteManager::loadTexture(const std::string& filename)
{
	sf::Texture texture;

	if (!texture.loadFromFile(filename)) {
		std::cerr << "Failed to load texture from file " << filename << std::endl;
	}

	return texture;
}

void SpriteManager::resizeSprite(sf::Sprite& sprite, int cellSize)
{
	float scaleFactor = cellSize / std::max(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
	sprite.setScale(scaleFactor, scaleFactor);
}