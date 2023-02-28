#pragma once
#include <vector>;
#include "Ratz.h";
#include "MyVector.h";
#include <SFML/Graphics.hpp>

class Snake
{
public:
	std::vector<Ratz> snake;
	int sHeight;
	MyVector direction;
	Snake();
	void LookDirection(MyVector newDirection);
	void Eat();
	void Move(sf::Window window, MyVector direction, float rate);
};
