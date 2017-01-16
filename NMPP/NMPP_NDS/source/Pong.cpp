#include "Pong.h"




Pong::Pong(StateManager & manager) : GameState(manager)
{
	initBackgrounds();
	controller = ponglogic::GameController();
	communication.isConnected = false;
	//p1Paddle = paddle(0, 0, SCREEN_WIDTH*0.05, SCREEN_HEIGHT / 2);
	//p2Paddle = paddle(1, 0, SCREEN_WIDTH - SCREEN_WIDTH*0.05, SCREEN_HEIGHT / 2);
	p1Paddle.setID(1);
	p2Paddle.setID(2);
	bal.setID(3);
	//bal = ball(2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2); //init ball in the center of the screen

	p1Paddle.setSize(controller.getPad1Width(), controller.getPad1Length());
	p2Paddle.setSize(controller.getPad2Width(), controller.getPad2Length());
	//bal.setSize(16, 16);
	p1Paddle.setPosition(controller.getPad1X(), controller.getPad1Y());// sync paddle positions
	p2Paddle.setPosition(controller.getPad2X(), controller.getPad1Y());
	bal.setPosition(controller.getBallX(), controller.getBallY());
	p1Paddle.create();
	p2Paddle.create();
	bal.create();
}

Pong::~Pong()
{
	NF_DeleteTiledBg(0, 3);
	NF_DeleteTiledBg(1, 3);
	NF_UnloadTiledBg("BottomBG");
	NF_UnloadTiledBg("TopBG");
	NF_ResetTiledBgBuffers();
	NF_ResetSpriteBuffers();
}

void Pong::changeState(GameState * nextState)
{
	manager.changeState(nextState);
}

void Pong::initBackgrounds()
{
		NF_LoadTiledBg("game/bg/splashImg", "TopBG", 256, 256); // splash background
		NF_LoadTiledBg("game/bg/fieldImg", "BottomBG", 256, 256);	//field background

		NF_CreateTiledBg(1, 3, "TopBG");		// splash Background
		NF_CreateTiledBg(0, 3, "BottomBG");		// game Background
}

void Pong::update(float deltaTime)
{
	if (KEY_SELECT & keysCurrent())
	{
		//changeState(new SplashScreen(manager));
	}
	updateGame(); //call the function containing the vs ai, vs host or vs client code
	controller.Update(/*0.05f*/deltaTime); //update controller
	NF_SpriteOamSet(0);
	NF_SpriteOamSet(1);		// Update NFLib's Sprite OAM System
	swiWaitForVBlank();		// Wait for the Vertical Blank
	oamUpdate(&oamMain);
	oamUpdate(&oamSub);		// Update the OAM of the Bottom Screen engine
	scanKeys();		// Scan for Input
	touchRead(&Stylus);		// Read Stylus data
}
