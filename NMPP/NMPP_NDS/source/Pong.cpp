#include "Pong.h"
#include "SplashScreen.h"



Pong::Pong(StateManager & manager) : GameState(manager)
{
	initBackgrounds();
	controller = GameController();
	communication.isConnected = false;
	bal.setID(0); //set unique ids for each object so they take their own spot in ram
	p1Paddle.setID(paddleSpriteID);
	p2Paddle.setID(paddleSpriteID2);
	p1Paddle.setSlot(1);
	p2Paddle.setSlot(2); //both paddles need to be different objects
	p1Paddle.setSize(controller.getPad1Width(), controller.getPad1Length());
	p2Paddle.setSize(controller.getPad2Width(), controller.getPad2Length());
	p1Paddle.setPosition(controller.getPad1X(), controller.getPad1Y());// sync paddle positions
	p2Paddle.setPosition(controller.getPad2X(), controller.getPad1Y());

	p1Paddle.create();
	p2Paddle.create();
	bal.create();
	bal.setPosition(controller.getBallX(), controller.getBallY());
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
	if (isP1)
	{
		if (KEY_DOWN & keysCurrent()) {
			controller.movePaddle1(down);
		}
		else if (KEY_UP & keysCurrent()) {
			controller.movePaddle1(up);
		}
		else if (KEY_SELECT & keysDown())
		{

		}
		else
			controller.movePaddle1(neutral);
	}

	controller.Update(deltaTime); //update controller
	updateGame(); //call the function containing the vs ai, vs host or vs client code
	consoleDemoInit();
	cout << "\n\n\n\n\n\t\t\t    score:\n\n\n\t\t\t " << controller.getScore1() << "\t\t\t\t" << controller.getScore2() << endl;
	if (KEY_SELECT & keysCurrent())
	{
		changeState(new SplashScreen(manager));
	}
	NF_Flip16bitsBackBuffer(0);
	NF_Flip16bitsBackBuffer(1);
	NF_SpriteOamSet(0);
	NF_SpriteOamSet(1);		// Update NFLib's Sprite OAM System
	swiWaitForVBlank();		// Wait for the Vertical Blank
	oamUpdate(&oamMain);
	oamUpdate(&oamSub);		// Update the OAM of the Bottom Screen engine
	scanKeys();		// Scan for Input
	touchRead(&Stylus);		// Read Stylus data
}
