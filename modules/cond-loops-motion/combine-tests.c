/*
 * combine-tests.c
 *
 * This program will demonstrate the usefulness of the && and || operators.
 * Further, it should demonstrate the need to gather all the sensor data you 
 * need before acting upon it.
 */

#include "MyroC.h"

int
main (int argc, char ** argv)
{
  rConnect("/dev/rfcomm0");

  int left  = rGetIRTxt ("left");
  int right = rGetIRTxt ("right");
  
  if ( left )
    rTurnRight (1, 1);
  else if ( right )
    rTurnLeft (1, 1);
  
 rDisconnect();
  return 0;
}
