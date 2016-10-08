#include "GameController.h"

GameController::GameController() {
	gmtl::Point3f upLeftCorner = gmtl::Point3f(0, 0, 0);
	gmtl::Point3f downRightCorner = gmtl::Point3f(400, 240, 0);
	playingField = gmtl::AABoxf(upLeftCorner, downRightCorner);
	player1 = Pad1();
	player2 = Pad2();
	ball = Ball();
}

void GameController::Update(float deltaTime)
{
	player1.Update(deltaTime);
	player2.Update(deltaTime);
	ball.Update(deltaTime);	
	if (gmtl::intersect(player1.getBox(), ball.getSphere()))
	{
		ball.reverseDirection();
	}
	else if (gmtl::intersect(player2.getBox(), ball.getSphere()))
	{
		ball.reverseDirection();
	}

}

int GameController::getBallX()
{
	return ball.getX();
}

int GameController::getBallY()
{
	return ball.getY();
}

int GameController::getPad1X()
{
	return player1.getX();
}

int GameController::getPad1Y()
{
	return player1.getY();
}

int GameController::getPad1Width()
{
	return player1.getWidth();
}

int GameController::getPad1Length()
{
	return player1.getLength();
}

int GameController::getPad2X()
{
	return player2.getX();
}

int GameController::getPad2Y()
{
	return player2.getY();
}

int GameController::getPad2Width()
{
	return player2.getWidth();
}

int GameController::getPad2Length()
{
	return player2.getLength();
}




