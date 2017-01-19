#pragma once
#include <3ds.h>
#include <sf2d.h>
#include <functional>

/**
*@ Class for Button.
*/
class Button {

private:
	sf2d_texture *normalButton;
	sf2d_texture *selectedButton;
	int x, y, width, height;
	bool selected = false;
	std::function<void()> onAction;

public:
	Button(int x, int y, const void *pixeldataNormal, const void *pixeldataSelected, int width, int height, std::function<void()> onAction);
	~Button();
	void draw();
	void activate();
	bool isSelected();
	bool isSelected(int x, int y);
	void select();
	void unSelect();
};