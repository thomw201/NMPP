#include "HostPong.h"


HostPong::HostPong(StateManager & manager, UdpSocket & socket) : GameState(manager), socket(socket)
{
	game = GameController();
	game.setMode(host);
}

HostPong::~HostPong()
{	
	
}

void HostPong::update(float deltaTime)
{
	game.Update(deltaTime);
	hidCircleRead(&circle);
	held = hidKeysHeld();

	if (held & KEY_TOUCH) {
		hidTouchRead(&touch);
	}

	if (held & KEY_UP)
	{
		game.movePaddle1(up);
	}
	else if (held & KEY_DOWN)
	{
		game.movePaddle1(down);
	}
	else
	{
		game.movePaddle1(neutral);
	}
	if (held & KEY_SELECT)
	{
		changeState(new SplashScreen(manager,socket));
	}

	sf2d_start_frame(GFX_TOP, GFX_LEFT);
		sf2d_draw_fill_circle(game.getBallX(), game.getBallY(), playingField.ballRadius, RGBA8(0xFF, 0xFF, 0xFF, 0xFF));
		sf2d_draw_rectangle(game.getPad1X(), game.getPad1Y(), game.getPad1Width(), game.getPad1Length(), RGBA8(0xFF, 0xFF, 0xFF, 0xFF));
		sf2d_draw_rectangle(game.getPad2X(), game.getPad2Y(), game.getPad2Width(), game.getPad2Length(), RGBA8(0xFF, 0xFF, 0xFF, 0xFF));
	sf2d_end_frame();

	sf2d_start_frame(GFX_TOP, GFX_RIGHT);
		sf2d_draw_fill_circle(game.getBallX(), game.getBallY(), playingField.ballRadius, RGBA8(0xFF, 0xFF, 0xFF, 0xFF));
		sf2d_draw_rectangle(game.getPad1X(), game.getPad1Y(), game.getPad1Width(), game.getPad1Length(), RGBA8(0xFF, 0xFF, 0xFF, 0xFF));
		sf2d_draw_rectangle(game.getPad2X(), game.getPad2Y(), game.getPad2Width(), game.getPad2Length(), RGBA8(0xFF, 0xFF, 0xFF, 0xFF));
	sf2d_end_frame();

	sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
		scoreManager.drawScore(game.getScore1(), game.getScore2());
	sf2d_end_frame();

	sf2d_swapbuffers();

}

void HostPong::changeState(GameState *nextState)
{
	manager.changeState(nextState);
}
