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
	int dx = 2;
	int dy = 2;
	snake.push_back(Ratz(snake[sHeight].x + dx, snake[sHeight].y + dy));
	sHeight += 1;
	}

void Snake::Move(MyVector direction, float rate) {
};