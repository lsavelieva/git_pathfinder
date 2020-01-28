#include "../inc/pathfinder.h"

void mx_printline(const char c, int num) {
    for (int i = 0; i < num; i++)
        mx_printchar(c);
    mx_printchar('\n');
}

//псевдокод - скелет вывода

void mx_output(){
    mx_printline('=', 40);
    PATH;
    //path out format "Path: <island1> -> <island2>"
    ROUTE;
    //route out format "Route: <island1> -> <all_islands_between> -> <island2>"
    DISTANCE;
    //distance out format "Distance: <length1> + <length2> = <sum>"
    mx_printline('=', 40);
}
