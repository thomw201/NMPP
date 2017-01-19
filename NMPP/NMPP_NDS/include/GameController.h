#pragma once
#include "GameObject.h"
#include <vector>
#include <gmtl\gmtl.h>
#include <string>
#include <sstream>

using namespace std;
/**
*@GameController Handles the Logic of the Game.
*/
class GameController {
private:
	Pad player1;
	Pad player2;
	Ball ball;
	Mode mode;
	void moveAutoMove(Pad &paddle);
public:
	vector<GameObject> gameObjects;
	GameController();
	void Update(float deltaTime);
	void movePaddle1(Direction direction);
	void movePaddle2(Direction direction);
	string getGameState();
	string getp2State();
	void syncGameState(string state);
	void syncPaddleState(string state);
	void setMode(Mode mode);
	int getBallX();
	int getBallY();
	int getPad1X();
	int getPad1Y();
	int getPad1Width();
	int getPad1Length();
	int getPad2X();
	int getPad2Y();
	int getPad2Width();
	int getPad2Length();
	int getScore1();
	int getScore2();
};