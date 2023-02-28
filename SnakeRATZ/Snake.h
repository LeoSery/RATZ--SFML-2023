#pragma once
#include <vector>;
#include "Ratz.h";
#include "MyVector.h";
#include <SFML/Graphics.hpp>

class Snake
{
private:
	std::vector<Ratz> snake;
public:
	int sHeight;
	MyVector direction;
	Snake();
	void LookDirection(MyVector newDirection);
	void Eat();
	void Move(sf::Window window, MyVector direction, float rate);
};
