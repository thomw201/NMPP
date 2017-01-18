#pragma once
#include "Pong.h"
#include "SplashScreen.h"

class PongClient : public Pong
{
public:
	PongClient(StateManager &manager);
	~PongClient();
private:
	// Inherited via Pong
	virtual void updateGame() override;
	bool connect();
	string command;
};

