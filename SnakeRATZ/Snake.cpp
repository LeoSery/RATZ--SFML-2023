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
void Snake::LookDirection(int newDirection) {
	
	switch (newDirection)
	{
	case 0:
		direction = MyVector(-1, 0);
		break;
	case 1:
		direction = MyVector(1, 0);
		break;
	case 2:
		direction = MyVector(0, -1);
		break;
	case 3:
		direction = MyVector(0, 1);
		break;
	default:
		break;
	}
	std::cout << direction.x << direction.y << std::endl;

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
	head.cell.setPosition(position.x + direction.x * cellSize, position.y + direction.y * cellSize);
	head.x += direction.x;
	head.y += direction.y;
	for (int i = snake.size() - 1; i > 0; i--) {
		Ratz &block = snake[i];
		block.x = snake[i - 1].x;
		block.y = snake[i - 1].y;
		sf::Vector2f nextPosition = snake[i - 1].cell.getPosition();
		
		block.cell.setPosition(nextPosition);
		
	}

	
};