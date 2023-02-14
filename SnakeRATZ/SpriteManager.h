#include <SFML/Graphics.hpp>
#include <iostream>

class SpriteManager
{
public:
	static sf::Texture loadTexture(const std::string& filename);
	static void resizeSprite(sf::Sprite& sprite, int cellSize);
};
