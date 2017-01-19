#include "HostPong.h"


HostPong::HostPong(StateManager & manager, UdpSocket & socket) : GameState(manager), socket(socket)
{
	game = GameController();
	game.setMode(host);
	font = readBitmapFont((u8*)font_img.pixel_data, 32, 7, 16, 512);
}

HostPong::~HostPong()
{	
	sf2d_free_texture(font.bitmap);
}

void HostPong::update(float deltaTime)
{
	game.Update(deltaTime);
	hidCircleRead(&circle);
	held = hidKeysHeld();
	socket.sendString(game.getGameState());
	
	string message;
	if (socket.getMessage(message) == 0)
	{
		game.syncPaddleState(message);
	}

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
		sf2d_draw_fill_circle(translateCoordX(game.getBallX()), translateCoord(game.getBallY()), translateCoord(playingField.ballRadius), RGBA8(0xFF, 0xFF, 0xFF, 0xFF));
		sf2d_draw_rectangle(translateCoordX(game.getPad1X()), translateCoord(game.getPad1Y()), translateCoord(game.getPad1Width()), translateCoord(game.getPad1Length()), RGBA8(0xFF, 0xFF, 0xFF, 0xFF));
		sf2d_draw_rectangle(translateCoordX(game.getPad2X()), translateCoord(game.getPad2Y()), translateCoord(game.getPad2Width()), translateCoord(game.getPad2Length()), RGBA8(0xFF, 0xFF, 0xFF, 0xFF));
		for (size_t i = 0; i < 20; i++)
		{
			sf2d_draw_rectangle(198, i * 12, 4, 8, RGBA8(0xFF, 0xFF, 0xFF, 0xFF));
		}
	sf2d_end_frame();

	sf2d_start_frame(GFX_TOP, GFX_RIGHT);
		sf2d_draw_fill_circle(translateCoordX(game.getBallX()), translateCoord(game.getBallY()), translateCoord(playingField.ballRadius), RGBA8(0xFF, 0xFF, 0xFF, 0xFF));
		sf2d_draw_rectangle(translateCoordX(game.getPad1X()), translateCoord(game.getPad1Y()), translateCoord(game.getPad1Width()), translateCoord(game.getPad1Length()), RGBA8(0xFF, 0xFF, 0xFF, 0xFF));
		sf2d_draw_rectangle(translateCoordX(game.getPad2X()), translateCoord(game.getPad2Y()), translateCoord(game.getPad2Width()), translateCoord(game.getPad2Length()), RGBA8(0xFF, 0xFF, 0xFF, 0xFF));
		for (size_t i = 0; i < 20; i++)
		{
			sf2d_draw_rectangle(198, i * 12, 4, 8, RGBA8(0xFF, 0xFF, 0xFF, 0xFF));
		}
	sf2d_end_frame();

	sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
		renderBitmapText("Score:", 80, 30, font);
		converter.str(string()); converter << game.getScore1();
		renderBitmapText(converter.str(), 80, 90, font);
		converter.str(string()); converter << game.getScore2();
		renderBitmapText(converter.str(), 200, 90, font);
	sf2d_end_frame();;

	sf2d_swapbuffers();

}

void HostPong::changeState(GameState *nextState)
{
	manager.changeState(nextState);
}

int HostPong::translateCoordX(int coord)
{
	return coord * 5 / 4 + 40;
}

int HostPong::translateCoord(int coord)
{
	return coord * 5 / 4;
}
