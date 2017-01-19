#include "MPMenu.h"

touchPosition t;

MPMenu::MPMenu(StateManager & manager) : GameState(manager)
{
	create();
}


MPMenu::~MPMenu()
{
	for (u8 i = 0; i < 12; i++)
	{
	//	NF_UnloadSpriteGfx(i);
		//NF_UnloadSpritePal(i);
		//NF_FreeSpriteGfx(1, i);
		//NF_DeleteSprite(1, i);
	}
}

void MPMenu::changeState(GameState * nextState)
{
	manager.changeState(nextState);
}

void MPMenu::update(float deltaTime)
{
	// read the touchscreen coordinates
	touchRead(&t);
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
	//else if (KEY_TOUCH & keysDown())
	//{
	//	if ((t.px > 30) & (t.px < 156))
	//	{
	//		if ((t.py > 30) & (t.py < 62))
	//		{
	//				changeState(new PongvsAI(manager));
	//		}
	//		else if (t.py > 62 & t.py < 94)
	//		{
	//				changeState(new MPMenu(manager));
	//		}
	//		else if (t.py > 94 & t.py < 126)
	//		{
	//			changeState(new MainMenu(manager));
	//		}
	//	}
	//}
	NF_SpriteOamSet(0);
	NF_SpriteOamSet(1);		// Update NFLib's Sprite OAM System
	swiWaitForVBlank();		// Wait for the Vertical Blank
	oamUpdate(&oamMain);
	oamUpdate(&oamSub);		// Update the OAM of the Bottom Screen engine
	scanKeys();		// Scan for Input
}

void MPMenu::create()
{
	createMenuButton(0, joinfriendleftSpriteID);
	createMenuButton(1, hostgameleftSpriteID);
	createMenuButton(2, backleftSpriteID);
}

void MPMenu::navigate(signed int direction)
{
	////show de-selected button
	NF_ShowSprite(1, selected+joinfriendleftSpriteID, true); //left side of button
	NF_ShowSprite(1, selected+ joinfriendleftSpriteID + 6, true); //right side of button
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
	NF_ShowSprite(1, selected+ joinfriendleftSpriteID, false); //left side of button
	NF_ShowSprite(1, selected+ joinfriendleftSpriteID + 6, false); //right side of button
}
