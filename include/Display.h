#ifndef Display_H
#define Display_H

#include <vector>
#include <string>

using namespace std;

class Display
{
private:
	int points;

public:
	
	char map[17][34] =
	{
	"#################################",
	"#P                  #####      G#",
	"# ######### #######       ##### #",
	"# ######### ####### ########### #",
	"#                   ########### #",
	"####### #### ######             #",
	"####### #### ###### ###### #### #",
	"#                   ###### #### #",
	"## ###### ####### ######## #### #",
	"## ###### #####            #### #",
	"##  ##### ##### ### ###### #### #",
	"### ###         ###             #",
	"### ### #### ######   ######### #",
	"#       ####  ###       ####### #",
	"#   ######         #### ####### #",
	"#P              #######        G#",
	"#################################"
	};

	/*{
		"#################################",
		"#P                             G#",
		"#                               #",
		"#                               #",
		"#                               #",
		"#                              G#",
		"#                               #",
		"#                               #",
		"#                               #",
		"#                               #",
		"#                               #",
		"#                               #",
		"#                               #",
		"#                               #",
		"#                               #",
		"#P                              #",
		"#################################",
	};*/

	//getter function for map: displays the map on the screen
	void show_map();

	//setter and getter for points
	void set_points(int);
	int get_points();

	//clears entire screen
	void clear_screen();
};

#endif