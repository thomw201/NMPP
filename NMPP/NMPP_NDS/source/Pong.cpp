#include "Pong.h"




Pong::Pong(StateManager & manager) : GameState(manager)
{
	initBackgrounds();
	controller = ponglogic::GameController();
	communication.isConnected = false;
	//p1Paddle = paddle(0, 0, SCREEN_WIDTH*0.05, SCREEN_HEIGHT / 2);
	//p2Paddle = paddle(1, 0, SCREEN_WIDTH - SCREEN_WIDTH*0.05, SCREEN_HEIGHT / 2);
	p1Paddle.setID(13);
	p2Paddle.setID(14);
	bal.setID(15);
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
	NF_Unload16bitsBg(5);
	NF_Disble16bitsBackBuffer(5);
}

void Pong::changeState(GameState * nextState)
{
	manager.changeState(nextState);
}

void Pong::initBackgrounds()
{
	NF_Unload16bitsBg(3);
	NF_Load16bitsBg("bg/playingfield", 5);
	NF_Copy16bitsBuffer(0, 5, 5);

}

void Pong::update(float deltaTime)
{
	if (KEY_SELECT & keysCurrent())
	{
		//changeState(new SplashScreen(manager));
	}
	NF_Flip16bitsBackBuffer(0);
	NF_Flip16bitsBackBuffer(1);
	updateGame(); //call the function containing the vs ai, vs host or vs client code
	controller.Update(deltaTime); //update controller
	NF_SpriteOamSet(0);
	NF_SpriteOamSet(1);		// Update NFLib's Sprite OAM System
	swiWaitForVBlank();		// Wait for the Vertical Blank
	oamUpdate(&oamMain);
	oamUpdate(&oamSub);		// Update the OAM of the Bottom Screen engine
	scanKeys();		// Scan for Input
	touchRead(&Stylus);		// Read Stylus data
}
