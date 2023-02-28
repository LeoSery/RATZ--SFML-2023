#include "Snake.h";
#include "MyVector.h";

Snake::Snake(int cellSize, std::vector<sf::Texture>& textures) {
	sHeight = 1;
	snake.push_back(Ratz(8, 14, cellSize, textures[3]));
	snake.push_back(Ratz(8, 15, cellSize, textures[3]));
}
void Snake::LookDirection(MyVector newDirection) {
		direction = newDirection;
	}
void Snake::Eat() {
	}

void Snake::Move(sf::Window window, MyVector direction, float rate) {

};