#pragma once
#include "GameState.h"
#include "GameController.h"
#include "com.h"
#include "paddle.h"
#include "ball.h"
#include <string.h>
#include <nf_lib.h>
#include <stdio.h>

class Pong : public GameState
{
public:
	Pong(StateManager &manager);
	~Pong();

	// Inherited via GameState
	virtual void update(float deltaTime) override;
private:
	// Inherited via GameState
	virtual void changeState(GameState * nextState) override;
	void initBackgrounds();
protected:
	virtual void updateGame() = 0;
	ponglogic::GameController controller;
	com communication;
	paddle p1Paddle;
	paddle p2Paddle;
	ball bal;
	touchPosition Stylus;
};

