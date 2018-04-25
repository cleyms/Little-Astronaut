#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

#include "world.hpp"
#include "entities.hpp"

int main(int argc, char *argv[]){
	//Basics vaiables
	int leftRight;
	int downUp;

	//Main player init
	TextureSet p1TextureSet_walk("sprites/player/walk/walk", 8);
	TextureSet p1TextureSet_idle("sprites/player/idle/idle", 4);

	Animation p1Animation_walk(p1TextureSet_walk);
	Animation p1Animation_idle(p1TextureSet_idle);
	
	p1Animation_idle.oX = -25;
	p1Animation_idle.oY = -160;

	p1Animation_walk.oX = -25;
	p1Animation_walk.oY = -160;

	p1Animation_idle.speed = 100;

	Player p1(&p1Animation_walk, 120, 190);
	p1.setPos(0, 0);

	//Init window
	RenderWindow window(VideoMode(1200, 900), "Little astronaut");
	window.setFramerateLimit(60);

	//Init camera
	Camera camera(&window);

	//Mainloop
	while(window.isOpen()){
		Event event;
		while(window.pollEvent(event)){
			if(event.type == Event::Closed)
				window.close();
		}

		//Keyboard update
		leftRight = (Keyboard::isKeyPressed(Keyboard::Right)-Keyboard::isKeyPressed(Keyboard::Left));
		downUp = (Keyboard::isKeyPressed(Keyboard::Down)-Keyboard::isKeyPressed(Keyboard::Up));

		//Control player
		if(leftRight){
			p1.setAnimation(&p1Animation_walk);
			if(leftRight > 0)
				p1.setDir(true);
			else
				p1.setDir(false);
		}else{
			p1.setAnimation(&p1Animation_idle);
		}
		p1.setPos(p1.getX()+p1.getSpeed()*leftRight, p1.getY()+p1.getSpeed()*downUp);

		//Updating screen
		window.clear();
		p1.getHitbox()->draw(&camera);
		p1.playAnimation(&window);
		window.display();
	}
	return 0;
}
