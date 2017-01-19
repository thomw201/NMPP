#include "nf_lib.h"
#include "GameObject.h"
#include "sprites.h"
#pragma once
class ball
{
public:
	ball(int _id, int _screen, int _posX, int _posY);
	ball();
	~ball();
	void create();
	void setSize(int _width, int _height);
	void setPosition(int _posX, int _posY);
	void setX(int _posX);
	void setY(int _posY);
	void setID(int _id);
	int getWidth();
	int getHeight();
	int getX();
	int getY();
private:
	int id, screen, posX, posY, width, height;
};

