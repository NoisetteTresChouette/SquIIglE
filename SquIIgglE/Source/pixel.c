#include "bucket.h"
#include "pixel.h"

/*
@requires nothing
@assigns add a new pixel
@ensures create a new transparent black pixel
*/
pixel init_pixel(){
    pixel new_pixel;
    new_pixel.C = char_color('n');
    new_pixel.O = 0;
    return new_pixel;
}

/*
@requires p must be initialized with a color and an opacity
@assigns nothing
@ensures displays the pixel p like so: #C:p.C|O:p.O#
*/
void print_pixel(pixel p){
    printf("#C:");
    print_color(p.C);
    printf("|O:%d#",p.O);
}

/*
@requires both pixels p1 and p2 must be fully initialized
@assigns create a new unsigned char
@ensures return 1 if p1 and p2 have all their components equal, 0 otherwise
*/
char pixel_equals(pixel p1, pixel p2){
    if (p1.C.R != p2.C.R) return 0;
    if (p1.C.G != p2.C.G) return 0;
    if (p1.C.B != p2.C.B) return 0;
    if (p1.O != p2.O) return 0;
    return 1;
}

/*
@requires both buckets must be initialized and finished
@assigns create a new pixel
@ensures create a new_pixel with its opacity being the average of opacities or 255 if this later is empty, and its color being black if colors is empty, or its opacity/255 times colors average for each color component
*/
pixel calculate_pixel(cbucket colors, obucket opacities){
    pixel new_pixel;
    if (opacities == NULL) new_pixel.O = 255;
    else {
        int len_o = 0;
        int sum_o = 0;
        while (opacities != NULL){// opcaities being finished and going for the next cell every times, we can be certain that this loop will end
            len_o ++;
            sum_o += opacities->value;
            opacities = opacities->next;
        }
        new_pixel.O = sum_o / len_o;
    }
    if (colors == NULL) new_pixel.C = char_color('n');
    else {
        int len_c = 0;
        int sum_R = 0;
        int sum_G = 0;
        int sum_B = 0;
        while (colors != NULL){// colors being finished and going for the next cell every times, we can be certain that this loop will end
            len_c ++;
            sum_R += (colors->value).R;
            sum_G += (colors->value).G;
            sum_B += (colors->value).B;
            colors = colors->next;
        }
        new_pixel.C.R = new_pixel.O*sum_R/(255*len_c);
        new_pixel.C.G = new_pixel.O*sum_G/(255*len_c);
        new_pixel.C.B = new_pixel.O*sum_B/(255*len_c);
    }
    return new_pixel;
}