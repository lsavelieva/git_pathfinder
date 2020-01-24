#ifndef PATHFINDER_H
#define PATHFINDER_H

#define MX_INF 2147483647

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <malloc/malloc.h>
#include <fcntl.h>
#include <errno.h>
#include "../libmx/inc/libmx.h"

//Error function
void mx_printerr(const char *s);
void mx_error_invalid_line(int line);
void mx_error_invalid_number();
int mx_err_handling(const char *file);
int mx_check_line(char *str);
int mx_check_digit(const char *s, int n, int line_nbr);

//Additional functions
int mx_file_size(const char *file);
int mx_atoi(const char *str);
int mx_get_arr_size(char **arr);
int mx_get_index(char *s, char c1, char c2);
int mx_pf_count_word(char *s, const char *delim);


//Basic functions
char *mx_file_content(const char *file);
int mx_first_line(char *tempstr);
char **mx_get_strarr(char *s, int isl_count);
char **mx_matrix_split(char **arr, int count);
char **mx_arr_of_isl(char **arr, int count, int isl_count);
// int mx_matrix_adjacency(char **mdata, int size);

#endif
