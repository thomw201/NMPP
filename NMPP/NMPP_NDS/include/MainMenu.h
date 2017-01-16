#pragma once
#include "GameState.h"
#include <nf_lib.h>
#include "PongvsAI.h"
#include "PongHost.h"
#include "PongClient.h"

class MainMenu : public GameState
{
public:
	MainMenu(StateManager &manager);
	~MainMenu();

	// Inherited via GameState
	virtual void changeState(GameState * nextState) override;
	virtual void update(float deltaTime) override;
private:
	void create();
	int selected;
	void navigate(u8 direction);
};

