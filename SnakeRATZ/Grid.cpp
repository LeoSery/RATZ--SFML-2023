#include "Grid.h"

Grid::Grid(int rows, int cols, int cellSize, std::vector<sf::Texture>& textures, Snake snake)
{
	this->rows = rows;
	this->cols = cols;
	this->cellSize = cellSize;
	this->snake = snake;
	cells = new sf::Sprite * [rows];
	CheeseList.push_back(Cheese(rows, cols, cellSize, textures[2]));
	
	for (int i = 0; i < rows; i++) {
		cells[i] = new sf::Sprite[cols];
		for (int j = 0; j < cols; j++) {
			cells[i][j].setTexture(textures[1]);
			cells[i][j].setPosition(j * cellSize, i * cellSize);
		}
	}
}

Grid::~Grid()
{
	for (int i = 0; i < rows; i++) {
		delete[] cells[i];
	}
	delete[] cells;
}

void Grid::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			window.draw(cells[i][j]);
		}
	}
	for(Cheese cheese : CheeseList) {
		window.draw(cheese.cell);
	}
	for (Ratz ratz : snake.snake) {
		window.draw(ratz.cell);
	}
}

sf::Sprite Grid::getCell(int row, int col)
{
	return cells[row][col];
}

int Grid::getRows()
{
	return rows;
}

int Grid::getCols()
{
	return cols;
}