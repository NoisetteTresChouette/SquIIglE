Hello World !

Here is SquIIgglE manual.

NAME
    ./SquIIgglE.exe - draw and return a P6 ppm file based 
    on an ipi input. You can reload the exec SquIIgglE 
    thanks to the command make in the main directory.

SYNOPSIS
    ./SquIIgglE.exe [OPTION FILE]

DESCRIPTION
    Read stdin as an IPI (cf NOTE) format, and write in the stdout 
    the corresponding PPM format.
    This program only work on Linux.

OPTION
    input 
        if the option input is specified, the file precised
        after input will be read instead of the stdin.
    
    output
        if the option output is specified, the PPM will be
        written in the file indicated after output instead
        of the stdout. Moreover, this file name will be 
        printed in the stdout.
    
NOTE
    IPI format
        IPI format is used to describe the construction of
        a square image.

        In such a file, there is first the lenght of the 
        picture written on the first line, and the a 
        sequence of characters. If said characters are one
        of the following 'abcefghijlmnoprstvwy', they 
        correspond to commands, else, they will be skipped.
        Therefore, it is recommanded to use capital letters to
        comment an IPI file.

        In order to understand IPI format, you should 
        consider a canvas with initally 1 layer, and a 
        maximum of 10, a cursor facing East place at the 
        coordinates (0,0), a marked position first being 
        (0,0), a bucket of colors, and a bucket of opacity.
        A layer is composed of pixels defined by a color and
        an opacity.

        Here are the different commands:

        n 
            Add black to the color bucket.
        r 
            Add red to the color bucket.
        g
            Add green to the color bucket.
        b 
            Add blue to the color bucket.
        y
            Add yellow to the color bucket.
        m
            Add magenta to the color bucket.
        c 
            Add cyan to the color bucket.
        w 
            Add white to the color bucket.
        t 
            Add transparency to the opacity bucket.
        o 
            Add the opaque opacity to the opacity bucket.
        i
            Empty both buckets.
        v
            Moove the cursor 1 pixel toward its direction.
        h
            Rotate the cursor 90 degrees clockwise.
        a
            Rotate the cursor 90 degrees anticlockwise.
        p
            Set the marked position to the cursor position.
        l
            Draw a line from the marked position to the 
            cursor, using as an opacity the average of the
            opacity bucket, and as a color the average of
            the color bucket multiplied by the later opacity
            divided by 255. The color is black by default,
            and the opacity is opaque.
        f
            Fill the area around the cursor position of the
            same color than the pixel here with a new pixel,
            using as an opacity the average of the
            opacity bucket, and as a color the average of
            the color bucket multiplied by the later opacity
            divided by 255. The color is black by default,
            and the opacity is opaque.
        s
            Add a new black transparent layer on top of the 
            canvas.
        e
            Merge the two layer on top of the canvas.
        j
            Cut the second most higher layer of the canvas,
            using the one at the top as an opacity mask.
            It gets rid of the layer at the top.
        
        The image associated with this IPI file is the top
        layer of the canvas obtained after all the commands
        were executed.

ERRORS
    if the wrong number of arguments is given
        "SquIIgglE Error, wrong number of arguments:%d given", %d = number of arguments
    if one parameter isn't "input" nor "output"
        "SquIIggle Error, unknown parameter %s", %s = specific parameter
    if both parameters are "input" or "output"
        "SquIIgglE Error, redundant parameter %s", %s = redundant parameter