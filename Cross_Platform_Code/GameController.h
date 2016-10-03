#pragma once
#include <vector>
#include "GameObject.h"

using namespace std;
/**
*@GameController Handles the Logic of the Game.
*/
class GameController {

public:
	vector<GameObject> gameObjects;
	void GameController();
	void Update(float deltaTime);

};