/* * * * *
 * array-move.c
 *
 * Make the Scribbler move in different speeds and times by putting different numbers to different 
 * arrays and giving them as parameters to the commands rForward and rTurn.
 *
 * Authors: Dilan Ustek, Erik Opavsky
 *
 * Date: 8 July 2011
 */


#include "MyroC.h"

int
main()
{

  rConnect("/dev/rfcomm0");
  rSetForwardnessTxt("fluke-forward");

  int numMoves = 8; // the number of moves that the Scribbler will do.
  int i;

  // the various speeds and times in two seperate arrays

  double speed[] = {.3, .2, .4, 1, 1, .3, .2, .5};

  double time[] = {.3, 1, .6, .1, 1, .9, .3, .8};

  double speedTime[2][8] = {{speed[8]},
                            {time[8]}};

  // go forward and turn for the various speeds and times given by the two arrays
  for (i = 0; i < numMoves; i++)
    {
      printf ("speedTime:  [0][%d]:  %d ;  [1][%d] :  %d\n:, i,  speedTime[0][i], speedTime[1][i]);
      rForward (speedTime[0][i], speedTime[1][i]);
      rTurn (speedTime[0][i], speedTime[1][i]);
    }
  
  // beep when done
  rBeep (1, 500);

  rDisconnect();

  return 0;
} // main
