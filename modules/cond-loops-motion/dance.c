/********************
 * dance.c
 *
 * Program to make the Scribbler 2 robot dance with basic motion commands.
 *
 * Author: April O'Neill
 *
 * Date: July 21, 2011
 ********************/

#include "MyroC.h"

int
main()
{ /* connect to the Scribbler 2 robot */
  rConnect("/dev/rfcomm0");

  /* flourish:  move the robot left, right, and left to start the dance */
  rTurnLeft (.75, .55);   /* turn left at speed 0.75 (max speed 1.0)
                             for a time interval of 0.55 seconds */
  rTurnRight (.75, 1.05); /* turn right at speed 0.75 (max speed 1.0)
                             for a time interval of 1.05 seconds */
  rTurnLeft (.75, .5);
  sleep (1);              /* rest (do nothing) for 1 second; times for
                             sleep must be integers */

  rForward(1.0, 4.0);     /* move forward (straight) at full speed (1.0 max)
                             for 4 seconds */

  /* flourish, repeating previous flourish */
  rTurnLeft (.75, .55);
  rTurnRight (.75, 1.05);
  rTurnLeft (.75, .5);
  sleep (1);

  rBackward (1.0, 3.0);   /* move forward (straight) at full speed (1.0 max)
                             for 4 seconds */

  rTurnLeft (1.0, 1.7);

  rBackward (1.0, 3.0);
  
  /* flourish */
  rTurnLeft (.75, .55);
  rTurnRight (.75, 1.05);
  rTurnLeft (.75, .5);
  sleep (1);

  rTurnLeft (1.0, 1.7);

  /* break the connection with the Scribbler 2 robot */
  rDisconnect();
  return 0;
}
