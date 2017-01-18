#include "PongvsAI.h"
#include "SplashScreen.h"

PongvsAI::PongvsAI(StateManager &manager) : Pong(manager)
{
	controller.AIenabled = true;
}


PongvsAI::~PongvsAI()
{
}


void PongvsAI::updateGame()
{
	if (KEY_DOWN & keysCurrent()) {
		controller.movePaddle1(ponglogic::down);
	}
	else if (KEY_UP & keysCurrent()) {
		controller.movePaddle1(ponglogic::up);
	}
	else if (KEY_SELECT & keysDown())
	{
		changeState(new SplashScreen(manager));
	}
	else
		controller.movePaddle1(ponglogic::neutral);

	bal.setPosition(controller.getBallX(), controller.getBallY());
	p1Paddle.setPosition(controller.getPad1X() + (controller.getPad1Width() / 2), controller.getPad1Y() + (controller.getPad1Length() / 2));
	p2Paddle.setPosition(controller.getPad2X() + (controller.getPad2Width() / 2), controller.getPad2Y() + (controller.getPad2Length() / 2)); //update game with local values as it's the host
}
