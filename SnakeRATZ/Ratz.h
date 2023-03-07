#include <SFML/Graphics.hpp>

class Ratz
{
public:
	Ratz(int a, int b, int cellSize, sf::Texture& texture);
	void TurnRatz(MyVector& direction);
	sf::Sprite cell;
	int x, y;
};
