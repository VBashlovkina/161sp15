/*******
 * picture-splice.c
 *
 * Example program takes two pictures, using the Scribbler 2 
 *  and shows a picture composed of pieces of the two pictures
 *
 * Author: April O'Neill
 *
 * Date: 4 August 2011
 *******/

#include <stdio.h>
#include "MyroC.h"


int
main()
{
  int i, j, width, height, midwidth, midheight;
  Picture * pic1, * pic2, * spliced;
  rConnect ("/dev/rfcomm0");

  pic1 = rTakePicture();
  width = rGetPictureWidth (pic1);
  height = rGetPictureHeight (pic1);
  midwidth = width / 2;
  midheight = height / 2;
  rTurnLeft (1, 1);
  pic2 = rTakePicture();
  spliced = rTakePicture();
  rDisplayPicture (pic1, "pic1");
  rDisplayPicture (pic2, "pic2");

  for (i = 0; i < width ; i++)
    {
      for (j = 0; j < height; j++)
        {
          if ( ( (i < midwidth) && (j < midheight))
               || ( (i > midwidth) && (j > midheight)) )
            rSetPicturePixel (spliced, i, j, (rGetPicturePixel (pic1, i, j)));
          else
            rSetPicturePixel (spliced, i, j, (rGetPicturePixel (pic2, i, j)));

        }
    }

  rShowPicture (spliced);
  rDisconnect();
  return 0;
}
