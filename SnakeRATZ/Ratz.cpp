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
	float angle = atan2(direction.y, direction.x) * 180.0f / M_PI;

	if (angle > -45.0f && angle <= 45.0f) {
		cell.setRotation(0.0f);
	}
	else if (angle > 45.0f && angle <= 135.0f) {
		cell.setRotation(90.0f);
	}
	else if (angle > 135.0f || angle <= -135.0f) {
		cell.setRotation(180.0f);
	}
	else if (angle > -135.0f && angle <= -45.0f) {
		cell.setRotation(-90.0f);
	}
}
