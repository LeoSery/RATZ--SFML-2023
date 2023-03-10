#include "MyVector.h";
#include "Cheese.h";
#include "Snake.h";

Snake::Snake(int cellSize, std::vector<sf::Texture>& textures)
{
	this->textures = textures;
	direction = MyVector(0, -1);

	this->cellSize = cellSize;
	sHeight = 1;
	snake.push_back(Ratz(10, 10, cellSize, textures[4]));
	snake.push_back(Ratz(10, 11, cellSize, textures[3]));
}

void Snake::LookDirection(int newDirection)
{

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
}

void Snake::Eat(std::vector<Cheese>& cheeseList)
{
	

	if (snake[0].cell.getPosition().x <= cheeseList[0].cell.getPosition().x + 40 && snake[0].cell.getPosition().x >= cheeseList[0].cell.getPosition().x)
	{
		if (snake[0].cell.getPosition().y <= cheeseList[0].cell.getPosition().y + 40 && snake[0].cell.getPosition().y >= cheeseList[0].cell.getPosition().y - 20)
		{
			cheeseList[0].randomizePos();

			int LastIndex = snake.size() - 1;
			snake.push_back(Ratz(snake[LastIndex].x, snake[LastIndex].y, cellSize, textures[3]));
			snake[LastIndex + 1].ratzDirection = snake[LastIndex].nextratzDirection;
		}
	}

	if (cheeseList[0].getX() == snake[0].x - 2 && cheeseList[0].getY() == snake[0].y)
	{

	}
}

void Snake::draw(sf::RenderWindow& window)
{
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
		body.nextratzDirection = snake[i - 1].nextratzDirection;

		sf::Vector2f nextPosition = snake[i - 1].cell.getPosition();

		body.cell.setPosition(nextPosition);
		body.TurnRatz(body.nextratzDirection);
	}

	head.cell.setPosition(position.x + direction.x * cellSize, position.y + direction.y * cellSize);
	head.TurnRatz(direction);
	head.x += direction.x;
	head.y += direction.y;
}

void Snake::CheckDeath(bool& gameOver)
{
	Ratz& head = snake[0];
	for (int i = 1; i < snake.size(); i++) {
		if (head.x == snake[i].x && head.y == snake[i].y) {
			gameOver = true;
			break;
		}
	}

	if (head.x < 0 || head.x > 20 || head.y < 0 || head.y > 20) {
		gameOver = true;
	}
};
