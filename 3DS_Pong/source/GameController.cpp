#include "GameController.h"
void GameController::moveAutoMove(Pad &paddle)
{
	if (ball.getY() + 10 > paddle.getY() + paddle.getLength() / 2 && ball.getY()  - 10 < paddle.getY() + paddle.getLength() / 2)
	{
		paddle.setDirection(neutral);
	}
	else if (ball.getY() > paddle.getY() + paddle.getLength() / 2)
	{
		paddle.setDirection(down);
	}
	else if (ball.getY()  < paddle.getY() + paddle.getLength() / 2)
	{
		paddle.setDirection(up);
	}
}
/**
* This will handle the game logic of PONG!!
*/
GameController::GameController() {
	player1 = Pad(true);
	player2 = Pad(false);
	ball = Ball();
}


/**
* This function updates Pong game.
* @param deltaTime the time is the time difference between each Update call.
*/
void GameController::Update(float deltaTime)
{
	moveAutoMove(player2);
	player1.Update(deltaTime);
	player2.Update(deltaTime);
	ball.Update(deltaTime);	
	if (gmtl::intersect(player1.getBox(), ball.getSphere()))//Check for collition.
	{		
		ball.reverseDirection((ball.getY() - player1.getCenterY()) / (playingField.padHeight / 2) * 100);//calculation for the ball ricochet angle.
	}
	else if (gmtl::intersect(player2.getBox(), ball.getSphere()))
	{
		ball.reverseDirection((ball.getY() - player2.getCenterY()) / (playingField.padHeight / 2) * 100);
	}

}

/**
* This function moves player1 paddle
* @param direction is the direction you want to move the paddle
*/
void GameController::movePaddle1(Direction direction)
{
	player1.setDirection(direction);
}

/**
* This function moves player2 paddle
* @param direction is the direction you want to move the paddle
*/
void GameController::movePaddle2(Direction direction)
{
	player2.setDirection(direction);
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

int GameController::getScore1()
{
	return ball.getScore1();
}

int GameController::getScore2()
{
	return ball.getScore2();
}




