#ifndef GAME
#define GAME

#include <iostream>
#include <SFML/Graphics.hpp>

class Game{
public:
	Game();
	void run();
private:
	void processEvents();
	void update(sf::Time pTimePerFrame);
	void render();

	sf::RenderWindow window;
	sf::Time timePerFrame;
};

#endif //GAME