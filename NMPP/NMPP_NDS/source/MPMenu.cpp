#include "MPMenu.h"

const int usedslots = 12;


MPMenu::MPMenu(StateManager & manager) : GameState(manager)
{
	const char* const buttonSprite1[] = { "menu/singleplayer_1", "menu/multiplayer_1", "menu/options_1", "menu/singleplayerselected_1", "menu/multiplayerselected_1", "menu/optionsselected_1" };
	const char* const buttonSprite2[] = { "menu/singleplayer_2", "menu/multiplayer_2", "menu/options_2", "menu/singleplayerselected_2", "menu/multiplayerselected_2", "menu/optionsselected_2" };
	//draw left side of all buttons
	for (u16 i = 0; i < 3; i++)
	{
		NF_UnloadSpriteGfx(i);
		NF_FreeSpriteGfx(1, i);
		NF_UnloadSpritePal(i);
		//NF_SPR256VRAM[1][i].inuse = false;
		NF_LoadSpriteGfx(buttonSprite1[i], i, 64, 32);	// load left side of the button sprites
		NF_LoadSpritePal(buttonSprite1[i], i);
		NF_VramSpritePal(1, i, i);		// Load the Palette into VRAM 
		NF_VramSpriteGfx(1, i, i, true);	// Load the Gfx into VRAM - transfer all Sprites
		NF_CreateSprite(1, i, i, i, 64, 30 + (i * 50));
		////draw right side of all buttons
		//NF_LoadSpriteGfx(buttonSprite2[i], i + 3, 64, 32);	// load left side of the button sprites
		//NF_LoadSpritePal(buttonSprite2[i], i + 3);
		//NF_VramSpriteGfx(1, i + 3, i + 3, true);	// Load the Gfx into VRAM - transfer all Sprites
		//NF_VramSpritePal(1, i + 3, i + 3);		// Load the Palette into VRAM 
		//NF_CreateSprite(1, i + 3, i + 3, i + 3, 128, 30 + (i * 50));
		////NF_ShowSprite(1, i+3, false); //hide selected sprite
		////draw right side of all SELECTED buttons
		//NF_LoadSpriteGfx(buttonSprite2[i + 3], i + 6, 64, 32);	// load left side of the button sprites
		//NF_LoadSpritePal(buttonSprite2[i + 3], i + 6);
		//NF_VramSpriteGfx(1, i + 6, i + 6, true);	// Load the Gfx into VRAM - transfer all Sprites
		//NF_VramSpritePal(1, i + 6, i + 6);		// Load the Palette into VRAM 
		//NF_CreateSprite(1, i + 6, i + 6, i + 6, 128, 30 + (i * 50));
		////NF_ShowSprite(1, i + 6, false); //hide selected sprite
		////draw left side of all SELECTED buttons
		//NF_LoadSpriteGfx(buttonSprite1[i + 3], i + 9, 64, 32);	// load left side of the button sprites
		//NF_LoadSpritePal(buttonSprite1[i + 3], i + 9);
		//NF_VramSpriteGfx(1, i + 9, i + 9, true);	// Load the Gfx into VRAM - transfer all Sprites
		//NF_VramSpritePal(1, i + 9, i + 9);		// Load the Palette into VRAM 
		//NF_CreateSprite(1, i + 9, i + 9, i + 9, 64, 30 + (i * 50));
	}
}


MPMenu::~MPMenu()
{
	for (int i = 0; i < 12; i++)
	{
		NF_DeleteSprite(1, i);
		NF_FreeSpriteGfx(1, i);
		NF_UnloadSpriteGfx(i);
		NF_UnloadSpritePal(i);
	}
	NF_ResetSpriteBuffers();
}

void MPMenu::changeState(GameState * nextState)
{
	manager.changeState(nextState);
}

void MPMenu::update(float deltaTime)
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
			changeState(new PongClient(manager));
			break;
		case 1:
			changeState(new PongHost(manager));
			break;
		case 2:
			changeState(new MainMenu(manager));
			break;
		}
	}
	NF_SpriteOamSet(0);
	NF_SpriteOamSet(1);		// Update NFLib's Sprite OAM System
	swiWaitForVBlank();		// Wait for the Vertical Blank
	oamUpdate(&oamMain);
	oamUpdate(&oamSub);		// Update the OAM of the Bottom Screen engine
	scanKeys();		// Scan for Input
}

void MPMenu::create()
{

}

void MPMenu::navigate(signed int direction)
{
	//////show de-selected button
	//NF_ShowSprite(1, usedslots+ selected, true); //left side of button
	//NF_ShowSprite(1, usedslots+selected + 3, true); //right side of button
	//selected = selected + direction;
	//if (selected > 2)
	//{
	//	selected = 0;
	//}
	//if (selected < 0)
	//{
	//	selected = 2;
	//}
	//////hide deselected button
	//NF_ShowSprite(1, usedslots+selected, false); //left side of button
	//NF_ShowSprite(1, usedslots+selected + 3, false); //right side of button
}
