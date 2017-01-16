#include "Button.h"

Button::Button(int x, int y, const void * pixeldataNormal, const void * pixeldataSelected, int width, int height, std::function<void()> onAction) :	x(x), y(y), width(width), height(height), onAction(onAction)
{
	normalButton = sf2d_create_texture_mem_RGBA8(pixeldataNormal, width, height, TEXFMT_RGBA8, SF2D_PLACE_VRAM);
	selectedButton = sf2d_create_texture_mem_RGBA8(pixeldataSelected, width, height, TEXFMT_RGBA8, SF2D_PLACE_VRAM);
}

Button::~Button()
{
	sf2d_free_texture(normalButton);
	sf2d_free_texture(selectedButton);
}

void Button::draw()
{
	if (!selected)
	{
		sf2d_draw_texture(normalButton, x, y);
	}
	else {
		sf2d_draw_texture(selectedButton, x, y);
	}
}

void Button::activate()
{
	onAction();
}

bool Button::isSelected()
{
	return selected;
}

bool Button::isSelected(int x, int y)
{
	selected = x > this->x && y > this->y && x < this->x + width && y < this->y + height;
	return selected;
}

void Button::select()
{
	selected = true;
}

void Button::unSelect()
{
	selected = false;
}
