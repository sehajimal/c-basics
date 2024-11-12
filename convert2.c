/* Sehaj Ajimal, 400511220, 2024
 * second .c file which is used to make the code more modular and contains all of the functions outside of main
 * includes the help function which goes beyond the usage string to explain the function
 * 
 **/


#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "convert.h"



//function for when user does help flag
void help() {
    printf("Usage: convert [-b BASE] [-r START FINISH]\n");
    printf("        1 < BASE < 37\n");
    printf("        START and FINISH are long integers\n\n");

    printf("2 optional flags allowed:\n");
    printf("    -r START FINISH     This will allow 'convert' to output a range of conversions of long integers [START,FINISH] and then exit.\n");
    printf("                        If -r is not used 'convert' will accept integers form standard input once at a time until EOF is reached.\n");
    printf("    -b BASE             This tells 'convert' which base to do the conversion to.\n");
    printf("                        If base is higher thanBases higher than 10 use capital letters A-Z to represent digit values 11 through 36.\n");
    printf("                        If -b is not used then it will do the conversion to base 16.\n\n");
    printf("Testing the utility example:\n");
    printf("    convert -b 2             Will convert the integers to base 10 given from standard input.\n");
    printf("    convert -b 2 -r 2 9      Will convert integers [2,9] to base base 2.\n\n");
}