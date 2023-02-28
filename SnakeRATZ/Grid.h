#include <SFML/Graphics.hpp>
#include "Cheese.h"
#include "Snake.h"
#ifndef GRID_H
#define GRID_H

class Grid
{
public:
	Grid(int rows, int cols, int cellSize, std::vector<sf::Texture>& textures);
	~Grid();
	void draw(sf::RenderWindow& window);
	sf::Sprite getCell(int row, int col);
	Snake snake(int cellSize, std::vector<sf::Texture>& textures);
	int getRows();
	int getCols();
private:
	int rows;
	int cols;
	int cellSize;
	sf::Sprite** cells;
	std::vector<Cheese> CheeseList;
};

#endif