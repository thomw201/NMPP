#pragma once
#include "GameState.h"
#include "PongvsAI.h"
#include "PongHost.h"
#include "PongClient.h"
#include "MPMenu.h"

class MainMenu : public GameState
{
public:
	MainMenu(StateManager &manager);
	~MainMenu();
private:
	// Inherited via GameState
	virtual void changeState(GameState * nextState) override;
	virtual void update(float deltaTime) override;
	void create();
	signed int selected;
	void navigate(signed int direction);
};

