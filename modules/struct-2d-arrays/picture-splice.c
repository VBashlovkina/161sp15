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
#include "MyroCDev.h"


int
main()
{
  int i, j, width, height, midwidth, midheight;
  Picture  pic1,  pic2,  spliced;
  rConnect ("/dev/rfcomm0");

  pic1 = rTakePicture();
  width = pic1.width;
  height = pic1.height;
  midwidth = width / 2;
  midheight = height / 2;
  rTurnLeft (1, 1);
  pic2 = rTakePicture();
  spliced = rTakePicture();
  rDisplayPicture (pic1, 5, "pic1");
  rDisplayPicture (pic2, 5, "pic2");

  for (i = 0; i < width ; i++)
    {
      for (j = 0; j < height; j++)
        {
          if ( ( (i < midwidth) && (j < midheight))
               || ( (i > midwidth) && (j > midheight)) )
          spliced.pix_array[i][j]=pic1.pix_array[i][j];           
else
            spliced.pix_array[i][j]=pic2.pix_array[i][j]; 

        }
    }

  rDisplayPicture (spliced,-3,"spliced");
  rDisconnect();
  return 0;
}
