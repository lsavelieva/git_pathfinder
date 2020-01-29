#include "../inc/pathfinder.h"

/* print line between the path */
void mx_printline(const char c, int num) {
    for (int i = 0; i < num; i++)
        mx_printchar(c);
    mx_printchar('\n');
}

/* print path out format "Path: <island1> -> <island2>" */
void mx_print_path(t_path *mpath, int **mroute, t_matrix *tm) {
    mx_printline('=', 40);
    mx_printstr(PATH);
    mx_printstr(tm->uniq[mroute->mroute[1]);
    mx_printstr(DELIM);
    mx_printstr(tm->uniq[mroute->mroute[0]);
    mx_printchar('\n');
    mx_printstr(ROUTE);
    write_route(tm, mroute);
    mx_printstr(DISTANCE);
    write_distance();
    mx_printline('=', 40);
}

/* print route */
static void write_route() {
    mx_printchar('\n');
}

/* print distance */
static void write_distance () {

    mx_printchar('\n');
}
