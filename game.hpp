#ifndef GAME
#define GAME

#include <iostream>
#include <SFML/Graphics.hpp>

#include "entities.hpp"
#include "world.hpp"

class Game{
public:
	Game();
	void run();
private:
	void processEvents();
	void update();
	void render();

	sf::RenderWindow window;
};

#endif //GAME