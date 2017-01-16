#include "MainMenu.h"


MainMenu::MainMenu(StateManager & manager) : GameState(manager)
{
	create();
	NF_LoadTiledBg("splash/splashscreentop", "top_splash", 256, 256);	//field background
	NF_CreateTiledBg(0, 3, "top_splash");		// game Background
	navigate(0);
}


MainMenu::~MainMenu()
{
	NF_ResetSpriteBuffers();
	for (int i = 0; i < 12; i++)
	{
		NF_DeleteSprite(1, i);
	}
}

void MainMenu::changeState(GameState * nextState)
{
	manager.changeState(nextState);
}

void MainMenu::update(float deltaTime)
{
	if (KEY_UP & keysDown())
	{
		navigate(-1);
	}
	else if (KEY_DOWN & keysDown())
	{
		navigate(1);
	}
	else if (KEY_A & keysDown())
	{
		switch (selected)
		{
		case 0:
			changeState(new PongvsAI(manager));
			break;
		case 1:
			changeState(new PongHost(manager));
		}
	}

	NF_SpriteOamSet(0);
	NF_SpriteOamSet(1);		// Update NFLib's Sprite OAM System
	swiWaitForVBlank();		// Wait for the Vertical Blank
	oamUpdate(&oamMain);
	oamUpdate(&oamSub);		// Update the OAM of the Bottom Screen engine
	scanKeys();		// Scan for Input
}

//draws all buttons
void MainMenu::create()
{
	const char* const buttonSprite1[] = { "menu/singleplayer_1", "menu/multiplayer_1", "menu/options_1", "menu/singleplayerselected_1", "menu/multiplayerselected_1", "menu/optionsselected_1" };
	const char* const buttonSprite2[] = { "menu/singleplayer_2", "menu/multiplayer_2", "menu/options_2", "menu/singleplayerselected_2", "menu/multiplayerselected_2", "menu/optionsselected_2" };
	//draw left side of all buttons
	for (u16 i = 0; i < 3; i++)
	{
		NF_LoadSpriteGfx(buttonSprite1[i], i, 64, 32);	// load left side of the button sprites
		NF_LoadSpritePal(buttonSprite1[i], i);
		NF_VramSpriteGfx(1, i, i, false);	// Load the Gfx into VRAM - transfer all Sprites
		NF_VramSpritePal(1, i, i);		// Load the Palette into VRAM 
		NF_CreateSprite(1, i, i, i, 64, 30+(i*50));
		//NF_ShowSprite(1, i, false); //hide selected sprite
	//draw right side of all buttons
		NF_LoadSpriteGfx(buttonSprite2[i], i+3, 64, 32);	// load left side of the button sprites
		NF_LoadSpritePal(buttonSprite2[i], i+3);
		NF_VramSpriteGfx(1, i + 3, i + 3, false);	// Load the Gfx into VRAM - transfer all Sprites
		NF_VramSpritePal(1, i + 3, i + 3);		// Load the Palette into VRAM 
		NF_CreateSprite(1, i + 3, i + 3, i + 3, 128, 30 + (i * 50));
		//NF_ShowSprite(1, i+3, false); //hide selected sprite
	//draw right side of all SELECTED buttons
		NF_LoadSpriteGfx(buttonSprite2[i+3], i + 6, 64, 32);	// load left side of the button sprites
		NF_LoadSpritePal(buttonSprite2[i+3], i + 6);
		NF_VramSpriteGfx(1, i + 6, i + 6, false);	// Load the Gfx into VRAM - transfer all Sprites
		NF_VramSpritePal(1, i + 6, i + 6);		// Load the Palette into VRAM 
		NF_CreateSprite(1, i + 6, i + 6, i + 6, 128, 30 + (i * 50));
		//NF_ShowSprite(1, i + 6, false); //hide selected sprite
	//draw left side of all SELECTED buttons
		NF_LoadSpriteGfx(buttonSprite1[i + 3], i + 9, 64, 32);	// load left side of the button sprites
		NF_LoadSpritePal(buttonSprite1[i + 3], i + 9);
		NF_VramSpriteGfx(1, i + 9, i + 9, false);	// Load the Gfx into VRAM - transfer all Sprites
		NF_VramSpritePal(1, i + 9, i + 9);		// Load the Palette into VRAM 
		NF_CreateSprite(1, i + 9, i + 9, i + 9, 64, 30 + (i * 50));
	}

}

void MainMenu::navigate(u8 direction)
{
	////show de-selected button
	NF_ShowSprite(1, selected, true); //left side of button
	NF_ShowSprite(1, selected + 3, true); //right side of button
	selected = selected + direction;
	if (selected > 2)
	{
		selected = 0;
	}
	if (selected < 0)
	{
		selected = 2;
	}
	////hide deselected button
	NF_ShowSprite(1, selected, false); //left side of button
	NF_ShowSprite(1, selected + 3, false); //right side of button
}
