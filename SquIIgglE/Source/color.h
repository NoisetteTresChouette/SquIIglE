#ifndef COLOR_H
#define COLOR_H

#include <stdio.h>

typedef struct color{
    unsigned char R;
    unsigned char G;
    unsigned char B;
} color;

typedef unsigned char opacity;

/*
@requires c must be initialized
@assigns nothing
@ensures displays the values of the different components of c such as color{R:c.R/G:c.G/B:c.B}
*/
void print_color(color c);

/*
@requires c must one of the following : 'n','r','g','b','y','m','c','w'
@assigns set a new color
@ensures return a color corresponding to the char: 'n' black, 'r' red, 'g' green, 'b' blue, 'y' yellow, 'm' magenta, 'c' cyan, 'w' white
*/
color char_color(char c);

/*
@requires c must be 't' or 'o'
@assigns set a new opacity
@ensures returns the transparent opacity 0 if c=='t', and full opacity 255 if c=='o'
*/
opacity char_opacity(char c);

#endif