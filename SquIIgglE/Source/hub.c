#include "draw.h"
#include "cursor.h"
#include "canvas.h"

/*
@requires str1 and str2 must be initialized
@assigns set a new char
@ensures returns 1 if both strings have all their characters identical, 0 other wise
*/
char str_equals(char *str1,char *str2){
    int i=0;
    while (str1[i] != '\0' && str2[i] != '\0'){
        if (str1[i] != str2[i]) return 0;
        i ++;
    }
    if (str1[i] != str2[i]) return 0;
    else return 1;
}

int main(int argc, char *argv[]){

    int custom_input = 0;// if the parameter "input" is used, custom_input will be set to the index of the input file in argv, it will stay to 0 otherwise
    int custom_output = 0;// if the parameter "output" is used, custom_output will be set to the index of the output file in argv, it will stay to 0 otherwise

    if (argc != 1 && argc != 3 && argc != 5){
        fprintf(stderr,"SquIIgglE Error, wrong number of arguments:%d given",argc);
        return 1;// return 1 to state an Error
    }

    if (argc == 3){
        if (str_equals(argv[1],"input")) custom_input = 2;
        else if (str_equals(argv[1],"output")) custom_output = 2;
        else{
            fprintf(stderr,"SquIIggle Error, unknown parameter %s",argv[1]);
            return 1;
        }
    }

    if (argc == 5){
        if (str_equals(argv[1],argv[3])){
            fprintf(stderr,"SquIIgglE Error, redundant parameter %s",argv[1]);
            return 1;
        }
        if (str_equals(argv[1],"input")) custom_input = 2;
        else if (str_equals(argv[1],"output")) custom_output = 2;
        else{
            fprintf(stderr,"SquIIggle Error, unknown parameter %s",argv[1]);
            return 1;
        }
        if (str_equals(argv[3],"input")) custom_input = 4;
        else if (str_equals(argv[3],"output")) custom_output = 4;
        else{
            fprintf(stderr,"SquIIggle Error, unknown parameter %s",argv[3]);
            return 1;
        }
    }

    FILE *commands;

    if ( custom_input == 0) commands = stdin;
    else commands = fopen(argv[custom_input],"r");

    char str_size[256];
    fgets(str_size,256,commands);
    int size;//this will be the size of my image, and therefor of my canvas and its layers
    sscanf(str_size,"%d",&size);

    int set_x = 0;
    int set_y = 0;//these are the coordinates marked by the 'p' command
    cursor cur = init_cursor(size);
    cbucket cb = init_cbucket();
    obucket ob = init_obucket();
    canvas can = init_canvas(size);
    add_layer(&can);//the canvas should initally have one layer

    char command = fgetc(commands);
    while (command != EOF){//every cycle we are doing one fgetc, which makes the input file cursor shift from one character, eventually reaching the end. When it happens, command will be set to EOF, finishing the loop.
        switch(command){
            case 'n' :
                addc(char_color(command),&cb);
                break;
            case 'r' :
                addc(char_color(command),&cb);
                break;
            case 'g' :
                addc(char_color(command),&cb);
                break;
            case 'b' :
                addc(char_color(command),&cb);
                break;
            case 'y' :
                addc(char_color(command),&cb);
                break;
            case 'm' :
                addc(char_color(command),&cb);
                break;
            case 'c' :
                addc(char_color(command),&cb);
                break;
            case 'w' :
                addc(char_color(command),&cb);
                break;
            case 't' :
                addo(char_opacity(command),&ob);
                break;
            case 'o' :
                addo(char_opacity(command),&ob);
                break;
            case 'i' :
                free_cbucket(&cb);
                free_obucket(&ob);
                break;
            case 'v' :
                moove(&cur);
                break;
            case 'h' :
                clock_rotate(&cur);
                break;
            case 'a' :
                aclock_rotate(&cur);
                break;
            case 'p' :
                set_x = cur.x;
                set_y = cur.y;
                break;
            case 'l' :
                draw_line(set_x,set_y,cur.x,cur.y,calculate_pixel(cb,ob),&(can.layers[can.nb_layers-1]));
                break;
            case 'f' :
                fill(cur.x,cur.y,calculate_pixel(cb,ob),&(can.layers[can.nb_layers-1]));
                break;
            case 's' :
                add_layer(&can);
                break;
            case 'e' :
                merge_layers(&can);
                break;
            case 'j' :
                cut_layer(&can);
                break;
        }
        command = fgetc(commands);
    }
    fclose(commands);// We don't use commands anymore, we should not forget to close the file

    layer top_layer = can.layers[can.nb_layers-1];

    if (custom_output == 0){
        printf("P6\n%d %d\n255\n",size,size);// We use P6 since it's lighter than P3
        for (int i=0; i<size; i++){
            for (int j=0; j<size; j++){
                printf("%c%c%c",top_layer.grid[i][j].C.R,top_layer.grid[i][j].C.G,top_layer.grid[i][j].C.B);
            }
        }
    }
    else{
        FILE  *foutput = fopen(argv[custom_output],"w");
        fprintf(foutput,"P6\n%d %d\n255\n",size,size);
        for (int i=0; i<size; i++){
            for (int j=0; j<size; j++){
                fprintf(foutput,"%c%c%c",top_layer.grid[i][j].C.R,top_layer.grid[i][j].C.G,top_layer.grid[i][j].C.B);
            }
        }
        fclose(foutput);//foutput is no longer used, it should be closed
        printf("%s\n",argv[custom_output]);
    }

    free_cbucket(&cb);
    free_obucket(&ob);
    free_canvas(&can);//as we used malloc, we should free the heap from the last allocated slots of the heap

    return 0;
}