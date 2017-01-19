#include "PongvsAI.h"
#include "SplashScreen.h"

PongvsAI::PongvsAI(StateManager &manager) : Pong(manager)
{
	controller.setMode(solo);
	isP1 = true;
}


PongvsAI::~PongvsAI()
{
}


void PongvsAI::updateGame()
{

	bal.setPosition(controller.getBallX(), controller.getBallY());
	p1Paddle.setPosition(controller.getPad1X() + (controller.getPad1Width() / 2), controller.getPad1Y() + (controller.getPad1Length() / 2));
	p2Paddle.setPosition(controller.getPad2X() + (controller.getPad2Width() / 2), controller.getPad2Y() + (controller.getPad2Length() / 2)); //update game with local values as it's the host
}
