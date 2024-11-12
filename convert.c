/* Sehaj Ajimal, 400511220, 2024
 * SE 2XC3 C Basics Assignment
 * The purpose of this utility is to convert an integer to a specific basic and send it to standard output
 * Using the -b flag allows you to convert to a base 1 < b < 37 otherwise base 16 is used.
 * Using the -r flag allows me to specify a range and without that it will accept integers one at a time otherwise it will check the integers once at a time until end of file is reached.
 */

#include <stdlib.h>
#include <stdio.h>
#include "convert.h"

/* Main
 *
 * Takes car of initialization of certain variables (no base specified, so base = 16)(if user does help flag then will assign it to true later)
 * Calls necessary functions which are in the convert2.c file (Processes converting the number)
 * 
**/
int main(int argc, char *argv[]) 
{
    int newBase = 16;                                                    
    int helpFlag = 0;                                                  
    long start = 0;
    long finish = 0;                                      

    conversionProcessor(newBase, helpFlag, start, finish);                   
   
    return EXIT_SUCCESS;
}


