#include "pixel.h"
#include "layer.h"

/*
@requires size must be positive
@assigns allocates memory for a new layer with size*size pixels in the heap
@ensures creates a new layer of size*size black transparent pixels
*/
layer init_layer(int size){
    layer new_layer;
    new_layer.size = size;
    new_layer.grid = malloc(size*sizeof(pixel*));
    for (int i=0; i<size; i++){
        new_layer.grid[i] = malloc(size*sizeof(pixel));
        for (int j=0; j<size; j++) new_layer.grid[i][j] = init_pixel();
    }
    return new_layer;
}

/*
@requires *pl must be fully initialized
@assigns free the heap from a matrix of pixels
@ensures free the heap from the entire grid of pixels of the layer pointed by pl
*/
void free_layer(layer *pl){
    for (int i=0; i<pl->size; i++) free(pl->grid[i]);
    free(pl->grid);
}

/*
@requires layer must be fully initialized with all its pixels
@assigns nothing
@ensures displays the layer l like this : ! pixel(1,1) pixel(1,2) ... !\n! pixel(2,1) pixel(2,2) ... ! ...
*/
void print_layer(layer l){
    for (int i=0; i<l.size; i++){
        printf("! ");
        for (int j=0; j<l.size; j++){
            print_pixel(l.grid[i][j]);
            printf(", ");
        }
        printf("!\n");
    }
}