/* 
 * Program written by Erik Opavsky & David Cowden
 * July 2011
 */


#include <stdlib.h>
#include "MyroC.h"

//  make the pixels in array pix expand from the corner of pic
void
cornerExpandReorder (Picture * pic, Pixel * pix);

// put an image into a two dimensional Pixel array
void
picToPixArray (Picture * pic, Pixel *pixArray);

/* swap: interchange pix[i] and pix[j] */
void
swap (Pixel * pix, int i, int j);

// compare two Pixels based upon their average RGB values
int
pixelCompare (Pixel pix1, Pixel pix2);


// quicksort basis from K & R
/* qsort: sort pix[left]...pix[right] into increasing order */
void
pixelQuickSort (Pixel * pix, int left, int right)
{
  int i, last;

  if (left >= right) /* do nothing if array contains */
    return;          /* fewer than two elements */

  // printf ("before swap1\n");
  swap (pix, left, (left + right) / 2);    /* move partition elem */
  last = left;                             /* to pix[0] */

  // printf ("before for loop\n");
  for (i = left + 1; i <= right; i++)      /* partition */
    if (pixelCompare (*(pix + i), *(pix + left)))
      swap (pix, ++last, i);
 
  // printf ("before final swap\n");
  swap (pix, left, last);                  /* restore partition elem */
  pixelQuickSort (pix, left, last-1);
  pixelQuickSort (pix, last+1, right);
}


int
main ()
{
  rConnect ("/dev/rfcomm0");

  int width, height;
  Picture * pic = rTakePicture();
  width = rGetPictureWidth (pic);
  height = rGetPictureHeight (pic);
  Pixel picArr[width][height];
  // 2D array for Pixels

  rDisplayPicture (pic, "original"); // before any changes to pic

  picToPixArray (pic, ( * picArr)); // put Pixels from pic into array picArr

  pixelQuickSort ((*picArr), 0, width * height);
  
  // expand sorted Pixels from corner of pic
  cornerExpandReorder (pic, ( * picArr)); 

  rShowPicture (pic); // after sorting and corner expansion

  rDisconnect();
  return 0;
} // main


//  make the pixels in array pix expand from the corner of pic
void
cornerExpandReorder (Picture * pic, Pixel * pix)
{
  int i, j, width, height;
  int pixCounter = 0; // counter for the current pixel
  width = rGetPictureWidth (pic);
  height = rGetPictureHeight (pic);

  for (i = 0; i < width * 2; i++)
    for (j = 0; j < i; j++)
      if ((j < width) && (i - j < height))
        rSetPicturePixel (pic, j, i - j, *(pix + pixCounter++));

} // cornerExpandReorder


// put an image into a two dimensional Pixel array
void
picToPixArray (Picture * pic, Pixel *pixArray)
{
  int i, j;
  int width = rGetPictureWidth (pic);
  int height = rGetPictureHeight (pic);

  for (i = 0; i < height; i++)
    for (j = 0; j < width; j++)
      *(pixArray + (i * width) + j) = rGetPicturePixel (pic, j, i);

} // picToPixArray

/* swap: interchange pix[i] and pix[j] */
void
swap (Pixel * pix, int i, int j)
{
  Pixel temp;
  temp = *(pix + i);
  *(pix + i) = *(pix + j);
  *(pix + j) = temp;
} // swap


// compare two Pixels based upon their average RGB values
int
pixelCompare (Pixel pix1, Pixel pix2)
{ 
  int average1 = (pix1.R + pix1.G + pix1.B) / 3;
  int average2 = (pix2.R + pix2.G + pix2.B) / 3;

  return (average1 <= average2);
} // pixelCompare
