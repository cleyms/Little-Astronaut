#include "game.hpp"

//###################
//	CLASS GAME
//###################

//PUBLIC

Game::Game(): 
window(sf::VideoMode(900, 600), "Little Astronaut"){
	timePerFrame = sf::seconds(1.f/60.f);
}
void Game::run(){
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while(window.isOpen()){
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while(timeSinceLastUpdate > timePerFrame){
			timeSinceLastUpdate -= timePerFrame;
			processEvents();
			update(timePerFrame);
		}
		render();
	}

}

//PRIVATE

void Game::processEvents(){
//
}
void Game::update(sf::Time pTimePerFrame){
//
}
void Game::render(){
	window.clear();
	//window.draw(...)
	window.display();
}