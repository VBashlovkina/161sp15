#include <stdio.h>
#include "MyroC.h"

/* program to take several readings of the Scribbler 2 light sensors

   compile this program with the line

     gcc -lMyroC -o light-MyroC-switch light-MyroC-switch.c
*/

int main ()
{
  /* preliminaries */
  printf ("reporting readings of the Scribbler 2 light sensors\n");
  rConnect ("/dev/rfcomm0");

  /* part 1:  take readings and report */
  /* take readings */
  int value1 = rGetLightTxt("left");
  int value2 = rGetLightTxt("left");
  int value3 = rGetLightTxt("left");
  int avgValue = (value1 + value2 + value3)/3;

  /* report results */
  printf ("reading 1 for left sensor: %d\n", value1);
  printf ("reading 2 for left sensor: %d\n", value2);
  printf ("reading 3 for left sensor: %d\n", value3);

  printf ("average reading:  %d\n", avgValue);

  /* part 2:  report if reading is bright */
  /* illustrate simple if statement */
  if (avgValue < 10000)
    {
      printf ("light in area is bright\n");
    }

  /* illustrate if else statement */
  if (avgValue < 5000)
    {
      printf ("light in area is very bright\n");
    }
  else 
    {
      printf ("sunglasses are not needed for this light\n");
    }

  /* part 3:  categorize amount of light in area */
  /* illustrate switch sequence */
  int ten_thousands = avgValue / 10000;
  switch (ten_thousands) 
    {
    case 0:  printf ("light is quite bright\n");
             break;
    case 1:  printf ("light is moderately bright\n");
             break;
    case 2:  printf ("light is somewhat bright\n");
             break;
    case 3:  printf ("light is somewhat dim\n");
             break;
    default: printf ("light is quite dim\n");
             break;
    }

  /* finish up */
  rDisconnect ();
  return 0;
}
