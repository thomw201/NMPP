#include "MPMenu.h"

const int usedslots = 12;


MPMenu::MPMenu(StateManager & manager) : GameState(manager)
{
	//NF_ResetSpriteBuffers();
	//NF_InitSpriteBuffers();		// Initialize Sprite Buffers
	//NF_InitSpriteSys(0);
	//NF_InitSpriteSys(1);		// Initialize Bottom Screen SpriteSystem
	const char* const buttonSprite1[] = { "menu/joinfriend_1", "menu/hostgame_1", "menu/back_1", "menu/joinfriendselected_1", "menu/hostgameselected_1", "menu/backselected_1" };
	const char* const buttonSprite2[] = { "menu/joinfriend_2", "menu/hostgame_2", "menu/back_2", "menu/joinfriendselected_2", "menu/hostgameselected_2", "menu/backselected_2" };
	//draw left side of all buttons
	for (u16 i = 0; i < 3; i++)
	{
		int id = 12 + i;
		NF_LoadSpriteGfx(buttonSprite1[i], id, 64, 32);	// load left side of the button sprites
		NF_LoadSpritePal(buttonSprite1[i], id);
		NF_VramSpritePal(1, id, i);		// Load the Palette into VRAM 
		NF_VramSpriteGfx(1, id, id, true);	// Load the Gfx into VRAM - transfer all Sprites
		NF_CreateSprite(1, id, id, i, 64, 30 + (i * 50));
		//draw right side of all buttons

		NF_LoadSpriteGfx(buttonSprite2[i], id + 3, 64, 32);	// load left side of the button sprites
		NF_LoadSpritePal(buttonSprite2[i], id + 3);
		NF_VramSpritePal(1, id + 3, i + 3);		// Load the Palette into VRAM 
		NF_VramSpriteGfx(1, id + 3, id + 3, true);	// Load the Gfx into VRAM - transfer all Sprites
		NF_CreateSprite(1, id + 3, id + 3, i + 3, 128, 30 + (i * 50));
		////NF_ShowSprite(1, i+3, false); //hide selected sprite
		////draw right side of all SELECTED buttons
		NF_LoadSpriteGfx(buttonSprite2[i + 3], id + 6, 64, 32);	// load left side of the button sprites
		NF_LoadSpritePal(buttonSprite2[i + 3], id + 6);
		NF_VramSpriteGfx(1, id + 6, id + 6, true);	// Load the Gfx into VRAM - transfer all Sprites
		NF_VramSpritePal(1, id + 6, i + 6);		// Load the Palette into VRAM 
		NF_CreateSprite(1, id + 6, id + 6, i + 6, 128, 30 + (i * 50));
		//NF_ShowSprite(1, i + 6, false); //hide selected sprite
		//draw left side of all SELECTED buttons
		NF_LoadSpriteGfx(buttonSprite1[i + 3], id + 9, 64, 32);	// load left side of the button sprites
		NF_LoadSpritePal(buttonSprite1[i + 3], id + 9);
		NF_VramSpriteGfx(1, id + 9, id + 9, true);	// Load the Gfx into VRAM - transfer all Sprites
		NF_VramSpritePal(1, id + 9, i + 9);		// Load the Palette into VRAM 
		NF_CreateSprite(1, id + 9, id + 9, i + 9, 64, 30 + (i * 50));
	}
}


MPMenu::~MPMenu()
{
	for (u8 i = 0; i < 12; i++)
	{
		NF_UnloadSpriteGfx(i);
		NF_UnloadSpritePal(i);
		NF_FreeSpriteGfx(1, i);
		NF_DeleteSprite(1, i);
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
	////show de-selected button
	NF_ShowSprite(1, usedslots+ selected, true); //left side of button
	NF_ShowSprite(1, usedslots+selected + 3, true); //right side of button
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
	NF_ShowSprite(1, usedslots+selected, false); //left side of button
	NF_ShowSprite(1, usedslots+selected + 3, false); //right side of button
}
