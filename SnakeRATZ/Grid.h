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
	int getRows();
	int getCols();
	sf::Sprite getCell(int row, int col);

private:
	int rows;
	int cols;
	int cellSize;
	sf::Sprite** cells;
	std::vector<Cheese> CheeseList;
};
#endif
