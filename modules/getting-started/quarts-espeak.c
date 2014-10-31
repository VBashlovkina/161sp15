/* A simple program to convert a number of quarts to liters
   eSpeak added to announce steps of processing
*/

#include <stdio.h>                    /* reference to standard I/O library */
#include "eSpeakPackage.h"

/* declarations */
int quarts; 
double liters;

int main ()                           /* beginning of main program */
  {  
    eSpeakConnect();                  /* set up eSpeak speech synthesizer */

    eSpeakTalk ("starting program");  /* convert string to spoken text */
    printf ("This program converts a number of quarts to liters\n");  

    eSpeakSetGender("female");        /* set gender female */
    eSpeakTalk ("Computing values");  /* annouce this code segment */
    quarts = 2;                       
    liters = quarts / 1.056710 ;      

    eSpeakTalk ("printing        ");  /* announce next code segment */
    printf ("%d quarts = %lf liters\n", quarts, liters);

    eSpeakSetGender("male");
    eSpeakTalk ("program done");      /* last announcement */
    eSpeakDisconnect ();              /* work with eSpeak completed */

    return 0;                        
  }
