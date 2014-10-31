#include "MyroC.h"
#include <stdio.h>

/*
 * Program to find a object, and follow it if it moves (e.g. paper used as "wall")
 * This uses the Scribbler 2 IR sensors.
 *
 * Authors: April O'Neill & Erik Opavsky
 *
 * Date: 7/8/11
 */

int
main()
{
  rConnect ("/dev/rfcomm0");
  rSetForwardnessTxt ("scribbler-forward");
 
  int left;
  int right;

  while (1)
    {
      left = rGetIRTxt ("left");
      right = rGetIRTxt ("right");

      printf ("left = %d", left);
      printf ("\tright = %d\n", right);

      switch (left + 2*right) 
        { case 0: /* no obstacle */
            printf ("moving forward\n");
            rForward (1,1);
            break;
        case 1: /* left blocked */
            printf ("turning right\n");
            rTurnRight (1, .2);
            break;
        case 2:  /* right blocked */
            printf ("turning left\n");
            rTurnLeft (1, .2);
            break;
        case 3: /* blocked ahead */
            printf ("no motion\n");
            sleep (1);
        }
    }

  rDisconnect();
  return 0;
} // main
