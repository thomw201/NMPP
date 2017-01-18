#include "MPMenu.h"


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
