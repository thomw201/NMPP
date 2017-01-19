#pragma once
#include "GameState.h"
#include "GameController.h"
#include "com.h"
#include "paddle.h"
#include "ball.h"
#include <stdio.h>

class Pong : public GameState
{
public:
	Pong(StateManager &manager);
	~Pong();

	// Inherited via GameState
	virtual void update(float deltaTime) override;
private:
	void initBackgrounds();
protected:
	// Inherited via GameState
	virtual void changeState(GameState * nextState) override;
	virtual void updateGame() = 0;
	GameController controller;
	com communication;
	paddle p1Paddle;
	paddle p2Paddle;
	ball bal;
	touchPosition Stylus;
	bool isP1;
};

