#include <SFML/Graphics.hpp>
#ifndef GRID_H
#define GRID_H

class Grid
{
public:
	Grid(int rows, int cols, int cellSize);
	~Grid();
	void draw(sf::RenderWindow& window);
	void setCell(int row, int col, bool state);
	bool getCell(int row, int col);
	int getRows();
	int getCols();

private:
	int rows;
	int cols;
	int cellSize;
	sf::RectangleShape** cells;
};

#endif