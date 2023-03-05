#include <SFML/Graphics.hpp>
#include "MyVector.h";
#include <iostream>;
#include <vector>;
#include "Ratz.h";

class Snake
{
public:
	Snake(int cellSize, std::vector<sf::Texture>& textures);
	Snake();
	void LookDirection(int newDirection);
	void draw(sf::RenderWindow& window);
	void Move();
	void Eat();
	std::vector<Ratz> snake;
	MyVector direction;
	int sHeight;
	int cellSize;
};
