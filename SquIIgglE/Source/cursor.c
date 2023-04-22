#include <stdio.h>

#include "cursor.h"

/*
@requires lim is initialized
@assigns creates a new cursor
@ensures create a new cursor placed at the coordinates (0,0), facing East and restrained, on x and y, in [0,lim[
*/
cursor init_cursor(int lim){
    cursor new_cursor;
    new_cursor.x = 0;
    new_cursor.y = 0;
    new_cursor.lim_coord = lim;
    new_cursor.direc = East;
    return new_cursor;
}

/*
@requires *pc must be fully initialized
@assigns changes either pc->x or pc->y
@ensures if *pc faces South, pc->x gains +1, -1 if *pc faces North, and same goes for y with East and West
*/
void moove(cursor *pc){
    if (pc->direc == South) pc->x = (pc->x +1)%(pc->lim_coord);
    else if (pc->direc == North) pc->x = (pc->x+pc->lim_coord-1)%(pc->lim_coord);
    else if (pc->direc == East) pc->y = (pc->y +1)%(pc->lim_coord);
    else if (pc->direc == West) pc->y = (pc->y+pc->lim_coord-1)%(pc->lim_coord);
}

/*
@requires *pc must have its direction initialized
@assigns changes pc->direc
@ensures the cursor makes a 90 degres clockwise rotation : East->South->West->North->East
*/
void clock_rotate(cursor *pc){
    pc-> direc = (pc->direc + 1)%4;
}

/*
@requires *pc must have its direction initialized
@assigns changes pc->direc
@ensures the cursor makes a 90 degres counterclockwise rotation : East->North->West->South->East
*/
void aclock_rotate(cursor *pc){
    pc->direc = (pc->direc +3)%4;
}

/*
@requires c must be fully initialized
@assigns nothing
@ensures displays the cursor as following : cur{(c.x,c.y)<c.lim_coord,c.direc} with c.direc written in letters 
*/
void print_cursor(cursor c){
    char* directions[4] = {"East","South","West","North"};
    printf("cur{(%d,%d)<%d,%s}",c.x,c.y,c.lim_coord,directions[c.direc]);
}