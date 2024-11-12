/* Sehaj Ajimal, 400511220, 2024
 * Second .c file which is used to make the code more modular and contains all of the functions outside of main
 * Includes the help function which goes beyond the usage string to explain the function
 * Has a conversionProcessor which uses other functions in order to handle all the tasks (convert the num)
 * 
 **/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "convert.h"

//This function is in charge of processing the tasks of converting the usersnumber
void conversionProcessor(int newBase, int helpFlag, long start, long finish) 
{
    if (helpFlag)                                                               //outputs help message
    {
        help();
    } 
    
    else if (finish > start)                                                    
    {  
        for (long usersNumber = start; usersNumber <= finish; usersNumber++) 
        {
            numberConverter(usersNumber, newBase);
        }
    } 
    
    else                                                                    //accepts standard input until EOF
    {  
        long usersNumber;

        while (true) 
        {
            int value = scanf("%ld", &usersNumber);
            if (value == EOF) 
            {
                break;  
            } 

            else if (value != 1)                                           //Non-long-int token encountered.
            {
                fprintf(stderr, "Error: Non-long-int token encountered.\n");
                exit(1);
            }

            convert_number(usersNumber, newBase);
        }
    }
}

//Function used to convert the long int to a new base
void numberConverter(long usersNumber, int newBase) 
{
    if (usersNumber < 0) 
    {
        printf('-');
        usersNumber = -usersNumber;                               //done to process the final number 
    }
    conversionRecursivley(usersNumber, newBase);
    printf('\n');
}

//process the number recursively and send the new representation to standard output one character at a time.
void conversionRecursivley(long usersNumber, int newBase) 
{
    int remainder = usersNumber % newBase; 
    int quotient = usersNumber / newBase;  

    if (quotient != 0) 
    {
        conversionRecursivley(quotient, newBase); 
    }
    
    printf(remainder < 10 ? '0' + remainder : 'A' + (remainder - 10));  
}

//function for when user does help flag
void help() 
{
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