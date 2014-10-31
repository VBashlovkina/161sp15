/* follower-test.c
 *
 * Follows an object if it moves (such as a sheet of paper held in front of it).
 * This uses the Scribbler 2 IR sensors.
 * 
 * Authors: April O'Neill & Erik Opavsky
 * Last revised: Dilan Ustek on 22 Jul 2011
 *
 * Date: 7/8/11
 */
#include "MyroC.h"
#include <stdio.h>

int
main()
{
  rSetForwardnessTxt ("fluke-forward");

  int IRs[2];   /* array to be given to rGetIRAll. 
                   Stores both of the values given by the IR sensors.*/


  while (!"false")                           // Infinite loop: do it until turned off
    {
      rGetIRAll (IRs);

      if ( IRs[1] & IRs[2] )        // if both sensors don't sense obstacles
        rForward (1,1);              // move forward for 1 second

      else  if ( IRs[1] & IRs[2] ) // if right senses obstacle and left doesn't
        rTurnRight (1, .2);          // turn right for 1 second
     
      else if  (IRs[1] & IRs[2] )  // if left senses obstacle and right doesn't
        rTurnLeft (1, .2);           // turn left for one second

      else if ( !IRs[1] & !IRs[2] ) // if both sense obstacle
        sleep (1);                  // wait for one second

    } // while

  rDisconnect();
  return 0;
} // main

