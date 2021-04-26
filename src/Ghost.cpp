#include "Ghost.h"

Ghost::Ghost() {
    //evertime a Ghost object is made it will have its own unique ghost_num
    object_count++;
    ghost_num = object_count;
}

int Ghost::get_object_count()
{
    return object_count;
}

int Ghost::move_to(Display& display)
{
    //eat_pacman();
    //g
    //p
    if ((display.map[coordinate[1] + 1][coordinate[0]] == ' ') && (coordinate[1] <= target[1]))
    {
        display.map[coordinate[1]][coordinate[0]] = '-';
        coordinate[1] += 1;
        display.map[coordinate[1]][coordinate[0]] = 'G';
    }
    
    //p
    //g
    if ((display.map[coordinate[1] - 1][coordinate[0]] == ' ') && (coordinate[1] >= target[1]))
    {
        display.map[coordinate[1]][coordinate[0]] = '-';
        coordinate[1] -= 1;
        display.map[coordinate[1]][coordinate[0]] = 'G';
    }

    //g p
    if ((display.map[coordinate[1]][coordinate[0] + 1] == ' ') && (coordinate[0] <= target[0]))
    {
        display.map[coordinate[1]][coordinate[0]] = '-';
        coordinate[0] += 1;
        display.map[coordinate[1]][coordinate[0]] = 'G';
    }

    //p g
    if ((display.map[coordinate[1]][coordinate[0] - 1] == ' ') && (coordinate[0] >= target[0]))
    {
        display.map[coordinate[1]][coordinate[0]] = '-';
        coordinate[0] -= 1;
        display.map[coordinate[1]][coordinate[0]] = 'G';
    }
    
    return 0;
}

//0 is chase, 1 is scatter
int Ghost::update_mode(int distance_gg)
{
    if (distance_gg < 7)
        return 1;
    else
        return 0;
}

void Ghost::chase(Pacman& p, Display& display)
{
    target = { path_find(p)[0], path_find(p)[1] };
    move_to(display);
}

void Ghost::scatter(Ghost& g, Display& display)
{
    if (ghost_num % 2 == 0)
        target = { 0,0 };
    else
        target = { 33,16 };

    move_to(display);
}

vector<int> path_find(Unit& u) {
    return u.coordinate;
}

Ghost Ghost::operator+(Unit& u)
{
    Ghost g;
    g.target = { path_find(u)[0], path_find(u)[1] };
    return Ghost();
}

