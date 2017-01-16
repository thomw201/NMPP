#pragma once
#include "GameState.h"
#include "PongClient.h"
#include "PongHost.h"
#include "MainMenu.h"

class MPMenu : public GameState
{
public:
	MPMenu(StateManager &manager);
	~MPMenu();
	// Inherited via GameState
	virtual void changeState(GameState * nextState) override;
	virtual void update(float deltaTime) override;
	void create();
	signed int selected;
	void navigate(signed int direction);
};

