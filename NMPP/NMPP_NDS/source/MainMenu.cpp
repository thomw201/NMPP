#include "MainMenu.h"


MainMenu::MainMenu(StateManager & manager) : GameState(manager)
{
	create();
}


MainMenu::~MainMenu()
{
	for (u8 i = 0; i < 12; i++)
	{
		//NF_UnloadSpriteGfx(i);
		//NF_UnloadSpritePal(i);
		//NF_FreeSpriteGfx(1, i);
		NF_DeleteSprite(1, i);
	}
}

void MainMenu::changeState(GameState * nextState)
{
	manager.changeState(nextState);
}

void MainMenu::update(float deltaTime)
{
	// read the touchscreen coordinates
	touchRead(&touch);
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
			changeState(new MPMenu(manager));
			break;
		case 2:
			break;
		}
	}
	else if (KEY_TOUCH & keysDown())
	{
		if ((touch.px > 30) & (touch.px < 156))
		{
			if ((touch.py > 30) & (touch.py < 62))
			{
				changeState(new PongvsAI(manager));
			}
			else if (touch.py > 62 & touch.py < 94)
			{
				changeState(new MPMenu(manager));
			}
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
	createMenuButton(0, singleplayerleftSpriteID);
	createMenuButton(1, multiplayerleftSpriteID);
	createMenuButton(2, optionsleftSpriteID);
}

void MainMenu::navigate(signed int direction)
{
	////show de-selected button
	NF_ShowSprite(1, selected, true); //left side of button
	NF_ShowSprite(1, selected + 6, true); //right side of button
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
	NF_ShowSprite(1, selected + 6, false); //right side of button
}
