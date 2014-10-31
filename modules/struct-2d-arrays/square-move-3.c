/*******
 * square-move-3.c
 * 
 * Program uses a struct containing an array of doubles and an int to move
 *   in a square.
 *
 * Author: April O'Neill
 * Edited: Erik Opavsky
 *
 * Date: 4 August 2011
 *******/

#include "MyroC.h"

int
main()
{
  rConnect ("/dev/rfcomm0");
  rSetForwardnessTxt ("fluke-forward");

  int i; 

  typedef struct {
    double speed;
    double time;
  } movement;


  /* Declares an array of 8 movement structs */
  movement actions[8];

  /* Loop to initialize the values in the structs */
  for (i = 0; i < 8; i++)
    {
      /* Sets a constant speed for all actions */
      actions[i].speed = 1 - (.1 * i);

      /* Sets the time for each action to increase by half a second */
      actions[i].time = (i / 2.0) + 0.5;
    }

  /* Loop to move the Scribbler according to the structs stored times
     and speed(s). */
  for (i = 0; i < 8; i++)
    {
      /* Command to move forward according to the speed and time stored
         in the struct in the array position i */
      rForward ( actions[i].speed, actions[i].time);

      /* Command to make a (roughly) 90 degree turn to the left */
      rTurnLeft (1, 0.8);
    }

  rBeep (1, 600);

  rDisconnect();
  return 0;
} // main
