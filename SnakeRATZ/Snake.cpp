#include "MyVector.h";
#include "Cheese.h";
#include "Snake.h";


Snake::Snake(int cellSize, std::vector<sf::Texture>& textures) {
	this->textures = textures;
	direction = MyVector(0, -1);

	this->cellSize = cellSize;
	sHeight = 1;
	snake.push_back(Ratz(5, 4, cellSize, textures[4]));
	snake.push_back(Ratz(5, 5, cellSize, textures[3]));
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

void Snake::Eat(std::vector<Cheese>& cheeseList) {
	std::cout << cheeseList[0].cell.getPosition().x << cheeseList[0].cell.getPosition().y << std::endl;
	std::cout << snake[0].cell.getPosition().x << snake[0].cell.getPosition().y << std::endl;

	if (snake[0].cell.getPosition().x <= cheeseList[0].cell.getPosition().x + 40 && snake[0].cell.getPosition().x >= cheeseList[0].cell.getPosition().x) {
		if (snake[0].cell.getPosition().y <= cheeseList[0].cell.getPosition().y + 20 && snake[0].cell.getPosition().y >= cheeseList[0].cell.getPosition().y-20) {
			cheeseList[0].randomizePos();

			int LastIndex = snake.size()-1;
			snake.push_back(Ratz(snake[LastIndex].x, snake[LastIndex].y, cellSize, textures[3]));
			snake[LastIndex + 1].ratzDirection = snake[LastIndex].nextratzDirection;
		}
	}

	if (cheeseList[0].getX() == snake[0].x - 2  && cheeseList[0].getY() == snake[0].y) {
		
	}


}

void Snake::draw(sf::RenderWindow& window) {
	for (Ratz& ratz : snake) {
		window.draw(ratz.cell);
	}
}

void Snake::Move() {
	Ratz& head = snake[0];
	head.nextratzDirection = head.ratzDirection;
	head.ratzDirection = direction; // saving next direction for normal rotations
	MyVector position(head.cell.getPosition());

	for (int i = snake.size() - 1; i > 0; i--) {
		Ratz& body = snake[i];
		body.x = snake[i - 1].x;
		body.y = snake[i - 1].y;
		body.ratzDirection = body.nextratzDirection;
		body.nextratzDirection = snake[i - 1].ratzDirection;
		
		sf::Vector2f nextPosition = snake[i - 1].cell.getPosition();

		body.cell.setPosition(nextPosition);
		body.TurnRatz(body.nextratzDirection);
	}

	head.cell.setPosition(position.x + direction.x * cellSize, position.y + direction.y * cellSize);
	head.TurnRatz(direction);
	head.x += direction.x;
	head.y += direction.y;
};
