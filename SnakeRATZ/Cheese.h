#include "MyVector.h"
#include <SFML/Graphics.hpp>
#include <random>

class Cheese
{
private:
	int x;
	int y;
	

public:
	sf::Sprite cell;
	int getX();
	int getY();
	Cheese(int rows, int cols, int cellSize,sf::Texture& cheeseTexture);

};

