#ifndef HEADER_H
#define HEADER_H

#include <nf_lib.h>

const int singleplayerleftSpriteID = 0;
const int  multiplayerleftSpriteID = 1;
const int  optionsleftSpriteID = 2;
const int  singleplayerselectedleftSpriteID = 3;
const int  multiplayerselectedleftSpriteID = 4;
const int  optionsselectedleftSpriteID = 5;
const int  singleplayerrightSpriteID = 6;
const int  multiplayerrightSpriteID = 7;
const int  optionsrightSpriteID = 8;
const int  singleplayerselectedrightSpriteID = 9;
const int  multiplayerselectedrightSpriteID = 10;
const int  optionsselectedrightSpriteID = 11;
const int  joinfriendleftSpriteID = 12;
const int  hostgameleftSpriteID = 13;
const int  backleftSpriteID = 14;
const int  joinfriendselectedleftSpriteID = 15;
const int  hostgameselectedleftSpriteID = 16;
const int  backselectedleftSpriteID = 17;
const int  joinfriendrightSpriteID = 18;
const int  hostgamerightSpriteID = 19;
const int  backrightSpriteID = 20;
const int  joinfriendselectedrightSpriteID = 21;
const int  hostgameselectedrightSpriteID = 22;
const int  backselectedrightSpriteID = 23;
const int  paddleSpriteID = 24;
const int  ballSpriteID = 25;
const int paddleSpriteID2 = 26;

	extern void loadSprites();
	extern void createMenuButton(int position, int leftspriteID);
	extern void createBall(int slot, int x, int y);
	extern void createPaddle(int slot, int x, int y);
#endif