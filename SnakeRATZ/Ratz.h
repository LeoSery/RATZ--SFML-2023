#include <SFML/Graphics.hpp>

class Ratz
{
public:
	Ratz(int a, int b, int cellSize, sf::Texture& texture);
	sf::Sprite cell;
	int x, y;
};
