/*******
 * square-move-4.c
 * 
 * Program uses a struct containing an array of doubles and an int to move
 *   in a square.
 *
 * Author: April O'Neill  4 August 2011
 * Edited: Erik Opavsky   4 August 2011
 * Revised:  Henry M. Walker 15 March 2012
 * 
 *******/

#include <stdio.h>
#include "MyroC.h"

/* declare struct that can be used in procedures and main */
typedef struct {
  double speed;
  double time;
} movement;


/* set speed and action for a move by the Scribbler 2 robot */
/* must pass address of pointer to get values out of procedure */
void initialize (movement *move, int index)
{
  (*move).speed = 1 - (.1 * index);
  (*move).time = (index / 2.0) + 0.5;
}

/* print values in movement struct */
void printMove (movement move)
{
  printf ("robot action:  time = %lf,   speed = %lf\n", move.time, move.speed);
}

/* move robot */
void moveRobot (movement move [], int size)
{
  int i;
  for (i = 0; i < size; i++)
    {
      rForward (move[i].speed, move[i].time);
      /* Command to make a (roughly) 90 degree turn to the left */
      rTurnLeft (1, 0.8);
    }
}

int main()
{
  rConnect ("/dev/rfcomm0");
  rSetForwardnessTxt ("fluke-forward");

  int i; 

  /* Declares an array of 8 movement structs */
  movement actions[8];

  /* Loop to initialize the values in the structs */
  for (i = 0; i < 8; i++)
    {
      initialize (&actions[i], i);
    }

  /* Loop to print the Scribbler times and speed(s). */
  for (i = 0; i < 8; i++)
    {
      printMove (actions[i]);
    }

    moveRobot (actions, 8);

  rBeep (1, 600);

  rDisconnect();
  return 0;
} // main
