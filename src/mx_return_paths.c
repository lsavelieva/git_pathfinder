#include "../inc/pathfinder.h"

/* function that create new route */
static t_path *mx_create_path(int isl_count, int start, int end){
    t_path *mpath = (t_path*)malloc(sizeof(t_path));

    if (mpath == NULL)
        exit(1);
    mpath->size = 1;
    mpath->isl_count = isl_count;
    mpath->mpath = mx_create_intarr(isl_count);
    mpath->mpath[0] = end;
    mpath->mpath[1] = start;
    return mpath;
}
/* function that find all routes */
void mx_all_routs(t_matrix *tm, int isl_count, int start, int end) {
    t_path *mpath = mx_create_path(tm->isl_count, start, end);

    mx_backtracking(tm->mad, tm->mroute, mpath, tm);
    free(mpath->mpath);
    free(mpath);
    mpath = NULL;
}

/* "tail" recursion function */
void mx_backtracking(int **mad, int **mroute, t_path *mpath, t_matrix *tm) {
    int ic = mpath->isl_count;

    if (mpath->mpath[mpath->size] == mpath->mpath[0]) {
        mx_print_path(mpath, mroute, tm);
        return;
    }
    else {
        for (int i = 0; i < ic; i++) {
            if (mx_path_around(i, mad, mroute, mpath) == 1) {
                if (mpath->size < mpath->isl_count) {
                    mpath->size++;
                    mpath->mpath[mpath->size] = i;
                }
                mx_backtracking(mad, mroute, mpath, tm);
                if (mpath->size > 1)
                    mpath->size--;
            }
        }
    }
}

/* find neighbor function */
int mx_path_around(int p, int **mad, int **mroute, t_path *mpath) {
    int i = mpath->mpath[mpath->isl_count];
    int j = mpath->mpath[0];

    if (i != p) {
        if (mad[i][p] == mroute[j][i] - mroute[j][p])
            return 1;
    }
    return 0;
}
