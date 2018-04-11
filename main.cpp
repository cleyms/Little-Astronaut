#include <iostream>
#include <SFML/Graphics.hpp>

#include "entities.hpp"

using namespace std;
using namespace sf;

int main(int argc, char *argv[]){
	int leftRight;
	int downUp;

	TextureSet p1TextureSet_walk({
		"sprites/player/walk/walk (1).png",
		"sprites/player/walk/walk (2).png",
		"sprites/player/walk/walk (3).png",
		"sprites/player/walk/walk (4).png",
		"sprites/player/walk/walk (5).png",
		"sprites/player/walk/walk (6).png",
		"sprites/player/walk/walk (7).png",
		"sprites/player/walk/walk (8).png"
	});

	Animation p1Animation({
		"sprites/player/walk/walk (1).png",
		"sprites/player/walk/walk (2).png",
		"sprites/player/walk/walk (3).png",
		"sprites/player/walk/walk (4).png",
		"sprites/player/walk/walk (5).png",
		"sprites/player/walk/walk (6).png",
		"sprites/player/walk/walk (7).png",
		"sprites/player/walk/walk (8).png"
	});
	Player p1(&p1Animation);
	p1.setPos(0, -200);

	RenderWindow window(VideoMode(500, 500), "First SFML!");
	window.setFramerateLimit(60);

	while(window.isOpen()){
		Event event;
		while(window.pollEvent(event)){
			if(event.type == Event::Closed)
				window.close();
		}

		leftRight = (Keyboard::isKeyPressed(Keyboard::Right)-Keyboard::isKeyPressed(Keyboard::Left));
		downUp = (Keyboard::isKeyPressed(Keyboard::Down)-Keyboard::isKeyPressed(Keyboard::Up));
		
		p1Animation.play();

		window.clear();
		window.draw(p1Animation.sprite);
		window.display();
		p1.setPos(p1.getX()+p1.getSpeed()*leftRight, p1.getY()+p1.getSpeed()*downUp);
	}
	return 0;
}
