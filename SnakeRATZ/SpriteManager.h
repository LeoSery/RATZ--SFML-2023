#include <SFML/Graphics.hpp>
#include <iostream>

class SpriteManager
{
public:
	static void resizeSprite(sf::Sprite& sprite, int cellSize);
	static sf::Texture loadTexture(const std::string& filename);
};
