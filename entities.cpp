#include "entities.hpp"

//TextureSet struct
TextureSet::TextureSet(vector<string> paths){
	int i = 0;
	for(; i<paths.size(); i++){
		cout<<"Loading "<<paths[i]<<endl;
		Texture foo;
		foo.loadFromFile(paths[i]);
		textures.push_back(foo);
	}
}

//Animation struct
Animation::Animation(vector<string> paths){
	//Init variables
	frame = 0;
	tick = 0;
	speed = 200; //per 1000ticks
	x = 0;
	y = 0;
	//Load textures
	int i = 0;
	for(; i<paths.size(); i++){
		cout<<"Loading "<<paths[i]<<endl;
		Texture foo;
		foo.loadFromFile(paths[i]);
		textures.push_back(foo);
	}
	sprite.setTexture(textures[0]);
}
void Animation::play(){
	tick++;
	tick %= 1000;
	if(tick % (1000/speed) == 0){
		frame += 1;
		frame %= textures.size();
	}
	sprite.setTexture(textures[frame]);
	sprite.setScale(2, 2);
}
void Animation::setPos(int x, int y){
	sprite.setPosition(x, y);
}

//Player class
Player::Player(Animation *animation){
	this->animation = animation;
	this->x = 0;
	this->y = 0;
	this->speed = 5;
}
void Player::setPos(int x, int y){
	this->x = x;
	this->y = y;
	animation->setPos(this->x, this->y);
}
int Player::getX(){
	return this->x;
}
int Player::getY(){
	return this->y;
}
int Player::getSpeed(){
	return this->speed;
}
