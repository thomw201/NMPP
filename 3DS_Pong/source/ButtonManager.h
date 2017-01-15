#pragma once
#include <3ds.h>
#include <sf2d.h>
#include <vector>
#include "Button.h"

/**
*@ Class for ButtonManager.
*/
class ButtonManager {

private:
	std::vector<Button*> &buttons;
	int arraySize;
	int buttonPlace = -1;

public:

	ButtonManager(std::vector<Button*> &buttons);
   ~ButtonManager();
   void up();
   void down();
   void accept();
   void touch(int x, int y);
   void draw();

private:
	void unselectAl();

};