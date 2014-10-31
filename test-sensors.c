// Program for correlating Scribbler 2 sensors with MyroC function names

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "MyroC.h"  /* reference to MyroC library */

int main()  /* beginning of main program */
{
  printf ("Program to execute various functions for MyroC/Scribbler 2 functions\n");
  printf ("Each function is repeated several times at 3.0 second intervals\n");

  #define len  20 /* length of maximum command string */
  char command [len] = "start";
  int i;
  int iter=0;

  char leftStr[] = "left";    /* declaration of needed string parameters */
  char middleStr[] = "middle";
  char rightStr[] = "right";

  int vals[3] = {-100, -100, -100};   /* array to store up to 3 sensor values */
  int * res;

  int left, middle, right;

  rConnect("/dev/rfcomm0"); /* connect to robot */

  while (strcmp (command, "quit") != 0)
    {
      iter += 1000;
      vals[0] = iter;
      vals[1] = iter + 200;
      vals[2] = iter + 400;
      
      left = iter + 600;
      right= iter + 800;

      printf ("\nMenu of MyroC functions\n");
      printf ("   quit\n");
      printf ("   light:     rGetLightsAll\n");
      printf ("   ir:        rGetIRAll       (returns 0, 1  / no obstacle, obstacle)\n");
      printf ("   obstacle:  rGetObstacleAll (returns 0-6000/ no obstacle--obstacle)\n");
      printf ("   bright:    rGetBrightAll\n");
      /*
      printf ("   \n");
      printf ("   \n");
      printf ("   \n");
      printf ("   \n");
      */
      printf ("\nEnter function command:  ");
      scanf ("%s", command);

      /* convert command to lower case for easy comparisons */
      for (i = 0; i < len; i++)
	command[i] = tolower(command[i]);

      if (strcmp (command, "light") == 0)
	{
	  printf ("light txt sensors\n");
	  rGetLightsAll (vals);
          left = rGetLightTxt(leftStr);
          middle = rGetLightTxt(middleStr);
          right=rGetLightTxt(rightStr);
	  printf ("left:  %d\tmiddle:  %d\tright:  %d\n", vals[0], vals[1], vals[2]);
          printf ("left:  %d\tmiddle:  %d\tright:  %d\n", left, middle, right);
	  rBeep (3.0, 0);  /* pause for 3.0 seconds */

	  printf ("light num sensors\n");
	  rGetLightsAll (vals);
          left = rGetLightNum(0);
          middle= rGetLightNum(1);
          right= rGetLightNum(2);
	  printf ("left:  %d\tmiddle:  %d\tright:  %d\n", vals[0], vals[1], vals[2]);
          printf ("left:  %d\tmiddle:  %d\tright:  %d\n", left, middle, right);
	  rBeep (3.0, 0);  /* pause for 3.0 seconds */

	  printf ("light txt sensors\n");
	  rGetLightsAll (vals);
          left = rGetLightTxt(leftStr);
          middle = rGetLightTxt(middleStr);
          right=rGetLightTxt(rightStr);
	  printf ("left:  %d\tmiddle:  %d\tright:  %d\n", vals[0], vals[1], vals[2]);
          printf ("left:  %d\tmiddle:  %d\tright:  %d\n", left, middle, right);
	  rBeep (3.0, 0);  /* pause for 3.0 seconds */

	  printf ("light num sensors\n");
	  rGetLightsAll (vals);
          left = rGetLightNum(0);
          middle= rGetLightNum(1);
          right=rGetLightNum(2);
	  printf ("left:  %d\tmiddle:  %d\tright:  %d\n", vals[0], vals[1], vals[2]);
          printf ("left:  %d\tmiddle:  %d\tright:  %d\n", left, middle, right);
	  rBeep (3.0, 0);  /* pause for 3.0 seconds */

	}
      else if (strcmp (command, "obstacle") == 0)
	{
	  printf ("obstacle sensors\n");
	  res = rGetObstacleAll (vals);
          left = rGetObstacleTxt(leftStr);
          right=rGetObstacleTxt(rightStr);
	  printf ("left:  %d\tmiddle:  %d\tright:  %d\n", vals[0], vals[1], vals[2]);
	  printf ("left:  %d\tmiddle:  %d\tright:  %d\n", res[0], res[1], res[2]);
          printf ("left:  %d\t\t\tright:  %d\n", left, right);
	  rBeep (3.0, 0);  /* pause for 3.0 seconds */

	  printf ("obstacle sensors\n");
	  rGetObstacleAll (vals);
          left = rGetObstacleNum(1);
          right=rGetObstacleNum(2);
	  printf ("left:  %d\tmiddle:  %d\tright:  %d\n", vals[0], vals[1], vals[2]);
          printf ("left:  %d\t\t\tright:  %d\n", left, right);
	  rBeep (3.0, 0);  /* pause for 3.0 seconds */

	  printf ("obstacle sensors\n");
	  rGetObstacleAll (vals);
          left = rGetObstacleTxt(leftStr);
          right=rGetObstacleTxt(rightStr);
	  printf ("left:  %d\tmiddle:  %d\tright:  %d\n", vals[0], vals[1], vals[2]);
          printf ("left:  %d\t\t\tright:  %d\n", left, right);
	}
      else if (strcmp (command, "bright") == 0)
	{
	  printf ("bright sensors\n");
	  //res = rGetBrightAll (vals);
	  //printf ("left:  %d\tmiddle:  %d\tright:  %d\n", vals[0], vals[1], vals[2]);
	  //printf ("left:  %d\tmiddle:  %d\tright:  %d\n", res[0], res[1], res[2]);
          left = rGetBrightTxt(leftStr);
          middle = rGetBrightTxt(middleStr);
          right= rGetBrightTxt(rightStr);
          printf ("left:  %d\tmiddle:  %d\tright:  %d\n", left, middle, right);
	  rBeep (3.0, 0);  /* pause for 3.0 seconds */

	  printf ("bright sensors\n");
	  rGetBrightAll (vals);
          left = rGetBrightTxt(leftStr);
          middle = rGetBrightTxt(middleStr);
          right= rGetBrightTxt(rightStr);
	  printf ("left:  %d\tmiddle:  %d\tright:  %d\n", vals[0], vals[1], vals[2]);
          printf ("left:  %d\tmiddle:  %d\tright:  %d\n", left, middle, right);
	  rBeep (3.0, 0);  /* pause for 3.0 seconds */

	  printf ("bright sensors\n");
	  rGetBrightAll (vals);
          left = rGetBrightTxt(leftStr);
          middle = rGetBrightTxt(middleStr);
          right= rGetBrightTxt(rightStr);
	  printf ("left:  %d\tmiddle:  %d\tright:  %d\n", vals[0], vals[1], vals[2]);
          printf ("left:  %d\tmiddle:  %dt\tright:  %d\n", left, middle, right);
	}
      else if (strcmp (command, "ir") == 0)
	{
	  printf ("IR sensors\n");
          rSetIRPower(135);
          printf("IR txt sensors set to 255\n");
	  rGetIRAll (vals);          
          left = rGetIRTxt(leftStr);
          right= rGetIRTxt(rightStr);
	  printf ("left:  %d\tright:  %d\n", vals[0], vals[1]);
          printf ("left:  %d\tright:  %d\n", left, right);
	  rBeep (3.0, 880);  /* pause for 3.0 seconds */

	  printf ("IR num sensors\n");
	  rGetIRAll (vals);
          left = rGetIRNum(0);
          right= rGetIRNum(1);
	  printf ("left:  %d\tright:  %d\n", vals[0], vals[1]);
          printf ("left:  %d\tright:  %d\n", left, right);
	  rBeep (3.0, 880);  /* pause for 3.0 seconds */

	  printf ("IR txt sensors\n");
	  rGetIRAll (vals);
          left = rGetIRTxt(leftStr);
          right= rGetIRTxt(rightStr);
	  printf ("left:  %d\tright:  %d\n", vals[0], vals[1]);
          printf ("left:  %d\tright:  %d\n", left, right);
	  rBeep (3.0, 880);  /* pause for 3.0 seconds */

	  printf ("IR num sensors\n");
	  rGetIRAll (vals);
          left = rGetIRNum(0);
          right= rGetIRNum(1);
	  printf ("left:  %d\tright:  %d\n", vals[0], vals[1]);
          printf ("left:  %d\tright:  %d\n", left, right);
	  rBeep (3.0, 880);  /* pause for 3.0 seconds */

	  printf ("IR txt sensors\n");
	  rGetIRAll (vals);
          left = rGetIRTxt(leftStr);
          right= rGetIRTxt(rightStr);
	  printf ("left:  %d\tright:  %d\n", vals[0], vals[1]);
          printf ("left:  %d\tright:  %d\n", left, right);
	}
    }

  rDisconnect (); /* disconnect from robot */

  return 0; /* return 0 if no errors occurred */
} /* end of main */
