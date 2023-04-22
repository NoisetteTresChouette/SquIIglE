#ifndef BUCKET_H
#define BUCKET_H

#include <stdlib.h>

#include "color.h"

typedef struct color_dose{
    color value;
    struct color_dose* next;
} cdose;

typedef cdose* cbucket;

/*
@requires nothing
@assigns set a new empty cbucket
@ensures create an empty color bucket = NULL
*/
cbucket init_cbucket();

/*
@requires new_color and *pb must be correctly initialized
@assigns create a new color dose in the heap and changes pb
@ensures add a new dose of the color new_color on top of the bucket pointed by pb
*/
void addc(color new_color, cbucket *pb);

/*
@requires *pb must be initialized and must end
@assigns free the heap from color doses
@ensures free the heap from all the color doses included in the bucket pointed by pb
*/
void free_cbucket(cbucket *pb);

/*
@requires bucket must be initialized and finshed
@assigns nothing
@ensures print all the colors from the cbucket bucket
*/
void print_cbucket(cbucket bucket);

typedef struct opacity_dose{
    opacity value;
    struct opacity_dose* next;
} odose;

typedef odose* obucket;

/*
@requires nothing
@assigns create a new obucket
@ensures create an empty opacity bucket = NULL
*/
obucket init_obucket();

/*
@requires new_opacity and *pb must be correctly initialized
@assigns allocates memory for a new odose in the heap and changes pb
@ensures add a new dose of opacity new_opacity at the top of the obucket pointed by pb
*/
void addo(opacity new_opacity, obucket *pb);

/*
@requires pb must be initialized and has to end
@assigns free the heap from odoses
@ensures free the heap from all the opacity doses of the obucket pointed by pb
*/
void free_obucket(obucket *pb);

/*
@requires pb must be initialized and has to end
@assigns nothing
@requires displays all the opacities of the obucket bucket
*/
void print_obucket(obucket bucket);

#endif