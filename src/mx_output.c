#include "../inc/pathfinder.h"

void mx_printline(const char c, int num) {
    for (int i = 0; i < num; i++)
        mx_printchar(c);
    mx_printchar('\n');
}

//псевдокод - скелет вывода

void mx_output(){
    mx_printline('=', 40);
    mx_printstr("Path: <island1> -> <island2>");
    //path out
    mx_printstr("Route: <island1> -> <all_islands_between> -> <island2>");
    //route out
    mx_printstr("Distance: <length1> + <length2> = <sum>");
    //distanse out
    mx_printline('=', 40);
}
