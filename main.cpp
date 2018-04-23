#include <iostream>
#include <SFML/Graphics.hpp>

#include "entities.hpp"

using namespace std;
using namespace sf;

int main(int argc, char *argv[]){
	int leftRight;
	int downUp;

	TextureSet p1TextureSet_walk("sprites/player/walk/walk", 8);
	TextureSet p1TextureSet_idle("sprites/player/idle/idle", 4);

	Animation p1Animation_walk(p1TextureSet_walk);
	Animation p1Animation_idle(p1TextureSet_idle);
	p1Animation_idle.speed = 100;

	Player p1(&p1Animation_walk);
	p1.setPos(0, -200);
	p1.setSize(1.5);

	RenderWindow window(VideoMode(900, 600), "Little astronaut");
	window.setFramerateLimit(60);

	while(window.isOpen()){
		Event event;
		while(window.pollEvent(event)){
			if(event.type == Event::Closed)
				window.close();
		}

		leftRight = (Keyboard::isKeyPressed(Keyboard::Right)-Keyboard::isKeyPressed(Keyboard::Left));
		downUp = (Keyboard::isKeyPressed(Keyboard::Down)-Keyboard::isKeyPressed(Keyboard::Up));

		if(leftRight){
			p1.setAnimation(&p1Animation_walk);
			if(leftRight > 0)
				p1.setDir(true);
			else
				p1.setDir(false);
		}else{
			p1.setAnimation(&p1Animation_idle);
		}

		window.clear();
		p1.playAnimation(&window);
		window.display();

		p1.setPos(p1.getX()+p1.getSpeed()*leftRight, p1.getY()+p1.getSpeed()*downUp);
	}
	return 0;
}
