#pragma once
#include <SFML/Graphics.hpp>
class Ratz
{
public:
	int x, y;
	Ratz(int a, int b, int cellSize ,sf::Texture& texture);
	sf::Sprite cell;
};

