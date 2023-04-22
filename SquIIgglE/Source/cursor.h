#ifndef CURSOR_H
#define CURSOR_H

#include <stdio.h>

typedef enum direction{East,South,West,North} direction;//these are by default set to the values 0,1,2,3

typedef struct cursor{
    int x;
    int y;
    int lim_coord;
    direction direc;
} cursor;

/*
@requires lim is initialized
@assigns creates a new cursor
@ensures create a new cursor placed at the coordinates (0,0), facing East and restrained, on x and y, in [0,lim[
*/
cursor init_cursor(int lim);

/*
@requires *pc must be fully initialized
@assigns changes either pc->x or pc->y
@ensures if *pc faces South, pc->x gains +1, -1 if *pc faces North, and same goes for y with East and West
*/
void moove(cursor *pc);

/*
@requires *pc must have its direction initialized
@assigns changes pc->direc
@ensures the cursor makes a 90 degres clockwise rotation : East->South->West->North->East
*/
void clock_rotate(cursor *pc);

/*
@requires *pc must have its direction initialized
@assigns changes pc->direc
@ensures the cursor makes a 90 degres counterclockwise rotation : East->North->West->South->East
*/
void aclock_rotate(cursor *pc);

/*
@requires c must be fully initialized
@assigns nothing
@ensures displays the cursor as following : cur{(c.x,c.y)<c.lim_coord,c.direc} with c.direc written in letters 
*/
void print_cursor(cursor c);

#endif