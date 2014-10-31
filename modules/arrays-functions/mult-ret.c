#include "MyroC.h"
#include <stdio.h>

// set the value of light[] to the robot's light sensor values
void 
set_lights (int light[])
{
  rGetLightsAll (light);
} // set_lights


// set the value of obst[] to the robot's obstacle sensor values
void 
set_obsts (int obst[])
{
  rGetObstacleAll (obst);
} // set_obsts


int
main()
{
  rConnect ("/dev/rfcomm0");

  // integers to hold each of the light sensor values
  int light0;
  int light1;
  int light2;

  // integers to hold each of the obstacle sensor values
  int obst0;
  int obst1;
  int obst2;

  // array to hold all of the light sensor values
  int light[3];

  // array to hold all of the obstacle sensor values
  int obst[3];

  // set all of the light values
  set_lights (light);

  // set all of the obstacle values
  set_obsts (obst);

  // display all of the light sensor values
  printf ("light0 = %d\tlight1 = %d\tlight2 = %d\n", light[0], light[1], light[2]);
  
  // display all of the obstacle sensor values
  printf ("obst0 = %d\tobst1 = %d\tobst2 = %d\n", obst[0], obst[1], obst[2]);


  rDisconnect();
  return 0;
} // main
