/*******
 * square-move-2.c
 * 
 * Program uses a struct to store a move by the Scribbler 2 robot
 * Procedures are used for initialization and use of the struct
 *  
 * Author:  Henry M. Walker
 * Date:  15 March 2012
 *
 * Motivated by an example by April O'Neill and Erik Opavsky
 * Date: 4 August 2011
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
void initialize (movement *move)
{
  (*move).speed = 0.8;
  (*move).time = 2.0;
}

/* print values in movement struct */
void printMove (movement move)
{
  printf ("robot action:  time = %lf,   speed = %lf\n", move.time, move.speed);
}

/* move robot */
void moveRobot (movement move)
{
  rForward (move.speed, move.time);
}

int main()
{
  rConnect ("/dev/rfcomm0");
  rSetForwardnessTxt ("fluke-forward");

  /* Declare information for one robot movement */
  movement action;

  /* Initialize, print, and execute a robot movement */
  initialize (&action);  /* address needed for getting struct out of procedure */
  printMove (action);
  moveRobot (action);

  /* beep after movement */
  rBeep (1, 600);

  //rDisconnect();
  return 0;
} // main
