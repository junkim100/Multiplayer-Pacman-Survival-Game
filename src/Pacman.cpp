#include "Pacman.h"

Pacman::Pacman()
{
	//evertime a Pacman object is made it will have its own unique player_num
	object_count++;
	player_num = object_count;

	mode = 0;
	points = 0;
	death = false;
}

int Pacman::get_object_count()
{
	return object_count;
}

int Pacman::move_to(Display& display)
{
	//cout << player_num;
	if (player_num == 1)
	{
		int c = 0;
		switch (c = _getch()) {
		case 119:
			//cout << endl << "Up1" << endl;
			if (display.map[coordinate[1] - 1][coordinate[0]] == ' ') {
				display.map[coordinate[1]][coordinate[0]] = ' ';
				coordinate[1] -= 1;
				display.map[coordinate[1]][coordinate[0]] = 'P';
			}
			else if (display.map[coordinate[1] - 1][coordinate[0]] == '-') {
				points++;
				display.map[coordinate[1]][coordinate[0]] = ' ';
				coordinate[1] -= 1;
				display.map[coordinate[1]][coordinate[0]] = 'P';
			}
			return 1;
		case 115:
			//cout << endl << "Down1" << endl;
			if (display.map[coordinate[1] + 1][coordinate[0]] == ' ') {
				display.map[coordinate[1]][coordinate[0]] = ' ';
				coordinate[1] += 1;
				display.map[coordinate[1]][coordinate[0]] = 'P';
			}
			else if (display.map[coordinate[1] + 1][coordinate[0]] == '-') {
				points++;
				display.map[coordinate[1]][coordinate[0]] = ' ';
				coordinate[1] += 1;
				display.map[coordinate[1]][coordinate[0]] = 'P';
			}
			return 1;
		case 97:
			//cout << endl << "Left1" << endl;
			if (display.map[coordinate[1]][coordinate[0] - 1] == ' ') {
				display.map[coordinate[1]][coordinate[0]] = ' ';
				coordinate[0] -= 1;
				display.map[coordinate[1]][coordinate[0]] = 'P';
			}
			else if (display.map[coordinate[1]][coordinate[0] - 1] == '-') {
				points++;;
				display.map[coordinate[1]][coordinate[0]] = ' ';
				coordinate[0] -= 1;
				display.map[coordinate[1]][coordinate[0]] = 'P';
			}
			return 1;
		case 100:
			//cout << endl << "Right1" << endl;
			if (display.map[coordinate[1]][coordinate[0] + 1] == ' ') {
				display.map[coordinate[1]][coordinate[0]] = ' ';
				coordinate[0] += 1;
				display.map[coordinate[1]][coordinate[0]] = 'P';
			}
			else if (display.map[coordinate[1]][coordinate[0] + 1] == '-') {
				points++;
				display.map[coordinate[1]][coordinate[0]] = ' ';
				coordinate[0] += 1;
				display.map[coordinate[1]][coordinate[0]] = 'P';
			}
			return 1;
		default:
			return 0;
		}
	}

	else
	{
		int c = 0;
		switch (c = _getch()) {
		case 105:
			//cout << endl << "Up2" << endl;
			if (display.map[coordinate[1] - 1][coordinate[0]] == ' ') {
				display.map[coordinate[1]][coordinate[0]] = ' ';
				coordinate[1] -= 1;
				display.map[coordinate[1]][coordinate[0]] = 'P';
			}
			else if (display.map[coordinate[1] - 1][coordinate[0]] == '-') {
				points++;
				display.map[coordinate[1]][coordinate[0]] = ' ';
				coordinate[1] -= 1;
				display.map[coordinate[1]][coordinate[0]] = 'P';
			}
			return 1;
		case 107:
			//cout << endl << "Down2" << endl;
			if (display.map[coordinate[1] + 1][coordinate[0]] == ' ') {
				display.map[coordinate[1]][coordinate[0]] = ' ';
				coordinate[1] += 1;
				display.map[coordinate[1]][coordinate[0]] = 'P';
			}
			else if (display.map[coordinate[1] + 1][coordinate[0]] == '-') {
				points++;
				display.map[coordinate[1]][coordinate[0]] = ' ';
				coordinate[1] += 1;
				display.map[coordinate[1]][coordinate[0]] = 'P';
			}
			return 1;
		case 106:
			//cout << endl << "Left2" << endl;
			if (display.map[coordinate[1]][coordinate[0] - 1] == '-') {
				points++;
				display.map[coordinate[1]][coordinate[0]] = ' ';
				coordinate[0] -= 1;
				display.map[coordinate[1]][coordinate[0]] = 'P';
			}
			return 1;
		case 108:
			//cout << endl << "Right2" << endl;
			if (display.map[coordinate[1]][coordinate[0] + 1] == ' ') {
				display.map[coordinate[1]][coordinate[0]] = ' ';
				coordinate[0] += 1;
				display.map[coordinate[1]][coordinate[0]] = 'P';
			}
			else if (display.map[coordinate[1]][coordinate[0] + 1] == '-') {
				points++;
				display.map[coordinate[1]][coordinate[0]] = ' ';
				coordinate[0] += 1;
				display.map[coordinate[1]][coordinate[0]] = 'P';
				return 1;
		default:
			return 0;
			}
		}

	}
}

//0 is normal, 1 is super
// parameter is the points needed to be in super mode
int Pacman::update_mode(int i)
{
	if (points >= i)
		mode = 1;
	else
		mode = 0;

	return mode;
}

void Pacman::eat_pacman(double distance_gp1, double distance_gp2)
{
	if ((distance_gp1 <= 1) || (distance_gp2 <= 1))
	{
		update_death();
		points = points - 100;
	}
}

void Pacman::eat_pacman(double distance_pp)
{
	if (distance_pp <= 1)
	{
		update_death();
		points = points + 100;
	}
}

void Pacman::update_death()
{
	if (death)
		death = false;
	else
		death = true;
}

bool Pacman::get_death()
{
	return death;
}

void Pacman::update_point(Display& display)
{
	display.set_points(points);
}

int Pacman::get_points()
{
	return points;
}

void Pacman::reset_points()
{
	points = 0;
}
