#pragma once
#include <sf2d.h>
#include <string>

struct uiBitmapFont {
	sf2d_texture* bitmap;
	s16 cellSize, offset, gridSize;
};

uiBitmapFont readBitmapFont(u8* bitmap, s16 cellSize, s16 offset, s16 gridSize, s16 texWidthAndHeight);
void renderBitmapText(std::string text, int x, int y, uiBitmapFont &font);





