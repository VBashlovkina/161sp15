#include <stdio.h>
#include "MyroCDev.h"

/* program to take several readings of the Scribbler 2 light sensors
   from robots noyce and perlis

   compile this program with the line

     gcc -lbluetooth -lMyroCDev -o light-compareDev light-compareDev.c
*/

int main ()
{
  /* preliminaries */
  printf ("reporting readings of the Scribbler 2 light sensors\n");
  int noyce  = rConnect ("365786");
  int perlis = rConnect ("245787");

  /* take readings alternately from the two robots */
  rSetConnection (noyce);
  int noyceValue1 = rGetLightTxt("left", 1);
  rSetConnection (perlis);
  int perlisValue1 = rGetLightTxt("left", 1);

  rSetConnection (noyce);
  int noyceValue2 = rGetLightTxt("left", 1);
  rSetConnection (perlis);
  int perlisValue2 = rGetLightTxt("left", 1);

  rSetConnection (noyce);
  int noyceValue3 = rGetLightTxt("left", 1);
  rSetConnection (perlis);
  int perlisValue3 = rGetLightTxt("left", 1);

  /* report results */
  printf ("readings from left light sensors from robots perlis and noyce\n");
  printf ("                 noyce     perlis\n");
  printf ("reading 1: %11d     %6d\n", noyceValue1, perlisValue1);
  printf ("reading 2: %11d     %6d\n", noyceValue2, perlisValue2);
  printf ("reading 3: %11d     %6d\n", noyceValue3, perlisValue3);

  return 0;
}

