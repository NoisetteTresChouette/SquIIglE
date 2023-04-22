#include "draw.h"
#include "layer.h"

/*
@requires x0,y0,x1,y1 must be in [0,pl->size[, current_pixel must be fully initialized
@assigns sets pixels to multiple slots of pc->grid
@ensures draws a line of cuurent_pixel on the layer pointed by pl, from the coordinates (x0,y0) to (x1,y1) 
*/
void draw_line(int x0,int y0,int x1, int y1,pixel current_pixel,layer *pl){
    int dx = x1-x0;
    int dy = y1-y0;
    int d = (abs(dx)+abs(dy) + abs(abs(dx)-abs(dy)))/2;//d is the maximum between abs(dx) and abs(dy)
    int s;
    if (dx*dy > 0) s = 0;
    else s = 1;
    int x = x0 * d + (d-s)/2;
    int y = y0 * d + (d-s)/2;
    for (int _=0; _<d; _++){
        pl->grid[x/d][y/d] = current_pixel;
        x += dx;
        y += dy;
    }
    pl->grid[x1][y1] = current_pixel;
}

// we are creating below a linked list type for the following fill function
typedef struct cell{
    int coord_x;
    int coord_y;
    struct cell *next;
}cell;

typedef cell *list;

/*
@requires *pl must be initialized
@assigns set a new cell and change the value of *pl
@ensures add new coordinates (new_x,new_y) on top of the list pointed by pl
*/
void add_list(int new_x,int new_y, list *pl){
    cell *head = malloc(sizeof(cell));
    head->coord_x = new_x;
    head->coord_y = new_y;
    head->next = *pl;
    *pl = head;
}

/*
@requires *pl has to be initialized and must have at least one element
@assigns free the heap from a cell and change the value of *pl
@ensures remove the top cell of *pl
*/
void pop(list *pl){
    list tmp;
    tmp = (*pl)->next;
    free(*pl);
    *pl = tmp;
}

/*
@requires x,y must belong to [0,pl->size[, new_pixel and *pl have to be fully initialized
@assigns sets pixels to multiple slots of pc->grid
@ensures change the color of all the pixels with the same color than the one at coordinates (x,y) in its surrounding arena to new_pixel
*/
void fill(int x, int y, pixel new_pixel, layer *pl){
    if (pixel_equals(pl->grid[x][y],new_pixel)) return;
    pixel old_pixel = pl->grid[x][y];
    list todolist = NULL;// we will add to this list the coordinates of the pixels we still have to work on
    add_list(x,y,&todolist);

    char **todogrid = malloc(pl->size*sizeof(char *));// as soon as the pixel at coordinates (x,y) is added to the todolist, todogrid[x][y] will be set to one, enabling us to later verify if it has already been added to the todolist, in order to avoid redundance
    for (int i=0; i<pl->size; i++) todogrid[i] = calloc(pl->size,sizeof(char));
    todogrid[x][y] = 1;
    
    while (todolist != NULL){// there is a limited amount of pixels on the layer, and every pixel can only appear one time in the todolist thanks to the todogrid. However, we keep poping out coordinates from the todolist, so it will eventually be empty
        x = todolist->coord_x;
        y = todolist->coord_y;
        pop(&todolist);// this pop empties the todolist, and avoids getting memory leaks
        pl->grid[x][y] = new_pixel;
        if ((x>0 && todogrid[x-1][y] != 1) && pixel_equals(old_pixel,pl->grid[x-1][y])){add_list(x-1,y,&todolist); todogrid[x-1][y] = 1;}
        if ((y>0 && todogrid[x][y-1] != 1) && pixel_equals(old_pixel,pl->grid[x][y-1])){add_list(x,y-1,&todolist); todogrid[x][y-1] = 1;}
        if ((x<pl->size-1 && todogrid[x+1][y] != 1) && pixel_equals(old_pixel,pl->grid[x+1][y])){add_list(x+1,y,&todolist); todogrid[x+1][y] = 1;}
        if ((y<pl->size-1 && todogrid[x][y+1] != 1) && pixel_equals(old_pixel,pl->grid[x][y+1])){add_list(x,y+1,&todolist); todogrid[x][y+1] = 1;}
    }

    for (int i=0; i<pl->size;i++) free(todogrid[i]);
    free(todogrid);// let's not forget to free this grid
}