#include "MyVector.h";
#include "Ratz.h"

#define M_PI 3.14159265358979323846

Ratz::Ratz(int a, int b, int cellSize, sf::Texture& texture) {
	x = a;
	y = b;

	cell.setTexture(texture);
	float scaleFactor = cellSize / std::max(cell.getGlobalBounds().width, cell.getGlobalBounds().height);
	cell.setScale(scaleFactor, scaleFactor);
	cell.setPosition(y * cellSize, x * cellSize);
}

void Ratz::TurnRatz(MyVector& direction)
{
	 
	if (x == (x+direction.x) && y != (y + direction.y) ) { // direction verticale
		
		cell.setRotation(0.0f);
	}
	else if (x != (x + direction.x) && y == (y + direction.y)) { // direction horizontale
		
		cell.setRotation(-90.0f);
	}
}
