#pragma once
#include "Pong.h"

class PongvsAI : public Pong
{
public:
	PongvsAI(StateManager &manager);
	~PongvsAI();
private:
	virtual void updateGame() override;
};

