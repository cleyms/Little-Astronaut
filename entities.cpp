#include "entities.hpp"

//TextureSet struct
TextureSet::TextureSet(string path, int size){
	int i = 1;
	for(; i<size+1; i++){
		cout<<"Loading "<<path<<" "<<i<<".png"<<endl;
		Texture foo;
		foo.loadFromFile(path+" ("+to_string(i)+").png");
		textures.push_back(foo);
	}
}

//Animation struct
Animation::Animation(TextureSet textureSet){
	//Init variables
	frame = 0;
	tick = 0;
	speed = 200; //per 1000ticks
	//Load textures
	textures = textureSet.textures;
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
void Animation::setSpeed(int speed){
	this->speed = speed;
}

//Player class
Player::Player(Animation *animation){
	this->animation = animation;
	this->x = 0;
	this->y = 0;
	this->speed = 5;
}
void Player::setAnimation(Animation *animation){
	this->animation = animation;
}
void Player::playAnimation(RenderWindow *window){
	this->animation->play();
	window->draw(this->animation->sprite);
}
void Player::setPos(int x, int y){
	this->x = x;
	this->y = y;
	animation->setPos(x, y);
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
