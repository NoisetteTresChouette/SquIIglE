#ifndef PIXEL_H
#define PIXEL_H

#include "bucket.h"

typedef struct pixel{
    color C;
    opacity O;
} pixel;

/*
@requires nothing
@assigns add a new pixel
@ensures create a new transparent black pixel
*/
pixel init_pixel();

/*
@requires p must be initialized with a color and an opacity
@assigns nothing
@ensures displays the pixel p like so: #C:p.C|O:p.O#
*/
void print_pixel(pixel p);

/*
@requires both pixels p1 and p2 must be fully initialized
@assigns create a new unsigned char
@ensures return 1 if p1 and p2 have all their components equal, 0 otherwise
*/
char pixel_equals(pixel p1, pixel p2);

/*
@requires both buckets must be initialized and finished
@assigns create a new pixel
@ensures create a new_pixel with its opacity being the average of opacities or 255 if this later is empty, and its color being black if colors is empty, or its opacity/255 times colors average for each color component
*/
pixel calculate_pixel(cbucket colors, obucket opacities);

#endif