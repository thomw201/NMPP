#include <math.h>
#include "paddle.h"



paddle::paddle()
{

}


paddle::~paddle()
{
}
<<<<<<< HEAD
=======


/* creates the paddle on the posX, posY position */
void paddle::create() {
	NF_LoadSpriteGfx("paddleImg", id, width, height);	// load paddle sprite
	NF_LoadSpritePal("paddleImg", id);

	NF_VramSpriteGfx(screen, id, id, true);	// Load the Gfx into VRAM - transfer all Sprites
	NF_VramSpritePal(screen, id, id);		// Load the Palette into VRAM

	NF_CreateSprite(screen, id, id, id, posX, posY);		//create paddle 5% from the border and in the middle of the screen (vertically)
}
>>>>>>> feature/Nightfoxlib_sprites
