#pragma once
class ball
{
public:
	ball(int _id, int _screen, int _posX, int _posY);
	~ball();
	void create();
	void setSize(int _width, int _height);
	void setX(int _posX);
	void setY(int _posY);
	int getWidth();
	int getHeight();
	int getX();
	int getY();
private:
	int id, screen, posX, posY, width, height;
};

