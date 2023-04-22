#ifndef CANVAS_H
#define CANVAS_H

#include "layer.h"

typedef struct canvas{
    int size;
    int nb_layers;
    layer layers[10];
} canvas;

/*
@requires size must be positive
@assigns sets a new canvas to the stack
@ensures creates a new canvas with no layers
*/
canvas init_canvas(int size);

/*
@requires c.nb_layers must be initialized and positive
@assigns nothing
@ensures if c.nb_layers == 0, it prints --BLANK CANVAS--\n other wise, it displays every layers of the canvas c indicated by their number
*/
void print_canvas(canvas c);

/*
@requires the canvas pointed by pc must be fully initialized with pc->size being positive
@assigns nothing if pc->nb_layers >= 10, add a new layer to pc->layers otherwise
@ensures if pc->nb_layers < 10 add a new layer of pc->size * pc->size black transparent pixels on top of the canvas
*/
void add_layer(canvas *pc);

/*
@requires the canvas pointed by pc must be initialized, with the layers it contains fully initialized
@assigns free the heap from some layers
@ensures free the heap from all the layers contained by the canvas
*/
void free_canvas(canvas *pc);

/*
@requires pc->nb_layers must be initialized, and if it is strictly more than 1, pc->size and the two layers on top of pc->layers must be fully initialized
@assigns if pc->nb_layers >=2 then changes pc->nb_layers and the layer below the summit of pc->grid, while freeing the heap from a layer, else nothing
@ensures merges the two last layers on top of the canvas
*/
void merge_layers(canvas *pc);

/*
@requires pc->nb_layers must be initialized, and if it is strictly more than 1, pc->size and the two layers on top of pc->layers must be fully initialized
@assigns if pc->nb_layers >=2 then changes pc->nb_layers and the layer below the summit of pc->grid, while freeing the heap from a layer, else nothing
@ensures cuts the layer below the one on top of pc->layers using the later as an opacity mask
*/
void cut_layer(canvas *pc);

#endif