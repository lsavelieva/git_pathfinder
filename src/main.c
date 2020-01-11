#include "../inc/pathfinder.h"

int main(int argc, char **argv) {
    //int temp;

    if(argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        return 0;
    }
    if (mx_err_handling(argv[1]) < 0)
        return 0;
    mx_check_line(argv[1]);
    mx_printstr("i am here\n");


    system("leaks -q pathfinder");
    return 0;
}
