#include "Cheese.h"

Cheese::Cheese(int rows, int cols, int cellSize, sf::Texture& cheeseTexture) {
	this->rows = rows;
	this->cols = cols;
	this->cellSize = cellSize;
	cell.setTexture(cheeseTexture);
	float scaleFactor = cellSize / std::max(cell.getGlobalBounds().width, cell.getGlobalBounds().height);
	cell.setScale(scaleFactor, scaleFactor);
	randomizePos();
}

void Cheese::randomizePos() {
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distrx(0, rows); // define the x range
	x = distrx(gen);
	std::uniform_int_distribution<> distry(0, cols); // define the y range
	y = distry(gen);
	
	cell.setPosition(x * cellSize, y * cellSize);
}

int Cheese::getX() {
	return x;
}

int Cheese::getY() {
	return y;
}
