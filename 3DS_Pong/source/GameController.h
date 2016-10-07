#pragma once
#include "GameObject.h"
#include <vector>

using namespace std;
/**
*@GameController Handles the Logic of the Game.
*/
class GameController {

public:
	vector<GameObject> gameObjects;
	GameController();
	void Update(float deltaTime);

};