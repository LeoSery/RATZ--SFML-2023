#pragma once
#include <vector>;
#include "Ratz.h";
#include "MyVector.h";
#include <SFML/Graphics.hpp>
#include <iostream>;

class Snake
{
public:
	std::vector<Ratz> snake;
	int sHeight;
	int cellSize;
	MyVector direction;
	Snake(int cellSize, std::vector<sf::Texture>& textures);
	Snake();
	void LookDirection(int newDirection);
	void draw(sf::RenderWindow& window);
	void Eat();
	void Move();
};
