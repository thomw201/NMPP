#pragma once

//#include <3ds.h>
#include <sf2d.h>

//Score assets
#include "ScoreAssets\Zero.c"
#include "ScoreAssets\One.c"
#include "ScoreAssets\Two.c"
#include "ScoreAssets\Three.c"
#include "ScoreAssets\Four.c"
#include "ScoreAssets\Five.c"
#include "ScoreAssets\Six.c"
#include "ScoreAssets\Seven.c"
#include "ScoreAssets\Eight.c"
#include "ScoreAssets\Nine.c"


/**
*@The score manager.
*/
class ScoreManager {
private:
	sf2d_texture *scoreNumbers[10];

public:
	ScoreManager();
	~ScoreManager();
	void drawScore(int score1, int score2);

private:

	
};