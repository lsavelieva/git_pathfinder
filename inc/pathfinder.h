#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <malloc/malloc.h>
#include <fcntl.h>
#include "../libmx/inc/libmx.h"

//Error function
void mx_printerr(const char *s);
int mx_err_handling(const char *file);

//Basic functions
int mx_file_size(const char *file);
int mx_atoi(const char *str);
int mx_check_line(const char *file);

#endif
