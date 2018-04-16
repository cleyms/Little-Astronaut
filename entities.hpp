#ifndef ENTITIES
#define ENTITIES

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

typedef struct TextureSet{
	vector<Texture> textures;
	TextureSet(string path, int size);
} TextureSet;

typedef struct Animation{
	int frame;
	int speed;
	int tick;
	vector<Texture> textures;
	Sprite sprite;
	
	Animation(TextureSet textureSet);
	void play();
	void setPos(int x, int y);
	void setSpeed(int speed);
} Animation;

class Player{
	private:
		int x, y;
		int speed;
		bool dir;
		Animation *animation;
	public:
		Player(Animation *animation);
		void setAnimation(Animation *animation);
		void playAnimation(RenderWindow *window);
		void setPos(int x, int y);
		void setDir(bool dir);
		int getX();
		int getY();
		int getSpeed();
};

#endif