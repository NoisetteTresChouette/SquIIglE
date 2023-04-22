#ifndef DRAW_H
#define DRAW_H

#include "layer.h"

/*
@requires x0,y0,x1,y1 must be in [0,pl->size[, current_pixel must be fully initialized
@assigns sets pixels to multiple slots of pc->grid
@ensures draws a line of cuurent_pixel on the layer pointed by pl, from the coordinates (x0,y0) to (x1,y1) 
*/
void draw_line(int x0,int y0,int x1, int y1,pixel current_pixel,layer *pl);

/*
@requires x,y must belong to [0,pl->size[, new_pixel and *pl have to be fully initialized
@assigns sets pixels to multiple slots of pc->grid
@ensures change the color of all the pixels with the same color than the one at coordinates (x,y) in its surrounding arena to new_pixel
*/
void fill(int x, int y, pixel new_pixel, layer *pl);

#endif