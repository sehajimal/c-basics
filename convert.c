/* Sehaj Ajimal, 400511220, 2024
 * SE 2XC3 C Basics Assignment
 * The purpose of this utility is to convert an integer to a specific base and send it to standard output
 * Using the -b flag allows you to convert to a base 1 < b < 37 otherwise base 16 is used.
 * Using the -r flag allows me to specify a range and without that it will accept integers one at a time until end of file is reached.
 */

#include <stdlib.h>
#include <stdio.h>
#include "convert.h"

/* Main
 *
 * Takes care of initialization of certain variables (no base specified, so base = 16)
 * Calls necessary functions which are in the convert2.c file (Processes converting the number)(interpreting the command line options and arguments)
 * 
**/
int main(int argc, char *argv[]) 
{
    int newBase = 16;                                       //beginning values used but will be changed in the interpretParamaters function                            
    long start = 0;
    long finish = 0;   
    
    interpretParamaters(argc, argv, &newBase, &start, &finish);                                   

    conversionProcessor(newBase, start, finish); 
}


