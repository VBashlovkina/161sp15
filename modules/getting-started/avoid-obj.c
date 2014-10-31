/* * * * *
 * avoid-obj.c
 *
 * Scribbler moves around avoiding objects. It turns to the side that does not
 * have an object, or turns around if only obstacles are found with sensors.
 *
 * The program uses 800 as a threshold for obstacle being seen using getObstacle.
 *
 * Authors: April O'Neill, Dilan Ustek
 *
 * Date: 7 July 2011
 */

#include "MyroC.h"

int 
main()
{
  rConnect("/dev/rfcomm0");  
  rSetForwardnessTxt("fluke-forward");

  int array[3];
  int i;
  int iterations = 70; // move for a specific number of iterations
 
  // loop to move avoiding obstacles for a specified number of iterations
  for(i=0; i < iterations; i++)
    {
      rGetObstacleAll(array);

      // If no object seen, move forward
      if(array[1]<800 && array[2]<800 && array[3]<800)
        rMotors(1,1);

      // If object seen on left only, turn right
      else if(array[1]>800 && array[2]<800 && array[3]<800)
        rTurnRight(1,0.5);

      // If object seen only in middle, turn right
      else if (array[1]<800 && array[2]>800 && array[3]<800)
        rTurnRight(1,0.5);

      // If object seen only on right, turn left
      else if (array[1]<800 && array[2]<800 && array[3]>800)
        rTurnLeft(1,0.5);

      // If object seen on right and center, turn right
      else if (array[1]>800 && array[2]>800 && array[3]<800)
        rTurnRight(1,0.5);

      //If object seen on center and right, turn left
      else if (array[1]<800 && array[2]>800 && array[3]>800)
        rTurnLeft(1,0.5);

      // Else turn around
      else 
        {
          rBeep(1,600);
          rTurnRight(1,2);
        }
    } // End of loop

  rDisconnect();

  return 0;
} // main
