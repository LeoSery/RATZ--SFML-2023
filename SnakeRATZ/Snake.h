#pragma once
#include <vector>;
#include "Ratz.h";
#include "MyVector.h";
#include "SFML/System/Vector2.hpp";

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
	void Move(MyVector direction, float rate);
};
