/* Sehaj Ajimal, 400511220, 2024
 * Second .c file which is used to make the code more modular and contains all of the functions outside of main
 * Includes the help function which goes beyond the usage string to explain the function
 * Has a conversionProcessor which uses other recursive functions in order to handle all the tasks (convert the num)
 **/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "convert.h"

//interpreting the command line options and arguments
void interpretParamaters(int argc, char *argv[], int *newBase, long *start, long *finish) 
{
    for (int i = 1; i < argc; i++) 
    {
        if (!(*newBase > 1 || *newBase < 37))                              //values do not meet specification so call usage
        {
            usage();
        }

        if (strcmp(argv[i], "-b") == 0 && argc > i + 1)              //converting to int using atoi and making sure that a value is given with -b (base)
        {
            i = i+1;                                                //using the base number inputted
            *newBase = atoi(argv[i]);                                     
        }
                
        else if (strcmp(argv[i], "-r") == 0 && argc > i + 2)            //must have 6 command line paramaters in order to use -r so this checks that
        {
            i = i+1;
            *start = atol(argv[i]);

            i = i+1;  
            *finish = atol(argv[i]);
        } 

        else if (strcmp(argv[i], "--help") == 0) 
        { 
            help();                                     
        } 
        
        else 
        {
            usage();
        }
    }
}

//This function is in charge of processing the tasks of converting the number specified
void conversionProcessor(int newBase, long start, long finish) 
{
    if (start<finish)                                           //using if else in order to also be able to get input form standard in (else block).
    {
        for (long i = start; i <= finish; i++)              //loop iterates for all the values in the range of start and finish
        {
            conversionRecursivley(i, newBase);
            putchar('\n');

        }
    }
    
    else
    {
        while (true)                                                 //accepts standard input until EOF
        {
            long i;
            int value = scanf("%ld", &i);
            if (value == EOF) 
            {
                break;  
            } 

            else if (value != 1)                                           //Non-long-int token encountered.
            {
                printf("Error: Non-long-int token encountered.\n");
            }

            conversionRecursivley(i, newBase);
            putchar('\n');

        }
    }
}

//Function used to convert the long int to a new base recursively and send to standard output one character at a time.
void conversionRecursivley(long usersNumber, int newBase) 
{
    if (usersNumber < 0) 
    {
        putchar('-');
        usersNumber = -usersNumber;                               //done to process the final number 
    }

    int remainder = usersNumber % newBase; 
    int quotient = usersNumber / newBase;  

    if (quotient != 0)                                          //waits until quotient is zero
    {
        conversionRecursivley(quotient, newBase); 
    }
    
    if (remainder < 10)                                     //either will be number or alphabet
    {
        printf("%c", '0' + remainder);
    } 
    
    else 
    {
        printf("%c", 'A' + (remainder - 10));
    }
}

//function for when user does help flag
void help() 
{
    printf("Usage: convert [-b BASE] [-r START FINISH]\n");
    printf("        1 < BASE < 37\n");
    printf("        START and FINISH are long integers\n\n");
    printf("Testing the utility example:\n");
    printf(" {convert -b 2 -r -3 3}   This will convert the integers from the range -3 to 3 to base 2.\n");
    printf(" Can use 2 flags {-b Base} and {-r Start finish}\n");
    printf(" the flag {-r Start finish} will allow 'convert' to output a range of conversions of long integers [START,FINISH]. Without it it will use standard input\n");
    printf(" The {-b Base} flag tells 'convert' which base to do the conversion to. And not using it will automatically convert to base 16\n");
}

//usage string
void usage() 
{
    fprintf(stderr,"Usage: convert [-b BASE] [-r START FINISH]\n");
    fprintf(stderr,"       1 < BASE < 37\n");
    fprintf(stderr,"       START and FINISH are long integers\n");
}