#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "RequestManager.h"
#include "SpriteManager.h"
#include <iostream>
#include "Grid.h"

int main()
{
	// Charger les textures pour les images des cellules
	std::vector<sf::Texture> textures;
	textures.push_back(SpriteManager::loadTexture("Assets/Sprites/BlueContainer.png"));
	textures.push_back(SpriteManager::loadTexture("Assets/Sprites/background.jpg"));
	textures.push_back(SpriteManager::loadTexture("Assets/Sprites/cheese.png"));
	textures.push_back(SpriteManager::loadTexture("Assets/Sprites/Rat_bagarreur_sprite.png"));
	textures.push_back(SpriteManager::loadTexture("Assets/Sprites/Rat_noir_sprite.png"));

	// Créer la grille
	int rows = 20, cols = 20, cellSize = 40;
	Snake currentSnake(cellSize, textures);
	Grid grid(rows, cols, cellSize, textures);

	sf::RenderWindow window(sf::VideoMode(cols * cellSize, rows * cellSize), "RATZ Project");

	// Musique
	sf::Music music;
	if (!music.openFromFile("Assets/Sprites/PASDPANIK.ogg"))
		return -1;
		
	music.setVolume(25.f);
	music.play();
	music.setLoop(true);

	// Créer le RequestManager
	RequestManager reqManager;

	//Variables du jeu
	bool GameOver = false;
	bool scoreSubmitted = false;

	//Création du texte pour l'input des scores
	sf::String playerInput;
	sf::Text playerText;
	sf::Font TextFont;
	if (!TextFont.loadFromFile("Assets/Fonts/FORCED_SQUARE.ttf"))
	{
		std::cout << "error";
	}
	playerText.setPosition(200, 300);
	playerText.setCharacterSize(24);
	playerText.setFillColor(sf::Color::White);
	playerText.setString("Enter your name: ");
	playerText.setFont(TextFont);




	//Enum pour les directions
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
				if (GameOver)
				{
					break;
				}
				MyVector direction{};
				if ((event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Q) && currentSnake.direction.x != 1)
				{
					currentSnake.LookDirection(Left);
				}
				else if ((event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D) && currentSnake.direction.x != -1)
				{
					currentSnake.LookDirection(Right);
				}
				else if ((event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Z) && currentSnake.direction.y != 1)
				{
					currentSnake.LookDirection(Up);
				}
				else if ((event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S) && currentSnake.direction.y != -1)
				{
					currentSnake.LookDirection(Down);
				}
			}

			if (event.type == sf::Event::TextEntered)
			{
				if (!GameOver or scoreSubmitted)
				{
					break;
				}

				if (event.text.unicode == 8)
				{
					playerInput = playerText.getString();
					if (playerInput.getSize() <= 17) { break; }
					playerInput.erase(playerInput.getSize() - 1, 1);
					playerText.setString(playerInput);
					break;
				}

				if (event.text.unicode == 13)
				{
					std::string pseudo = (std::string)playerText.getString().toAnsiString();
					pseudo.erase(0, 6);
					reqManager.NewScore(pseudo, currentSnake.snake.size());

					playerText.setString(reqManager.Scorelist());
					scoreSubmitted = true;
					break;
				}

				if (event.text.unicode < 128)
				{
					playerInput = playerText.getString();
					playerInput += event.text.unicode;
					playerText.setString(playerInput);
				}
			}
		}
		window.clear();

		if (!GameOver)
		{
			grid.draw(window);
			currentSnake.draw(window);
		}
		else
		{
			window.draw(playerText);
		}
		window.display();
		if (!GameOver) {
			currentSnake.Move();
			currentSnake.CheckDeath(GameOver);
			currentSnake.Eat(grid.CheeseList);
		}
		sf::sleep(sf::milliseconds(75));
	}
	return 0;
}
