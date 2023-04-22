#include "layer.h"
#include "canvas.h"

/*
@requires size must be positive
@assigns sets a new canvas
@ensures creates a new canvas with no layers
*/
canvas init_canvas(int size){
    canvas new_canvas;
    new_canvas.size = size;
    new_canvas.nb_layers = 0;
    return new_canvas;
}

/*
@requires c.nb_layers must be initialized and positive
@assigns nothing
@ensures if c.nb_layers == 0, it prints --BLANK CANVAS--\n other wise, it displays every layers of the canvas c indicated by their number
*/
void print_canvas(canvas c){
    if (c.nb_layers == 0){printf("--BLANK CANVAS--\n");return;}
    for (int i=0; i<c.nb_layers;i++){
        printf("--LAYER %d--\n\n",i+1);
        print_layer(c.layers[i]);
    }
}

/*
@requires the canvas pointed by pc must be fully initialized with pc->size being positive
@assigns nothing if pc->nb_layers >= 10, add a new layer to pc->layers otherwise
@ensures if pc->nb_layers < 10 add a new layer of pc->size * pc->size black transparent pixels on top of the canvas
*/
void add_layer(canvas *pc){
    if (pc->nb_layers < 10){
        layer new_layer = init_layer(pc->size);
        (pc->layers)[pc->nb_layers] = new_layer;
        pc->nb_layers ++;
    }
}

/*
@requires the canvas pointed by pc must be initialized, with the layers it contains fully initialized
@assigns free the heap from some layers
@ensures free the heap from all the layers contained by the canvas
*/
void free_canvas(canvas *pc){
    for (int i=0; i<pc->nb_layers; i++) free_layer(&(pc->layers[i]));
}

/*
@requires pc->nb_layers must be initialized, and if it is strictly more than 1, pc->size and the two layers on top of pc->layers must be fully initialized
@assigns if pc->nb_layers >=2 then changes pc->nb_layers and the layer below the summit of pc->grid, else nothing
@ensures merges the two last layers on top of the canvas
*/
void merge_layers(canvas *pc){
    if (pc->nb_layers > 1){
        int top = pc->nb_layers - 1;
        opacity current_opacity;
        for (int i=0; i<pc->size; i++){
            for (int j=0; j<pc->size; j++){
                current_opacity = pc->layers[top].grid[i][j].O;
                pc->layers[top-1].grid[i][j].O = pc->layers[top].grid[i][j].O + pc->layers[top-1].grid[i][j].O * (255-current_opacity)/255;
                pc->layers[top-1].grid[i][j].C.R = pc->layers[top].grid[i][j].C.R + pc->layers[top-1].grid[i][j].C.R * (255-current_opacity)/255;
                pc->layers[top-1].grid[i][j].C.G = pc->layers[top].grid[i][j].C.G + pc->layers[top-1].grid[i][j].C.G * (255-current_opacity)/255;
                pc->layers[top-1].grid[i][j].C.B = pc->layers[top].grid[i][j].C.B + pc->layers[top-1].grid[i][j].C.B * (255-current_opacity)/255;
            }
        }
        pc->nb_layers --;
        free_layer(&(pc->layers[top]));// it is important to not forget this free in order to not have any memory leak
    }
}

/*
@requires pc->nb_layers must be initialized, and if it is strictly more than 1, pc->size and the two layers on top of pc->layers must be fully initialized
@assigns if pc->nb_layers >=2 then changes pc->nb_layers and the layer below the summit of pc->grid, else nothing
@ensures cuts the layer below the one on the top of pc->layers using the later as an opacity mask
*/
void cut_layer(canvas *pc){
    int top = pc->nb_layers - 1;
    if (top>0){
        opacity current_opacity;
        for (int i=0; i<pc->size; i++){
            for (int j=0; j<pc->size; j++){
                current_opacity = pc->layers[top].grid[i][j].O;
                pc->layers[top-1].grid[i][j].C.R = pc->layers[top-1].grid[i][j].C.R*current_opacity/255;
                pc->layers[top-1].grid[i][j].C.G = pc->layers[top-1].grid[i][j].C.G*current_opacity/255;
                pc->layers[top-1].grid[i][j].C.B = pc->layers[top-1].grid[i][j].C.B*current_opacity/255;
                pc->layers[top-1].grid[i][j].O = pc->layers[top-1].grid[i][j].O*current_opacity/255;
            }
        }
        pc->nb_layers --;
        free_layer(&(pc->layers[top]));// it is important to not forget this free in order to not have any memory leak
    }
}