#pragma once
class menu
{
public:
	menu();
	menu(int screen);
	~menu();
	int run();
private:
	void createButton();
};

