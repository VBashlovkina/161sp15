/* 
 * Program written by Erik Opavsky & David Cowden:  July 2011
 * Revised February 2014 by Henry M. Walker
 */

#include "MyroC.h"


//  make the pixels in array pix expand from the corner of pic
void cornerExpandReorder (Picture * pic, Pixel pixArray []);

/* Convert a 1-dimensional array of Pixels to a Picture

   Precondition: Pixel * pixArray is a two dimensional array of size
   [rGetPictureHeight (pic)][rGetPictureWidth (pic)] */
void picToPix1DArray (Picture * pic, Pixel pixArray []);

/* Convert a 1-dimensional array of Pixels to a Picture

   Precondition: Pixel * pixArray is a two dimensional array of size
   [rGetPictureHeight (pic)][rGetPictureWidth (pic)] */
void pix1DArrayToPic (Picture * pic, Pixel pixArray []);

/* swap: interchange pix[i] and pix[j] */
void  swap (Pixel pix [], int i, int j);

/* compare two Pixels based upon their average RGB values
   returns 1 if average intensity of pix1 <- average intensity of pix2 
   returns 0 otherwise */
int pixelCompare (Pixel pix1, Pixel pix2);

// use insertion sort to sort the pixels in the picture array
void pixelInsertionSort (Pixel pix [], int size)
{
  //CODE HERE
}

int
main ()
{
  rConnect ("/dev/rfcomm0");

  int width, height;
  Picture * pic = rTakePicture();
  width = rGetPictureWidth (pic);
  height = rGetPictureHeight (pic);
  Pixel picArr[width * height];
  // 2D array for Pixels

  rDisplayPicture (pic, "unsorted"); // before any changes to pic

  picToPix1DArray (pic, picArr); // put Pixels from pic into array picArr

  pixelInsertionSort (picArr, width * height);

  pix1DArrayToPic (pic, picArr);
  
  rDisplayPicture (pic, "sorted"); // after sorting, before corner expansion

  cornerExpandReorder (pic, picArr); // expand sorted Pixels from corner of pic

  rDisplayPicture (pic, "expanded"); // after both sorting and corner expansion

  sleep (5);

  rDisconnect();
  return 0;
} // main


//  make the pixels in array pix expand from the corner of pic
void cornerExpandReorder (Picture * pic, Pixel pix [])
{
  int i, j, width, height;
  int pixCounter = 0; // counter for the current pixel
  width = rGetPictureWidth (pic);
  height = rGetPictureHeight (pic);

  for (i = 0; i < width * 2; i++)
    for (j = 0; j < i; j++)
      if ((j < width) && (i - j < height))
        rSetPicturePixel (pic, j, i - j, pix [pixCounter++]);

} // cornerExpandReorder

/* Convert a Picture to a 1-dimensional array of Pixels

   Precondition: Pixel * pixArray is a two dimensional array of size
   [rGetPictureHeight (pic)][rGetPictureWidth (pic)] */

void picToPix1DArray (Picture * pic, Pixel pixArray [])
{
  int i, j;
  int width = rGetPictureWidth (pic);
  int height = rGetPictureHeight (pic);

  for (i = 0; i < height; i++)
    for (j = 0; j < width; j++)
      pixArray[i*width + j] = rGetPicturePixel (pic, j, i);
}

/* Convert a 1-dimensional array of Pixels to a Picture

   Precondition: Pixel * pixArray is a two dimensional array of size
   [rGetPictureHeight (pic)][rGetPictureWidth (pic)] */
void pix1DArrayToPic (Picture * pic, Pixel pixArray [])
{
  int i, j;
  int width = rGetPictureWidth (pic);
  int height = rGetPictureHeight (pic);
      
  for (i = 0; i < height; i++)
    for (j = 0; j < width; j++)
      rSetPicturePixel (pic, j, i, pixArray[i * width + j]);
}

/* swap: interchange pix[i] and pix[j] */
void swap (Pixel pix [], int i, int j)
{
  Pixel temp;
  temp = pix [i];
  pix [i] = pix [j];
  pix [j] = temp;
} // swap


/* compare two Pixels based upon their average RGB values
   returns 1 if average intensity of pix1 <- average intensity of pix2 
   returns 0 otherwise */
int pixelCompare (Pixel pix1, Pixel pix2)
{ 
  int average1 = (pix1.R + pix1.G + pix1.B) / 3;
  int average2 = (pix2.R + pix2.G + pix2.B) / 3;

  return (average1 <= average2);
} // pixelCompare
