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
}
void Animation::setPos(int x, int y){
	sprite.setPosition(x, y);
}
void Animation::setSpeed(int speed){
	this->speed = speed;
}

//Animation struct
Hitbox::Hitbox(int x, int y, int width, int height){
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

//Player class
Player::Player(Animation *animation){
	this->animation = animation;
	this->x = 0;
	this->y = 0;
	this->width = this->animation->textures[0].getSize().x;
	this->height = this->animation->textures[0].getSize().y;
	this->dir = true;
	this->speed = 5;
	this->size = 1;
	Hitbox htbx = Hitbox(this->x, this->y, this->width, this->height);
	this->hitbox = &htbx;
}
void Player::setAnimation(Animation *animation){
	if(this->animation != animation)
		this->animation = animation;
}
void Player::playAnimation(RenderWindow *window){
	this->animation->play();
	if(this->dir){
		this->animation->sprite.setScale(this->size, this->size);
		this->animation->setPos(this->getX(), this->getY());
	}else{
		this->animation->sprite.setScale(-this->size, this->size);
		this->animation->setPos(this->getX()+this->width, this->getY());
	}
	window->draw(this->animation->sprite);
}
void Player::setPos(int x, int y){
	this->x = x;
	this->y = y;
	animation->setPos(x, y);
}
void Player::setSize(int size){
	this->size = size;
}
void Player::setDir(bool dir){
	this->dir = dir;
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
void Player::drawHitbox(RenderWindow *window){
	RectangleShape rectangle;
	int width = this->animation->textures[0].getSize().x;
	int height = this->animation->textures[0].getSize().y;
	rectangle.setOutlineColor(Color::White);
	rectangle.setSize(Vector2f(width, height));
	rectangle.setPosition(this->x, this->y);
	window->draw(rectangle);
}