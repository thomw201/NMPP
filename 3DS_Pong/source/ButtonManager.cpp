#include "ButtonManager.h"

ButtonManager::ButtonManager(std::vector<Button*> &buttons) : buttons(buttons)
{

}

ButtonManager::~ButtonManager()
{

}

void ButtonManager::up()
{
	buttonPlace--;
	if (buttonPlace < 0)
		buttonPlace = buttons.size() - 1;
	unselectAl();
	buttons.at(buttonPlace)->select();
}

void ButtonManager::down()
{
	buttonPlace++;
	if (buttonPlace >= buttons.size())
		buttonPlace = 0;
	unselectAl();
	buttons.at(buttonPlace)->select();
}

void ButtonManager::accept()
{
	for (auto &button : buttons)
	{
		if (button->isSelected())
		{
			button->activate();
		}
	}
}

void ButtonManager::touch(int x, int y)
{
	unselectAl();
	for (auto &button : buttons)
	{
		if (button->isSelected(x, y)) {
			break;
		}
	}
}

void ButtonManager::draw()
{
	for (auto &button : buttons)
	{
		button->draw();
	}
}

void ButtonManager::unselectAl()
{
	for (auto &button : buttons)
	{
		button->unSelect();
	}
}
