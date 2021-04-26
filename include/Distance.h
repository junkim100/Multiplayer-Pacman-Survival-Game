#ifndef Distance_H
#define Distance_H

#include "Ghost.h"
#include "Pacman.h"

#include <math.h>

using namespace std;

class Distance
{
private:
    double distance_gg;
    double distance_pp;
    double distance_gp;

public:
    //getter for the 3 distances that also calculates 
    //the distance using Pythagorean Theorem
    double get_distance_gg(Ghost, Ghost);
    double get_distance_pp(Pacman, Pacman);
    double get_distance_gp(Ghost, Pacman);
};

#endif