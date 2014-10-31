#include <stdio.h>
#include "MyroCDev.h"

/* program to take several readings of the Scribbler 2 light sensors

   compile this program with the line

     gcc -lbluetooth -lMyroCDev -o light-MyroCDev light-MyroCDev.c
*/

int main ()
{
  /* preliminaries */
  printf ("reporting readings of the Scribbler 2 light sensors\n");
  rConnect ("/dev/rfcomm0");
  //rConnect ("00:1E:19:01:0E:88");
  //rConnect ("0958");

  /* part 1:  take readings and report */
  /* take readings */
  int value1 = rGetLightTxt("left", 1);
  int value2 = rGetLightTxt("left", 1);
  int value3 = rGetLightTxt("left", 1);
  int avgValue = (value1 + value2 + value3)/3;

  /* report results */
  printf ("reading 1 for left sensor: %d\n", value1);
  printf ("reading 2 for left sensor: %d\n", value2);
  printf ("reading 3 for left sensor: %d\n", value3);

  printf ("average of first three reading:  %d\n", avgValue);
  printf ("separate average of three reading:  %d\n", rGetLightTxt("left", 3));


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
  /* illustrate else if sequence */
  if (avgValue < 10000)
    {
      printf ("light is quite bright\n");
    }
  else if (avgValue < 20000)
    {
      printf ("light is moderatlely bright\n");
    }
  else if (avgValue < 30000)
    {
      printf ("light is somewhat bright\n");
    }
  else if (avgValue < 40000)
    {
      printf ("light is somewhat dim\n");
    }
  else
    {
      printf ("light is quite dim\n");
    }

  /* finish up */
  rDisconnect ();
  return 0;
}
