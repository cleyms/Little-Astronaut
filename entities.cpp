#include "entities.hpp"

//TextureSet struct
TextureSet::TextureSet(string path, int size){
	int i = 1;
	for(; i<size+1; i++){
		cout<<"Loading "<<path<<" ("<<i<<").png"<<endl;
		Texture foo;
		foo.loadFromFile(path+" ("+to_string(i)+").png");
		this->textures.push_back(foo);
	}
}

//Animation struct
Animation::Animation(TextureSet textureSet){
	//Init variables
	this->oX = 0;
	this->oY = 0;
	this->frame = 0;
	this->tick = 0;
	this->speed = 200; //per 1000ticks
	//Load textures
	this->textures = textureSet.textures;
	this->sprite.setTexture(textures[0]);
}
void Animation::play(){
	this->tick++;
	this->tick %= 1000;
	if(this->tick % (1000/this->speed) == 0){
		this->frame += 1;
		this->frame %= textures.size();
	}
	this->sprite.setTexture(textures[frame]);
}
void Animation::setPos(int x, int y){
	this->sprite.setPosition(x, y);
}
void Animation::setSpeed(int speed){
	this->speed = speed;
}

//Animation struct
Hitbox::Hitbox(){
	this->x = 0;
	this->y = 0;
	this->width = 0;
	this->height = 0;
}
Hitbox::Hitbox(int x, int y, int width, int height){
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}
void Hitbox::draw(RenderWindow *window){
	RectangleShape rectangle;
	rectangle.setOutlineColor(Color::White);
	rectangle.setSize(Vector2f(this->width, this->height));
	rectangle.setPosition(this->x, this->y);
	window->draw(rectangle);
}

//Player class
Player::Player(Animation *animation, int width, int height){
	this->animation = animation;
	this->width = width;
	this->height = height;
	this->dir = true;
	this->speed = 5;
	Hitbox htbx = Hitbox(this->x, this->y, this->width, this->height);
	this->hitbox = htbx;
}
void Player::setAnimation(Animation *animation){
	if(this->animation != animation)
		this->animation = animation;
}
void Player::playAnimation(RenderWindow *window){
	this->animation->play();
	if(this->dir){
		this->animation->sprite.setScale(1, 1);
		this->animation->setPos(this->getX()+this->animation->oX, this->animation->oY+this->getY());
	}else{
		this->animation->sprite.setScale(-1, 1);
		this->animation->setPos(this->getX()+this->width-this->animation->oX, this->animation->oY+this->getY());
	}
	window->draw(this->animation->sprite);
}
void Player::setPos(int x, int y){
	this->hitbox.x = x;
	this->hitbox.y = y;
	this->animation->setPos(x, y);
}
void Player::setDir(bool dir){
	this->dir = dir;
}
int Player::getX(){
	return this->hitbox.x;
}
int Player::getY(){
	return this->hitbox.y;
}
int Player::getSpeed(){
	return this->speed;
}
Hitbox *Player::getHitbox(){
	return &this->hitbox;
}