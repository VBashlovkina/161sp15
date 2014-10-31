#include "MyroC.h"
#include <stdio.h>

/*
 * Program to find a object, and follow it if it moves (e.g. paper used as "wall")
 * This uses the Scribbler 2 IR sensors.
 *
 * Authors: April O'Neill & Erik Opavsky
 *
 *
 * Date: 7/8/11
 */

int
main()
{
  rConnect("/dev/rfcomm0");
  rSetForwardnessTxt ("scribbler-forward");

  int IRs[2];

  while (1)
    {
      rGetIRAll (IRs);

      if (!IRs[0] && !IRs[1] )        // if both sensors don't sense obstacles
        rForward (1,1);              // move forward for 1 second

      else  if (IRs[0] && !IRs[1] ) // if right senses obstacle and left doesn't
        rTurnRight (1, .2);          // turn right for 1 second
     
      else if (!IRs[0] && IRs[1] )  // if left senses obstacle and right doesn't
        rTurnLeft (1, .2);           // turn left for one second

      else if (IRs[0] && IRs[1] ) // if both sense obstacle
        sleep (1);                  // wait for one second

    } // while

  rDisconnect();
  return 0;
} // main
