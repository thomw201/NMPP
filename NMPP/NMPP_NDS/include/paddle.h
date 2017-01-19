#include "nf_lib.h"
#include "sprites.h"
#pragma once
class paddle
{
public:
	paddle(int _id, int _screen, int _posX, int _posY);
	paddle();
	~paddle();
	void create();
	void setPosition(int _posX, int posY);
	void setSize(int _width, int _height);
	void setX(int _posX);
	void setY(int _posY);
	void setID(int _id);
	void setSlot(int _slot);
	int getWidth();
	int getHeight();
	int getX();
	int getY();
private:
	int id, screen, posX, posY, width, height, slot;

};

