#include "world.hpp"

//Camera class
Camera::Camera(RenderWindow *window){
	this->window = window;
}
RenderWindow *Camera::getWindow(){
	return this->window;
}

//Level class
Level::Level(int width){
	this->width = width;
}
void Level::setMap(vector<int> map){
	this->map = map;
}