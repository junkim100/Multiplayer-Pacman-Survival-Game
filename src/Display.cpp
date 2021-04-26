#include "Display.h"

void Display::show_map() {
	for (int i = 0; i < 17; i++)
		printf("%s\n", map[i]);
}

void Display::set_points(int points)
{
	this->points = points;
}

int Display::get_points()
{
	return points;
}

void Display::clear_screen()
{
	system("CLS");
}

