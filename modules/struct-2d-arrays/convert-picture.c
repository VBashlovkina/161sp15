#include <stdio.h>
#include "MyroCDev.h"

/* ....... Conversions involving 2-dimensional arrays ........... */
/* Convert a Picture to a 2-dimensional array of Pixels

   Precondition: Pixel pixArray [][] is a two dimensional array of size
   [pic.width][pic.height] */

void picToPix2DArray (Picture pic, int height, Pixel pixArray[][height])
{
  int i, j;
  int width = pic.width;

  for (i = 0; i < height; i++)
    for (j = 0; j < width; j++)
        pixArray[j][i] = pic.pix_array[j][i];
}

/* Convert a 2-dimensional array of Pixels to a Picture

   Precondition: Pixel pixArray [][] is a two dimensional array of size
    [pic.width][pic.height] */
void pix2DArrayToPic (Picture pic, int height, Pixel pixArray[][height])
{
  int i, j;
  int width = pic.width;    
  for (i = 0; i < height; i++)
    for (j = 0; j < width; j++)
      pic.pix_array[j][i]=pixArray[j][i];
}

/* ....... Conversions involving 1-dimensional arrays ........... */
/* Convert a Picture to a 1-dimensional array of Pixels

   Precondition: Pixel * pixArray is a two dimensional array of size
   [pic.width][pic.height] */
void picToPix1DArray (Picture pic, Pixel pixArray [])
{
  int i, j;
  int width = pic.width;
  int height = pic.height;

  for (i = 0; i < height; i++)
    for (j = 0; j < width; j++)
      pixArray[i*width + j] = pic.pix_array[j][i];
}

/* Convert a 1-dimensional array of Pixels to a Picture

   Precondition: Pixel * pixArray is a two dimensional array of size
   [pic.width][pic.height] */
void pix1DArrayToPic (Picture pic, Pixel pixArray [])
{
  int i, j;
  int width = pic.width;
  int height = pic.height;
      
  for (i = 0; i < height; i++)
    for (j = 0; j < width; j++)
      pic.pix_array[j][i]= pixArray[i * width + j];
}


/* .................... Flip picture images .................... */
void flipPicUpsideDown (Picture pic)
{
  /* use 2-dimensional processing */
  int width =pic.width ;
  int height =pic.height;
  Pixel pixArray [width][height];
  
  picToPix2DArray (pic, height, pixArray);
  printf ("flipPicUpsideDown not fully implemented\n");
  pix2DArrayToPic (pic, height, pixArray);
}

void flipPicLeftToRight (Picture pic)
{
  /* use 1-dimensional processing */
  int width = pic.width;
  int height = pic.height;
  Pixel pixArray [height*width];
  
  picToPix1DArray (pic, pixArray);
  printf ("flipPicLeftToRight not fully implemented\n");
  pix1DArrayToPic (pic, pixArray);
}

int main ()
{
  printf ("program to manipulate pictures from the Scribbler 2 robot\n");

  rConnect ("/dev/rfcomm0");

  printf ("taking picture");
  Picture pic1 = rTakePicture ();
  flipPicUpsideDown (pic1);
  printf ("displaying upsidedown picture\n");
  rDisplayPicture (pic1,5,"upside down frame");

  printf ("taking picture");
  Picture pic2 = rTakePicture ();
  flipPicLeftToRight (pic2);
  printf ("displaying left-to-right picture\n");
  rDisplayPicture (pic2, 5, "Left to Right frame");

  return 0;
}
