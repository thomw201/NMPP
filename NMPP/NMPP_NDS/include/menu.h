#pragma once
class menu
{
public:
	menu();
	menu(int screen);
	~menu();
private:
	int run();
	void createButton();
};

