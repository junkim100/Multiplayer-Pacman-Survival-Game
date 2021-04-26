#ifndef Pacman_H
#define Pacman_H

#include "Unit.h"

using namespace std;

class Ghost;

class Pacman : public Unit
{
private:
    //static int variable that counts the number of Pacman object created
    static int object_count;

    int player_num;
    char mode;
    int points;
    bool death;

    void update_point(Display&);    
    
public:
    //constructor that initialize private member variables
    Pacman();

    //static getter function for object_count
    static int get_object_count();

    //overloading pure virtual functions of Unit class/////////////////////////////////

    //
    int move_to(Display&);

    //sets and returns mode as 0 if normal and 1 if super
    int update_mode(int);

    ///////////////////////////////////////////////////////////////////////////////////

    //function overloading
    //when eaten by ghost
    void eat_pacman(double, double);
    //when eating other pacman
    void eat_pacman(double);
    
    //change death value when called
    void update_death();

    //getter for death and points
    bool get_death();
    int get_points();

    void reset_points();

};

#endif