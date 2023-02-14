#include "Grid.h"

Grid::Grid(int rows, int cols, int cellSize)
{
	this->rows = rows;
	this->cols = cols;
	this->cellSize = cellSize;

	cells = new sf::RectangleShape * [rows];
	for (int i = 0; i < rows; i++) {
		cells[i] = new sf::RectangleShape[cols];
		for (int j = 0; j < cols; j++) {
			cells[i][j].setSize(sf::Vector2f(cellSize, cellSize));
			cells[i][j].setOutlineThickness(1);
			cells[i][j].setOutlineColor(sf::Color::Black);
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
}

void Grid::setCell(int row, int col, bool state)
{
	cells[row][col].setFillColor(state ? sf::Color::Black : sf::Color::White);
}

bool Grid::getCell(int row, int col)
{
	return cells[row][col].getFillColor() == sf::Color::Black;
}

int Grid::getRows()
{
	return rows;
}

int Grid::getCols()
{
	return cols;
}