#include "Snake.h";
#include "MyVector.h";


Snake::Snake(int cellSize, std::vector<sf::Texture>& textures) {
	direction = MyVector(1, 0);
	this->cellSize = cellSize;
	sHeight = 1;
	snake.push_back(Ratz(8, 14, cellSize, textures[3]));
	snake.push_back(Ratz(8, 15, cellSize, textures[3]));
}
Snake::Snake() {

}
void Snake::LookDirection(MyVector newDirection) {
	direction = newDirection;
}
void Snake::Eat() {
}

void Snake::Move() {
	Ratz& head = snake[0];
	MyVector position(head.cell.getPosition());
	head.cell.move(direction.x * cellSize, direction.y * cellSize);
	head.x += direction.x;
	head.y += direction.y;
	for (int i = snake.size() - 1; i > 0; i--) {
		Ratz &block = snake[i];
		sf::Vector2f nextPosition = snake[i - 1].cell.getPosition();
		block.cell.setPosition(nextPosition);
	}
	std::cout << direction.x << direction.y << std::endl;
	std::cout << head.x << head.y << std::endl;
};