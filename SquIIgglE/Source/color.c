#include <stdio.h>

#include "color.h"

/*
@requires c must be initialized
@assigns nothing
@ensures displays the values of the different components of c such as color{R:c.R/G:c.G/B:c.B}
*/
void print_color(color c){
    printf("color{R:%d/G:%d/B:%d}",c.R,c.G,c.B);
}

/*
@requires c must one of the following : 'n','r','g','b','y','m','c','w'
@assigns set a new color
@ensures return a color corresponding to the char: 'n' black, 'r' red, 'g' green, 'b' blue, 'y' yellow, 'm' magenta, 'c' cyan, 'w' white
*/
color char_color(char c){
    color color_return;
    switch(c){
        case 'n' :
            color_return.R = 0;
            color_return.G = 0;
            color_return.B = 0;
            break;
        case 'r':
            color_return.R = 255;
            color_return.G = 0;
            color_return.B = 0;
            break;
        case 'g' :
            color_return.R = 0;
            color_return.G = 255;
            color_return.B = 0;
            break;
        case 'b' :
            color_return.R = 0;
            color_return.G = 0;
            color_return.B = 255;
            break;
        case 'y' :
            color_return.R = 255;
            color_return.G = 255;
            color_return.B = 0;
            break;
        case 'm' :
            color_return.R = 255;
            color_return.G = 0;
            color_return.B = 255;
            break;
        case 'c' :
            color_return.R = 0;
            color_return.G = 255;
            color_return.B = 255;
            break;
        case 'w' :
            color_return.R = 255;
            color_return.G = 255;
            color_return.B = 255;
            break;
    }
    return color_return;
}

/*
@requires c must be 't' or 'o'
@assigns set a new opacity
@ensures returns the transparent opacity 0 if c=='t', and full opacity 255 if c=='o'
*/
opacity char_opacity(char c){
    opacity opacity_return;
    if (c == 't') opacity_return = 0;
    else if (c == 'o') opacity_return = 255;
    return opacity_return;
}