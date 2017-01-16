#include "ball.h"
#include "nf_lib.h"
#include "GameObject.h"


ball::ball(int _id, int _screen, int _posX, int _posY)
{
	id = _id;
	screen = _screen;
	posX = _posX;
	posY = _posY;
	width = 16; //ball size is 16x16 (lol)
	height = 16;
}

ball::ball()
{
	width = 16; //ball size is 16x16 (lol)
	height = 16;
}

ball::~ball()
{
	NF_DeleteSprite(screen, id);
	NF_FreeSpriteGfx(screen, id);
	NF_UnloadSpritePal(id);
}

int ball::getY() {
	return posY;
}

int ball::getX() {
	return posX;
}

int ball::getHeight() {
	return height;
}

int ball::getWidth() {
	return width;
}

void ball::setPosition(int _posX, int _posY) {
	_posX = _posX - ponglogic::playingField.ballRadius;
	_posY = _posY - ponglogic::playingField.ballRadius;
	posX = _posX;
	posY = _posY;
	NF_MoveSprite(screen, id, posX, posY);
}

/* change the size of the sprite */
void ball::setSize(int _width, int _height) {
	width = _width;
	height = _height;
	create();
	//todo: resize the sprite?
}

/* moves the paddle to the given X position */
void ball::setX(int _posX) {
	posX = _posX;
	NF_MoveSprite(screen, id, posX, posY);
}

/* moves the paddle to the given Y position */
void ball::setY(int _posY) {
	posY = _posY;
	NF_MoveSprite(screen, id, posX, posY);
}

void ball::setID(int _id)
{
	id = _id;
}

/* creates the paddle on the posX, posY position */
void ball::create() {
	NF_LoadSpriteGfx("game/sprites/ballImg", id, width, height);	// load paddle sprite
	NF_LoadSpritePal("game/sprites/ballImg", id);

	NF_VramSpriteGfx(screen, id, id, false);	// Load the Gfx into VRAM - transfer all Sprites
	NF_VramSpritePal(screen, id, id);		// Load the Palette into VRAM

	NF_CreateSprite(screen, id, id, id, posX, posY);		//create paddle 5% from the border and in the middle of the screen (vertically)
}