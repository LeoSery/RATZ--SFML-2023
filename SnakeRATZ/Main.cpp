#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grid.h"
#include "SpriteManager.h"

int main()
{
	// Charger les textures pour les images des cellules
	sf::Texture blueContainerTexture, greenContainerTexture;

	blueContainerTexture = SpriteManager::loadTexture("Assets/Sprites/BlueContainer.png");
	greenContainerTexture = SpriteManager::loadTexture("Assets/Sprites/GreenContainer.png");

	// Créer les sprites
	sf::Sprite blueContainerSprite, greenContainerSprite;
	blueContainerSprite.setTexture(blueContainerTexture);
	greenContainerSprite.setTexture(greenContainerTexture);

	// Créer la grille
	int rows = 20, cols = 20, cellSize = 40;
	Grid grid(rows, cols, cellSize);

	sf::RenderWindow window(sf::VideoMode(cols * cellSize, rows * cellSize), "RATZ Project");


	while (window.isOpen())
	{
		// Gestion des événements
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::Resized)
			{
				//// Redimensionne les images pour qu'elles fassent la même taille que les cellules
				//SpriteManager::resizeSprite(blueContainerSprite, cellSize);
				//SpriteManager::resizeSprite(greenContainerSprite, cellSize);
			}
		}

		// Dessine la grille avec les images alternées
		window.clear();
		for (int row = 0; row < rows; row++)
		{
			for (int col = 0; col < cols; col++)
			{
				bool isBlue = (row + col) % 2 == 0;
				sf::Sprite& sprite = isBlue ? blueContainerSprite : greenContainerSprite;
				sprite.setPosition(col * cellSize, row * cellSize);
				window.draw(sprite);
			}
		}
		window.display();
	}

	return 0;
}
