#include "Snake.h";
#include "MyVector.h";

Snake::Snake() {
	sHeight = 1;
	snake.push_back(Ratz(8, 14));
	snake.push_back(Ratz(8, 15));
}
void Snake::LookDirection(MyVector newDirection) {
		direction = newDirection;
	}
void Snake::Eat() {
	}

void Snake::Move(sf::Window window, MyVector direction, float rate) {

};