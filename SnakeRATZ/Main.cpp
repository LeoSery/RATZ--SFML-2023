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



	// Créer les sprites

	// Créer la grille
	int rows = 20, cols = 20, cellSize = 40;
	Snake currentSnake(cellSize, textures);
	Grid grid(rows, cols, cellSize, textures);

	sf::RenderWindow window(sf::VideoMode(cols * cellSize, rows * cellSize), "RATZ Project");

	enum directions { Left = 0, Right = 1, Up = 2, Down = 3 };

	while (window.isOpen())
	{
		// Gestion des événements
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				MyVector direction{};
				if (event.key.code == sf::Keyboard::Left && currentSnake.direction.x != 1)
				{
					currentSnake.LookDirection(Left);
				}
				else if (event.key.code == sf::Keyboard::Right && currentSnake.direction.x != -1)
				{
					currentSnake.LookDirection(Right);
				}
				else if (event.key.code == sf::Keyboard::Up && currentSnake.direction.y != 1)
				{
					currentSnake.LookDirection(Up);
				}
				else if (event.key.code == sf::Keyboard::Down && currentSnake.direction.y != -1)
				{
					currentSnake.LookDirection(Down);
				}
			}
		}

		// Dessine la grille avec les images alternées
		window.clear();
		
		grid.draw(window);
		currentSnake.draw(window);
		window.display();
		currentSnake.Move();
		sf::sleep(sf::milliseconds((150)));
	}

	return 0;
}
