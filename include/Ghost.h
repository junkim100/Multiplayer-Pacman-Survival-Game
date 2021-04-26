#ifndef Ghost_H
#define Ghost_H

#include "Unit.h"
#include "Pacman.h"

using namespace std;

class Ghost : public Unit
{
private:
    //static int variable that counts the number of Pacman object created
    static int object_count;

    int ghost_num;

    vector<int> target;

public:
    //constructor that initialize private member variables
    Ghost();

    //static getter function for object_count
    static int get_object_count();

    //overloading pure virtual functions of Unit class/////////////////////////////////

    //
    int move_to(Display&);

    //returns 0 if chase and 1 if scatter
    int update_mode(int);

    ///////////////////////////////////////////////////////////////////////////////////

    //chasing and scatter movement
    void chase(Pacman&, Display&);
    void scatter(Ghost& g, Display&);
    
    //friend function
    friend vector<int> path_find(Unit&);
    Ghost operator+(Unit&);
};

#endif