/* * * * *
 * wall.c
 *
 * Scribbler moves until it sees a wall, then turns right, and stops at
 * the next obstacle seen.
 *
 * The program uses 800 as a threshold for obstacle being seen using 
 * getObstacle.
 *
 * Authors: April O'Neill, Dilan Ustek
 *
 * Date: 7 July 2011
 */

#include "MyroC.h"

/* if batteries are fresh, then the obstacle sensors typically identify
   an object at a level of about 800.  If batteries weaken, use a lower
   value
*/
const int obstacleLimit = 800;

int 
main()
{
  rConnect("/dev/rfcomm0");
 
  int i = 0;

  // loop to stop at the second obstacle seen
  while(i<2)
    {
      rForward(1.0,1.0);
      if (rGetObstacleTxt("center", 3)>obstacleLimit)//fixme
        {
          rTurnRight(1.0,1.0);
          i++;
        }
    }

  rDisconnect();

  return 0;
} // main
