#include "ScoreManager.h"

ScoreManager::ScoreManager()
{
	scoreNumbers[0] = sf2d_create_texture_mem_RGBA8(zero_img.pixel_data, zero_img.width, zero_img.height, TEXFMT_RGBA8, SF2D_PLACE_VRAM);
	scoreNumbers[1] = sf2d_create_texture_mem_RGBA8(one_img.pixel_data, one_img.width, one_img.height, TEXFMT_RGBA8, SF2D_PLACE_VRAM);
	scoreNumbers[2] = sf2d_create_texture_mem_RGBA8(two_img.pixel_data, two_img.width, two_img.height, TEXFMT_RGBA8, SF2D_PLACE_VRAM);
	scoreNumbers[3] = sf2d_create_texture_mem_RGBA8(three_img.pixel_data, three_img.width, three_img.height, TEXFMT_RGBA8, SF2D_PLACE_VRAM);
	scoreNumbers[4] = sf2d_create_texture_mem_RGBA8(four_img.pixel_data, four_img.width, four_img.height, TEXFMT_RGBA8, SF2D_PLACE_VRAM);
	scoreNumbers[5] = sf2d_create_texture_mem_RGBA8(five_img.pixel_data, five_img.width, five_img.height, TEXFMT_RGBA8, SF2D_PLACE_VRAM);
	scoreNumbers[6] = sf2d_create_texture_mem_RGBA8(six_img.pixel_data, six_img.width, six_img.height, TEXFMT_RGBA8, SF2D_PLACE_VRAM);
	scoreNumbers[7] = sf2d_create_texture_mem_RGBA8(seven_img.pixel_data, seven_img.width, seven_img.height, TEXFMT_RGBA8, SF2D_PLACE_VRAM);
	scoreNumbers[8] = sf2d_create_texture_mem_RGBA8(eight_img.pixel_data, eight_img.width, eight_img.height, TEXFMT_RGBA8, SF2D_PLACE_VRAM);
	scoreNumbers[9] = sf2d_create_texture_mem_RGBA8(nine_img.pixel_data, nine_img.width, nine_img.height, TEXFMT_RGBA8, SF2D_PLACE_VRAM);
}

ScoreManager::~ScoreManager()
{
	for (size_t i = 0; i < 10; i++)
	{
		sf2d_free_texture(scoreNumbers[i]);
	}
}

void ScoreManager::drawScore(int score1, int score2)
{

	sf2d_draw_texture(scoreNumbers[score1 / 10 % 100],60,110);
	sf2d_draw_texture(scoreNumbers[score1 % 10],80,110);
	sf2d_draw_texture(scoreNumbers[score2 / 10 % 100], 220, 110);
	sf2d_draw_texture(scoreNumbers[score2 % 10], 240, 110);
}


