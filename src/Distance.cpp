#include "Distance.h"

double Distance::get_distance_gg(Ghost g1, Ghost g2)
{
	distance_gg = sqrt(pow(g1.coordinate[0] - g2.coordinate[0], 2) + pow(g1.coordinate[1] - g2.coordinate[1], 2));
	return distance_gg;
}

double Distance::get_distance_pp(Pacman p1, Pacman p2)
{
	distance_pp = sqrt(pow(p1.coordinate[0] - p2.coordinate[0], 2) + pow(p1.coordinate[1] - p2.coordinate[1], 2));
	return distance_pp;
}

double Distance::get_distance_gp(Ghost g1, Pacman p1)
{
	distance_gp = sqrt(pow(g1.coordinate[0] - p1.coordinate[0], 2) + pow(g1.coordinate[1] - p1.coordinate[1], 2));
	return distance_gp;
}
