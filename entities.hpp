#ifndef ENTITIES
#define ENTITIES

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

#include "world.hpp"

typedef struct TextureSet{
	vector<Texture> textures;
	TextureSet(string path, int size);
} TextureSet;

typedef struct Animation{
	int oX, oY;
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

typedef struct Hitbox{
	int x, y;
	int width, height;
	bool hitted;

	Hitbox();
	Hitbox(int x, int y, int width, int height);
	void draw(Camera *camera);
} Hitbox;

class Player{
	private:
		int x, y;
		int width, height;
		int speed;
		bool dir;
		Hitbox hitbox;
		Animation *animation;
	public:
		Player(Animation *animation, int width, int height);
		void setAnimation(Animation *animation);
		void playAnimation(RenderWindow *window);
		void setPos(int x, int y);
		void setDir(bool dir);
		int getX();
		int getY();
		int getSpeed();
		Hitbox *getHitbox();
};

#endif