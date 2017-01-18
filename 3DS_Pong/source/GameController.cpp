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
GameController::GameController() 
{ 
	mode = solo;
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
	if (mode == solo)
	{
		moveAutoMove(player2);
	}
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

string GameController::getGameState()
{
	std::stringstream finaltext;
	finaltext << "gamep1:" << getPad1X()<<","<<getPad1Y()<<","<<getBallX()<<","<<getBallY();
	return finaltext.str();
}

string GameController::getp2State()
{
	std::stringstream finaltext;
	finaltext << "gamep2:" << getPad2X() << "," << getPad2Y();
	return finaltext.str();
}

void GameController::syncGameState(string state)
{
	if (state.substr(0, 6) == "gamep1")
	{
		std::stringstream stream(state.substr(7, state.length() -7));
		int i, count;
		count = 0;
		int coords[4];

		while (stream >> i)
		{
			coords[count] = i;
			count++;
			if (stream.peek() == ',')
				stream.ignore();
		}
		player1.setX(coords[0]);
		player1.setY(coords[1]);
		ball.setX(coords[2]);
		ball.setY(coords[3]);
	}
	
}

void GameController::syncPaddleState(string state)
{
	if (state.substr(0, 6) == "gamep2")
	{
		std::stringstream stream(state.substr(7, state.length() - 7));
		int i, count;
		count = 0;
		int coords[2];

		while (stream >> i)
		{
			coords[count] = i;
			count++;
			if (stream.peek() == ',')
				stream.ignore();
		}
		player2.setX(coords[0]);
		player2.setY(coords[1]);
	}
}

void GameController::setMode(Mode mode)
{
	this->mode = mode;
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




