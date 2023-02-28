#include "Snake.h";
#include "MyVector.h";

extern int rows, cols, cellSize;

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
	Ratz head = snake[0];
	MyVector position(head.cell.getPosition());
	head.cell.setPosition(position.x + direction.x * cellSize, position.y + direction.y * cellSize);
	for (int i = snake.size() - 1; i > 0; i--) {
		Ratz block = snake[i];
		sf::Vector2f nextPosition = snake[i - 1].cell.getPosition();
		block.cell.setPosition(nextPosition);
	}
};