#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grid.h"
#include "SpriteManager.h"

int main()
{
	// Charger les textures pour les images des cellules
	std::vector<sf::Texture> textures;
	textures.push_back(SpriteManager::loadTexture("Assets/Sprites/BlueContainer.png"));
	textures.push_back(SpriteManager::loadTexture("Assets/Sprites/GreenContainer.png"));
	textures.push_back(SpriteManager::loadTexture("Assets/Sprites/cheese.png"));
	textures.push_back(SpriteManager::loadTexture("Assets/Sprites/Rat_bagarreur_sprite.png"));



	// Cr�er les sprites

	// Cr�er la grille
	int rows = 20, cols = 20, cellSize = 40;
	Grid grid(rows, cols, cellSize, textures);

	sf::RenderWindow window(sf::VideoMode(cols * cellSize, rows * cellSize), "RATZ Project");


	while (window.isOpen())
	{
		// Gestion des �v�nements
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Left && currentSnake.direction.x != 1)
				{
					currentSnake.direction = MyVector(-1, 0);
				}
				else if (event.key.code == sf::Keyboard::Right && currentSnake.direction.x != -1)
				{
					currentSnake.direction = MyVector(1, 0);
				}
				else if (event.key.code == sf::Keyboard::Up && currentSnake.direction.y != 1)
				{
					currentSnake.direction = MyVector(0, -1);
				}
				else if (event.key.code == sf::Keyboard::Down && currentSnake.direction.y != -1)
				{
					currentSnake.direction = MyVector(0, 1);
				}
			}
			//check ou on est
				// move
			// check eat
				// si eat, > rat++
			// si c'est un rat, c'est ciao
		}

		// Dessine la grille avec les images altern�es
		window.clear();
		
		grid.draw(window);
		window.display();
	}

	return 0;
}
