#pragma once
#include "GameObject.h"
#include <vector>
#include <gmtl\gmtl.h>

using namespace std;
/**
*@GameController Handles the Logic of the Game.
*/
class GameController {
private:
	gmtl::AABoxf playingField;
	Pad1 player1;
	Pad2 player2;
	Ball ball;
public:
	vector<GameObject> gameObjects;
	GameController();
	void Update(float deltaTime);
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
};