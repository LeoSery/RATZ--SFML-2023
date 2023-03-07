#include <SFML/Graphics.hpp>
#include "MyVector.h"
#include <random>

class Cheese
{
public:
	Cheese(int rows, int cols, int cellSize, sf::Texture& cheeseTexture);
	void randomizePos();
	sf::Sprite cell;
	int getX();
	int getY();

private:
	int rows;
	int cols;
	int cellSize;
	int x;
	int y;
};
