/* library for Myro functions */
#include "MyroC.h"

/* library for standard I/O */
#include <stdio.h>

/* library including memory allocation */
#include <stdlib.h>

int main (void) {
  /* program that takes a movie*/ 
  printf ("Starting program:  ");
  rConnect ("/dev/rfcomm0");
  rSetForwardnessTxt("fluke-forward");

  printf ("program asking Scribbler 2 to take and display pictures\n");
  /* determine how many pictures */
  int numPics, i;
  printf ("enter number of pictures to be taken:  ");
  scanf ("%d", &numPics);
  Picture * pics[numPics];
  
  printf ("taking %d pictures, while turning left\n", numPics);
  for (i = 0; i < numPics; i++)
    {
      pics[i] = rTakePicture();
      rTurnLeft (0.3, 0.3);
    }

  sleep(1);
  printf ("showing pictures in original order\n");
  for (i = 0; i < numPics; i++)
    {
      rDisplayPicture(pics[i], "movieFrame");
      sleep(1);
    }

  sleep(1);
  printf ("showing pictures in reverse order\n");
  for (i = numPics-1; i >= 0; i--)
    {
      rDisplayPicture(pics[i], "movieFrame");
      sleep(1);
    }

  printf ("Closing connection to robot....");
  rDisconnect();
  printf (" finished.\n\n");
}
 
