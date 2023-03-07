#include <SFML/Graphics.hpp>
#include "MyVector.h";

#include <iostream>;
#include <vector>;
#include "Ratz.h";


class Snake
{
public:
	Snake(int cellSize, std::vector<sf::Texture>& textures);
	void LookDirection(int newDirection);
	void draw(sf::RenderWindow& window);
	void Move();
	void CheckDeath(bool& gameOver);

	void Eat(std::vector<Cheese>& cheeseList);
	std::vector<Ratz> snake;
	MyVector direction;
	int sHeight;
	int cellSize;
	std::vector<sf::Texture> textures;
};
