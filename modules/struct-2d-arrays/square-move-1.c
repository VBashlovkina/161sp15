/*******
 * square-move-1.c
 * 
 * Program uses a struct to store a move by the Scribbler 2 robot
 *  
 * Author:  Henry M. Walker
 * Date:  15 March 2012
 *
 * Motivated by an example by April O'Neill and Erik Opavsky
 * Date: 4 August 2011
 *******/

#include "MyroC.h"

int main()
{
  rConnect ("/dev/rfcomm0");
  rSetForwardnessTxt ("fluke-forward");

  typedef struct {
    double speed;
    double time;
  } movement;


  /* Declare information for one robot movement */
  movement action;

  /* Initialize the elements of a robot movement */
  action.speed = 0.8;
  action.time = 2.0;

  /* Command to move forward according to the speed and time stored
     in the struct */
  rForward ( action.speed, action.time);

  /* beep after movement */
  rBeep (1, 600);

  rDisconnect();
  return 0;
} // main
