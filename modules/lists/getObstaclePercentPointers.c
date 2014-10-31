/* * * * *
 * getObstaclePercentPointers.c
 *
 * Use functions to simplify data from the robot's sensors.
 *
 * getObstaclePercent gets the obstacle values from the IR sensors in the form
 * of an array where the first element is the left value and the second 
 * element is the value of the right sensor, and stores their percentage
 * distance in the double * triplet array that should be passed to it.
 * 
 * Preconditions:  a three element array (named triplet)
 * Postconditions: triplet contains the percentage distance an obstacle is from
 *                 the left sensor in the first index and from the right 
 *                 sensor in the second locations (indicies 0 and 1 respectively)
 *
 * Authors: David Cowden, Dilan Ustek
 * Date: 7 July 2011
 * Revised:  7 November 2011 by Henry M. Walker
 *
 */

#include "MyroC.h"
#include <stdio.h>

double * getObstaclePercent (double * triplet) {
  /* complete me !! 0_o */
  return triplet;
}

int
main()
{
  /* connect to robot */
  rConnect ("/dev/rfcomm0");
  
  double tripletPercents[3];
  getObstaclePercent (tripletPercents );

  printf ("Obstacle is %lf%% away from the left sensor.\n", 
          tripletPercents[0]);
  
  printf ("Obstacle is %lf%% away from the middle sensor.\n", 
          tripletPercents[1]);

  printf ("Obstacle is %lf%% away from the right sensor.\n", 
          tripletPercents[2]); 
  
  /* disconnect from robot */
  rDisconnect();

  return 0;
} /* main */

