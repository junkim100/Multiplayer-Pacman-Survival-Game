#ifndef Unit_H
#define Unit_H

#include "Display.h"

#include <Windows.h>
#include <vector>
#include <iostream>
#include <conio.h>

using namespace std;

class Unit
{
public:
    vector<int> coordinate;

    //pure virtual function
    virtual int move_to(Display&) = 0;
    virtual int update_mode(int) = 0;

    friend vector<int> path_find(Unit&);
};

#endif