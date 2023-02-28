#include "MyVector.h";

MyVector::MyVector(int a, int b) {
	x = a;
	y = b;
}

MyVector::MyVector(sf::Vector2f pos)
{
	x = pos.x;
	y = pos.y;
}
