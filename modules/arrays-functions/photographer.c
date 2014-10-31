#include <stdio.h>
#include "MyroC.h"

int
main()
{
   rConnect("/dev/rfcomm0");


  Picture pics[3]; /* This is an array of pictures. Picture is a type just like char and int, but it is for storing Scribbler pictures. */
  int i; 
  const char * name = "Here is your current picture!";
  double duration = 2.0;
  for (i = 0; i < 3; i++)
    {
      pics[i] = rTakePicture();
      rTurnRight (.5, 1);

      /* rDisplayPicture (pics[i], duration, name); 
         printf ("This is a blocking call.\n");
         printf ("This means that the new picture will not be shown \n");
         printf ("until you close the window for the old picture. \n");
         printf ("CLOSE THE WINDOW TO PROCEED TO THE NEXT PICTURE.\n");
       */
	
      /* rDisplayPicture (pics[i], -1.0 * duration, name); 
         printf("This is a non-blocking call.\n");
         printf ("This means that the new picture is shown even \n");
         printf ("if you haven't closed the window for the old picture. \n");
         printf ("The windows will just pop on top of one another.\n");
         printf ("Relax, and enjoy the photos!\n");
       */
    }


  rDisconnect();
  return 0;
}
