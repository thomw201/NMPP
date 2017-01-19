#include "TextPrinter.h"




uiBitmapFont readBitmapFont(u8* bitmap, s16 cellSize, s16 offset, s16 gridSize, s16 texWidthAndHeight) {
	uiBitmapFont font;
	font.cellSize = cellSize;
	font.gridSize = gridSize;
	font.offset = offset;
	font.bitmap = sf2d_create_texture(texWidthAndHeight, texWidthAndHeight, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	sf2d_fill_texture_from_RGBA8(font.bitmap, bitmap, texWidthAndHeight, texWidthAndHeight);
	sf2d_texture_tile32(font.bitmap);
	return font;
}

void renderBitmapText(std::string text, int x, int y, uiBitmapFont &font) {
	int bitmapX, bitmapY, tcX, tcY, count = 0;
	for (char &c : text) {
		bitmapX = ((int)c % font.gridSize);
		bitmapY = ((int)c / font.gridSize);
		tcX = (int)(bitmapX * font.cellSize);
		tcY = (int)(bitmapY * font.cellSize);
		sf2d_draw_texture_part(font.bitmap, count >= 1 ? x + (font.cellSize - font.offset) * count : x, y, tcX, tcY, font.cellSize - font.offset, font.cellSize);
		count++;
	}
}

