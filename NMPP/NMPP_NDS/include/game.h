#include "GameController.h"
#include "GameObject.h"
#include "com.h"
#include "paddle.h"
#include "ball.h"
#include "GameController.h"
#include "GameObject.h"
#pragma once
class game
{
public:
	game();
	game(int screen);
	~game();
	void run(int gamemode);
	void vsAI();
	void isHost();
	void isClient();
	void show();
	void hide();
private:
	com communication;
	GameController controller;
	paddle p1Paddle;
	paddle p2Paddle;
	ball bal;
	touchPosition Stylus;	// variable for Stylus data
	void controlP1();
	void update();
};

