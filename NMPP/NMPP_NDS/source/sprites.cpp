#include "sprites.h"

const char* const buttonSprites[] = { "menu/singleplayer_1", "menu/multiplayer_1", "menu/options_1", "menu/singleplayerselected_1", "menu/multiplayerselected_1", "menu/optionsselected_1", "menu/singleplayer_2", "menu/multiplayer_2", "menu/options_2", "menu/singleplayerselected_2", "menu/multiplayerselected_2", "menu/optionsselected_2","menu/joinfriend_1", "menu/hostgame_1", "menu/back_1", "menu/joinfriendselected_1", "menu/hostgameselected_1", "menu/backselected_1", "menu/joinfriend_2", "menu/hostgame_2", "menu/back_2", "menu/joinfriendselected_2", "menu/hostgameselected_2", "menu/backselected_2" };
const char* paddleSprite = "game/sprites/paddleImg";
const char* ballSprite = "game/sprites/ballImg";

const int buttonleftX = 64;
const int buttonrightX = 128;

//load all sprites from PONG
extern void loadSprites()
{
	int spritecount = 0;
	//load all buttons
	for (auto const sprite : buttonSprites)
	{
		NF_LoadSpriteGfx(sprite, spritecount, 64, 32);	// load left side of the button sprites
		NF_LoadSpritePal(sprite, spritecount);
		NF_VramSpriteGfx(1, spritecount, spritecount, true);	// Load the Gfx into VRAM - transfer all Sprites
		spritecount++;
	}
	//load paddle sprite
	NF_LoadSpriteGfx(paddleSprite, paddleSpriteID, 8, 32);	// load left side of the button sprites
	NF_LoadSpritePal(paddleSprite, spritecount);
	NF_VramSpriteGfx(0, spritecount, spritecount, true);	// Load the Gfx into VRAM - transfer all Sprites
	spritecount++;
	//load ball sprite
	NF_LoadSpriteGfx(ballSprite, ballSpriteID, 8, 8);	// load left side of the button sprites
	NF_LoadSpritePal(ballSprite, spritecount);
	NF_VramSpriteGfx(0, spritecount, spritecount, true);	// Load the Gfx into VRAM - transfer all Sprites
	spritecount++;
	//load paddle2 sprite
	NF_LoadSpriteGfx(paddleSprite, paddleSpriteID2, 8, 32);	// load left side of the button sprites
	NF_LoadSpritePal(paddleSprite, spritecount);
	NF_VramSpriteGfx(0, spritecount, spritecount, true);	// Load the Gfx into VRAM - transfer all Sprites
	spritecount++;
}

//automatically creates the (whole) single player button (as we are limited to 64x64 sprites). Place on bottom screen by default
extern void createMenuButton(int position, int leftspriteID) {
	int slot = position * 4; //every button needs 4 slots
	//left side, unselected
	NF_VramSpritePal(1, leftspriteID, slot);		// Load the Palette into VRAM 
	NF_CreateSprite(1, leftspriteID, leftspriteID, slot, buttonleftX, 30+(position*50));
	//right side, unselected
	NF_VramSpritePal(1, leftspriteID+6, slot+1);		// Load the Palette into VRAM 
	NF_CreateSprite(1, leftspriteID+6, leftspriteID+6, slot+1, buttonrightX, 30 + (position * 50));
	//left side, selected
	NF_VramSpritePal(1, leftspriteID+3, slot+2);		// Load the Palette into VRAM 
	NF_CreateSprite(1, leftspriteID+3, leftspriteID+3, slot+2, buttonleftX, 30 + (position * 50));
	//right side, selected
	NF_VramSpritePal(1, leftspriteID+9, slot+3);		// Load the Palette into VRAM 
	NF_CreateSprite(1, leftspriteID+9, leftspriteID+9, slot+3, buttonrightX, 30 + (position * 50));
}

extern void createBall(int slot, int x, int y) {
	NF_VramSpritePal(0, ballSpriteID, slot);		// Load the Palette into VRAM 
	NF_CreateSprite(0, ballSpriteID, ballSpriteID, slot, x, y);
}

extern void createPaddle(int slot, int x, int y) {
	NF_VramSpritePal(0, paddleSpriteID, slot);		// Load the Palette into VRAM 
	NF_CreateSprite(0, paddleSpriteID, paddleSpriteID, slot, x, y);
}