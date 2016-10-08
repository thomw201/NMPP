#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <math.h>
#include <3ds.h>
#include <sf2d.h>
#include "citra_img.c"
#include "dice_img.c"
#include "GameController.h"

std::clock_t  start;

float frametimer()
{
	float time = (std::clock() - start) / (float)(CLOCKS_PER_SEC);
	start = std::clock();
	return time;
}

#define CONFIG_3D_SLIDERSTATE (*(float *)0x1FF81080)

int main()
{
	start = std::clock();
	// Set the random seed based on the time
	srand(time(NULL));
	float deltaTime = 0;

	sf2d_init();
	sf2d_set_clear_color(RGBA8(0x40, 0x40, 0x40, 0xFF));
	sf2d_set_3D(1);


	//sf2d_texture *tex1 = sf2d_create_texture_mem_RGBA8(dice_img.pixel_data, dice_img.width, dice_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	sf2d_texture *tex2 = sf2d_create_texture_mem_RGBA8(citra_img.pixel_data, citra_img.width, citra_img.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);

	float offset3d = 0.0f;
	float rad = 0.0f;
	u16 touch_x = 320/2;
	u16 touch_y = 240/2;
	touchPosition touch;
	circlePosition circle;
	u32 held;
	GameController game = GameController();
	
	

	while (aptMainLoop()) {

		hidScanInput();
		hidCircleRead(&circle);
		held = hidKeysHeld();



		if (held & KEY_START) {
			break;
		} else if (held & KEY_TOUCH) {
			hidTouchRead(&touch);
			touch_x = touch.px;
			touch_y = touch.py;
		} else if (held & (KEY_L | KEY_R)) {
			sf2d_set_clear_color(RGBA8(rand()%255, rand()%255, rand()%255, 255));
		}

		game.Update(0.05f);

		offset3d = CONFIG_3D_SLIDERSTATE * 30.0f;

		sf2d_start_frame(GFX_TOP, GFX_LEFT);
			sf2d_draw_fill_circle(offset3d + game.getBallX(), game.getBallY(), 10, RGBA8(0xFF, 0xFF, 0xFF, 0xFF));
			//sf2d_draw_fill_circle(offset3d + 180, 120, 55, RGBA8(0xFF, 0xFF, 0x00, 0xFF));

			//(offset3d + 260, 20, 40, 40, RGBA8(0xFF, 0xFF, 0x00, 0xFF), -2.0f*rad);
			sf2d_draw_rectangle(offset3d + game.getPad1X(), game.getPad1Y(), game.getPad1Width(), game.getPad1Length(), RGBA8(0xFF, 0xFF, 0xFF, 0xFF));
			sf2d_draw_rectangle(offset3d + game.getPad2X(), game.getPad2Y(), game.getPad2Width(), game.getPad2Length(), RGBA8(0xFF, 0xFF, 0xFF, 0xFF));
			//sf2d_draw_texture_rotate(tex1, offset3d + 400/2 + circle.dx, 240/2 - circle.dy, rad);
		sf2d_end_frame();

		sf2d_start_frame(GFX_TOP, GFX_RIGHT);

			sf2d_draw_fill_circle(game.getBallX(), game.getBallY(), 10, RGBA8(0xFF, 0xFF, 0xFF, 0xFF));
			//sf2d_draw_fill_circle(180, 120, 55, RGBA8(0xFF, 0xFF, 0x00, 0xFF));

			//sf2d_draw_rectangle_rotate(260, 20, 40, 40, RGBA8(0xFF, 0xFF, 0x00, 0xFF), -2.0f*rad);
			sf2d_draw_rectangle(game.getPad1X(), game.getPad1Y(), game.getPad1Width(), game.getPad1Length(), RGBA8(0xFF, 0xFF, 0xFF, 0xFF));
			sf2d_draw_rectangle(game.getPad2X(), game.getPad2Y(), game.getPad2Width(), game.getPad2Length(), RGBA8(0xFF, 0xFF, 0xFF, 0xFF));
			//sf2d_draw_texture_rotate(tex1, 400/2 + circle.dx, 240/2 - circle.dy, rad);
		sf2d_end_frame();

		sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
			//sf2d_draw_rectangle_rotate(190, 160, 70, 60, RGBA8(0xFF, 0xFF, 0xFF, 0xFF), 3.0f*rad);
			//sf2d_draw_rectangle(30, 100, 40, 60, RGBA8(0xFF, 0x00, 0xFF, 0xFF));
			sf2d_draw_texture_rotate(tex2, touch_x, touch_y, -rad);
			//sf2d_draw_rectangle(160-15 + cosf(rad)*50.0f, 120-15 + sinf(rad)*50.0f, 30, 30, RGBA8(0x00, 0xFF, 0xFF, 0xFF));
			//sf2d_draw_fill_circle(40, 40, 35, RGBA8(0x00, 0xFF, 0x00, 0xFF));
		sf2d_end_frame();

		//rad += 0.2f;

		sf2d_swapbuffers();

	}

	//sf2d_free_texture(tex1);
	//sf2d_free_texture(tex2);

	sf2d_fini();
	return 0;
}
