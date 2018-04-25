#ifndef WORLD
#define WORLD

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Camera{
private:
	int x, y;
	int zoom;
	RenderWindow *window;
public:
	Camera(RenderWindow *window);
	RenderWindow *getWindow();
};

class Level{
private:
	int width;
	vector<int> map;
public:
	Level(int width);
	void setMap(vector<int> map);
};

#endif //WORLD