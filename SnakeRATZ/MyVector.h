#pragma once
#include <SFML/Graphics.hpp>

class MyVector
{
public:
	int x, y;
	MyVector(int a, int b);
	MyVector() = default;
	MyVector(sf::Vector2f pos);
};

