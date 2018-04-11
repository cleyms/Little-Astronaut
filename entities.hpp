#ifndef ENTITIES
#define ENTITIES

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

typedef struct TextureSet{
	vector<Texture> textures;
	TextureSet(vector<string> paths);
} TextureSet;

typedef struct Animation{
	int frame;
	int speed;
	int tick;
	int x;
	int y;
	vector<Texture> textures;
	Sprite sprite;
	
	Animation(vector<string> paths);
	void play();
	void setPos(int x, int y);
} Animation;

class Player{
	private:
		int x;
		int y;
		int speed;
		Animation *animation;
	public:
		Player(Animation *animation);
		void setPos(int x, int y);
		int getX();
		int getY();
		int getSpeed();
};



#endif