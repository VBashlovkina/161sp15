/* * * * *
 * array-index.c
 *
 * Make the Scribbler move in different speeds and times by putting 
 * different numbers to different arrays and giving them 
 * as parameters to the commands forward and turn.
 *
 * Authors: Dilan Ustek, Erik Opavsky
 * Modified for this lab: Dilan Ustek, 8 July 2011
 *
 * Further modifications:  Henry M. Walker, 29 October 2011
 * 
 */

#include "MyroC.h"

int
main()
{

  rConnect ("/dev/rfcomm0");
  rSetForwardnessTxt("scribbler-forward");

  int i;

  /* the various speeds and times in two seperate arrays */
  double speed[] = {.3, .2, .4, 1, 1, .3, .2, .5};

  /* Since the array declaration supplies 8 numbers, this could also be declared
        double speed[8] = {.3, .2, .4, 1, 1, .3, .2, .5};

     If array size is more than 8, more space is allocated, but only 
     the first part of the array is initialized:
        double speed[10] = {.3, .2, .4, 1, 1, .3, .2, .5};
  */

  /* go forward and turn for the various speeds given by the speed array */
  rForward (speed[0], 0.5);
  rTurn (speed[1], 0.5);
  rForward (speed[2], 0.5);
  rTurn (speed[3], 0.5);
  rForward (speed[4], 0.5);
  rTurn (speed[5], 0.5);
  rForward (speed[6], 0.5);
  rTurn (speed[7], 0.5);

  /* beep when done */
  rBeep (1, 500);

  rDisconnect();

  return 0;
} /* main */
