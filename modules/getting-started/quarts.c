/* A simple program to convert a number of quarts to liters
   Version 1:  global variables only
*/

#include <stdio.h>                    /* reference to standard I/O library */

int quarts;                           /* declarations */
double liters;                        /* double = real */

int main ()                           /* beginning of main program */
  {  printf ("This program converts a number of quarts to liters\n");  
                                      /* write opening statement */

    quarts = 2;                       /* specify the number of quarts as 2 */

    liters = quarts / 1.056710 ;      /* arithemtic, assignment */

    printf ("%d quarts = %lf liters\n", quarts, liters);
                                      /* write text and new line */

    return 0;                        /* the program ran without errors */
  }
