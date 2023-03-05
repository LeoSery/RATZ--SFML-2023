#include "Ratz.h"

Ratz::Ratz(int a, int b, int cellSize, sf::Texture& texture) {
	x = a;
	y = b;

	cell.setTexture(texture);
	float scaleFactor = cellSize / std::max(cell.getGlobalBounds().width, cell.getGlobalBounds().height);
	cell.setScale(scaleFactor, scaleFactor);
	cell.setPosition(y * cellSize, x * cellSize);
}
