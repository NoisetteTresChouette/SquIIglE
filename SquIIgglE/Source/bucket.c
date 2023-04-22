#include <stdlib.h>

#include "color.h"
#include "bucket.h"

/*
@requires nothing
@assigns set a new empty cbucket
@ensures create an empty color bucket = NULL
*/
cbucket init_cbucket(){
    cbucket new_bucket = NULL;
    return new_bucket;
}

/*
@requires new_color and *pb must be correctly initialized
@assigns create a new color dose in the heap and changes pb
@ensures add a new dose of the color new_color on top of the bucket pointed by pb
*/
void addc(color new_color, cbucket *pb){
    cdose *new_dose = malloc(sizeof(cdose));
    new_dose->value = new_color;
    new_dose->next = *pb;
    *pb = new_dose;
}

/*
@requires *pb must be initialized and must end
@assigns free the heap from color doses
@ensures free the heap from all the color doses included in the bucket pointed by pb
*/
void free_cbucket(cbucket *pb){
    cbucket tmp;
    while (*pb != NULL){// as required, the bucket has to finish, and since we are mooving at the next dose every time, *pb will eventually be NULL
        tmp = (*pb)->next;
        free(*pb);
        *pb = tmp;
    }
}

/*
@requires bucket must be initialized and finshed
@assigns nothing
@ensures print all the colors from the cbucket bucket
*/
void print_cbucket(cbucket bucket){
    printf("[ ");
    while (bucket != NULL){// the bucket is finished, and we keep going further in the doses, therefore we will reach the bottom
        print_color(bucket->value);
        printf(" ");
        bucket = bucket-> next;
    }
    printf("]");
}

/*
@requires nothing
@assigns create a new obucket
@ensures create an empty opacity bucket = NULL
*/
obucket init_obucket(){
    obucket new_bucket = NULL;
    return new_bucket;
}

/*
@requires new_opacity and *pb must be correctly initialized
@assigns allocates memory for a new odose in the heap and changes pb
@ensures add a new dose of opacity new_opacity at the top of the obucket pointed by pb
*/
void addo(opacity new_opacity, obucket *pb){
    odose *new_dose = malloc(sizeof(odose));
    new_dose->value = new_opacity;
    new_dose->next = *pb;
    *pb = new_dose;
}

/*
@requires pb must be initialized and has to end
@assigns free the heap from odoses
@ensures free the heap from all the opacity doses of the obucket pointed by pb
*/
void free_obucket(obucket *pb){
    obucket tmp;
    while (*pb != NULL){// as required, the bucket has to finish, and since we are mooving at the next dose every time, *pb will eventually be NULL
        tmp = (*pb)->next;
        free(*pb);
        *pb = tmp;
    }
}

/*
@requires pb must be initialized and has to end
@assigns nothing
@requires displays all the opacities of the obucket bucket
*/
void print_obucket(obucket bucket){
    printf("[ ");
    while (bucket != NULL){// as required, the bucket has to finish, and since we are mooving at the next dose every time, *pb will eventually be NULL
        printf("%d ",bucket->value);
        bucket = bucket-> next;
    }
    printf("]");
}