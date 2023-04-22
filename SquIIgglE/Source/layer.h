#ifndef LAYER_H
#define LAYER_H

#include "pixel.h"

typedef struct layer {
    int size;
    pixel **grid;
}layer;

/*
@requires size must be positive
@assigns allocates memory for a new layer with size*size pixels in the heap
@ensures creates a new layer of size*size black transparent pixels
*/
layer init_layer(int size);

/*
@requires *pl must be fully initialized
@assigns free the heap from a matrix of pixels
@ensures free the heap from the entire grid of pixels of the layer pointed by pl
*/
void free_layer(layer *pl);

/*
@requires layer must be fully initialized with all its pixels
@assigns nothing
@ensures displays the layer l like this : ! pixel(1,1) pixel(1,2) ... !\n! pixel(2,1) pixel(2,2) ... ! ...
*/
void print_layer(layer l);

#endif