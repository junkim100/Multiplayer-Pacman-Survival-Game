#include "Display.h"
#include "Distance.h"

#include <iostream>

using namespace std;

int Pacman::object_count = 0;
int Ghost::object_count = 0;

int main()
{
    Display display;
    display.show_map();

    Distance distance;
    Pacman p1;
    Pacman p2;
    Ghost g1;
    Ghost g2;

    p1.coordinate = { 1,1 };
    g1.coordinate = { 31,1 };
    p2.coordinate = { 1,15 };
    g2.coordinate = { 31,5 };

    while (true)
    {
        //break from loop if player dies
        if ((p1.get_death() == true) || (p2.get_death() == true))
        {
            display.clear_screen();
            break;
        }

        double distance_pp = distance.get_distance_pp(p1,p2);
        double distance_g1p1 = distance.get_distance_gp(g1, p1);
        double distance_g2p1 = distance.get_distance_gp(g2, p1);
        double distance_g1p2 = distance.get_distance_gp(g1, p2);
        double distance_g2p2 = distance.get_distance_gp(g2, p2);

        p1.eat_pacman(distance_g1p1, distance_g2p1);
        p2.eat_pacman(distance_g1p2, distance_g2p2);

        //ghost1 movement: chase and scatter
        double distance_gg = distance.get_distance_gg(g1, g2);
        if (g1.update_mode((int) distance_gg) == 0)
        {
            //cout << "chase";
            //g1 + p1;
            g1.chase(p1, display);
        }
        else
        {
            //cout << "scatter";
            g1.scatter(g2, display);
        }

        //ghost2 movement: chase and scatter
        if (g2.update_mode((int)distance_gg) == 0)
        {
            //cout << "chase";
            //g2 + p2;
            g2.chase(p2, display);
        }
        else
        {
            //cout << "scatter";
            g2.scatter(g1, display);
        }

        //player movement
        int a = p1.move_to(display);
        int b = p2.move_to(display);
        if (a == 1 || b == 1)
        {
            if (p1.update_mode(20) == 1)
                p1.eat_pacman(distance_pp);
            else if (p2.update_mode(20) == 1)
                p2.eat_pacman(distance_pp);

            display.clear_screen();
            display.show_map();
            
            cout << "Player 1: " << p1.get_points() << endl
                 << "player 2: " << p2.get_points() << endl;
        }
    }

    if (p1.get_points() > p2.get_points())
        cout << "The Winner is PLAYER 1";
    else if (p1.get_points() < p2.get_points())
        cout << "The Winner is PLAYER 2";
    else
        cout << "Its a Draw";

    return 0;
}
