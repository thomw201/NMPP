#pragma once
#include "Pong.h"
#include "SplashScreen.h"

class PongHost : public Pong
{
public:
	PongHost(StateManager & manager);
	~PongHost();
private:
	// Inherited via Pong
	virtual void updateGame() override;
	bool createServer();
	string command;
};

