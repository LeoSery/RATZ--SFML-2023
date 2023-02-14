#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grid.h"
#include "SpriteManager.h"

int main()
{
	// Charger les textures pour les images des cellules
	sf::Texture blueContainerTexture, greenContainerTexture;
	blueContainerTexture = SpriteManager::loadTexture("./Assets/Sprites/BlueContainer.png");
	greenContainerTexture = SpriteManager::loadTexture("./Assets/Sprites/GreenContainer.png");

	// Cr�er les sprites
	sf::Sprite blueContainerSprite, greenContainerSprite;
	blueContainerSprite.setTexture(blueContainerTexture);
	greenContainerSprite.setTexture(greenContainerTexture);

	// Cr�er la grille
	int rows = 20, cols = 20, cellSize = 40;
	Grid grid(rows, cols, cellSize);

	// Cr�er la fen�tre SFML
	sf::RenderWindow window(sf::VideoMode(cols * cellSize, rows * cellSize), "RATZ Project");

	// Boucle principale
	while (window.isOpen())
	{
		// Gestion des �v�nements
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Redimensionner les images pour qu'elles fassent la m�me taille que les cellules
		SpriteManager::resizeSprite(blueContainerSprite, cellSize);
		SpriteManager::resizeSprite(greenContainerSprite, cellSize);

		// Dessiner la grille avec les images altern�es
		window.clear();
		for (int row = 0; row < rows; row++)
		{
			for (int col = 0; col < cols; col++)
			{
				bool isBlue = (row + col) % 2 == 0;
				sf::Sprite& sprite = isBlue ? blueContainerSprite : greenContainerSprite;

				if (grid.getCell(row, col))
				{
					sprite.setPosition(col * cellSize, row * cellSize);
					window.draw(sprite);
				}
			}
		}
		grid.draw(window);
		window.display();
	}

	return 0;
}
