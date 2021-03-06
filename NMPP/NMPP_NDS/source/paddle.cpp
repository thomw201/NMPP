#include "paddle.h"



paddle::paddle(int _id, int _screen, int _posX, int _posY)
{
	id = _id;
	screen = _screen;
	posX = _posX;
	posY = _posY;
	width = 8; //default size of the paddle is 8x32
	height = 32;
}

paddle::paddle()
{

}



paddle::~paddle()
{
	//NF_DeleteSprite(screen, id);
	//NF_FreeSpriteGfx(screen, id);
	//NF_UnloadSpritePal(id);
}

int paddle::getY() {
	return posY;
}

int paddle::getX() {
	return posX;
}

int paddle::getHeight() {
	return height;
}

int paddle::getWidth() {
	return width;
}

void paddle::setPosition(int _posX, int _posY) {
	_posX = _posX - (getWidth() / 2);
	_posY = _posY - (getHeight() / 2);
	posX = _posX;
	posY = _posY;
	NF_MoveSprite(0, id, posX, posY);
}

/* change the size of the sprite */
void paddle::setSize(int _width, int _height) {
	width = _width;
	height = _height;
	//todo: resize the sprite?
}

/* moves the paddle to the given X position */
void paddle::setX(int _posX) {
	_posX = _posX - (getWidth() / 2);
	posX = _posX;
	NF_MoveSprite(screen, id, posX, posY);
}

/* moves the paddle to the given Y position */
void paddle::setY(int _posY) {
	_posY = _posY - (getHeight() / 2);
	posY = _posY;
	NF_MoveSprite(screen, id, posX, posY);
}

void paddle::setID(int _id)
{
	id = _id;
}

void paddle::setSlot(int _slot)
{
	slot = _slot;
}

/* creates the paddle on the posX, posY position */
void paddle::create() {
	NF_VramSpritePal(0, id, slot);		// Load the Palette into VRAM 
	NF_CreateSprite(0, id, id , slot, posX, posY);
	//NF_LoadSpriteGfx("game/sprites/paddleImg", id, width, height);	// load paddle sprite
	//NF_LoadSpritePal("game/sprites/paddleImg", id);

	//NF_VramSpriteGfx(screen, id, id, false);	// Load the Gfx into VRAM - transfer all Sprites
	//NF_VramSpritePal(screen, id, id);		// Load the Palette into VRAM

	//NF_CreateSprite(screen, id, id, id, posX, posY);		//create paddle 5% from the border and in the middle of the screen (vertically)
}