#include "Snake.h";
#include "MyVector.h";


Snake::Snake(int cellSize, std::vector<sf::Texture>& textures) {
	direction = MyVector(1, 0);
	this->cellSize = cellSize;
	sHeight = 1;
	snake.push_back(Ratz(1, 0, cellSize, textures[3]));
	snake.push_back(Ratz(0, 0, cellSize, textures[3]));
}
Snake::Snake() {

}
void Snake::LookDirection(MyVector newDirection) {
	direction = newDirection;
}
void Snake::Eat() {
}


void Snake::draw(sf::RenderWindow& window) {
	for (Ratz& ratz : snake) {
		window.draw(ratz.cell);
	}
}

void Snake::Move() {
	Ratz& head = snake[0];
	MyVector position(head.cell.getPosition());
	std::cout << head.cell.getPosition().x << head.cell.getPosition().y << std::endl;
	head.cell.setPosition(position.x + direction.x * cellSize, position.y + direction.y * cellSize);
	std::cout << head.cell.getPosition().x << head.cell.getPosition().y << std::endl;
	head.x += direction.x;
	head.y += direction.y;
	for (int i = snake.size() - 1; i > 0; i--) {
		Ratz &block = snake[i];
		sf::Vector2f nextPosition = snake[i - 1].cell.getPosition();
		block.cell.setPosition(nextPosition);
	}
};