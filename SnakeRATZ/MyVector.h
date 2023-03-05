#pragma once
#include <SFML/Graphics.hpp>

class MyVector
{
public:
	MyVector(sf::Vector2f pos);
	MyVector(int a, int b);
	MyVector() = default;
	int x, y;
};
