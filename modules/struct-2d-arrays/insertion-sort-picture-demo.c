/* 
 * Program written by Erik Opavsky & David Cowden
 * July 2011
 */


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



// use insertion sort to sort the pixels in the picture array
void
pixelInsertionSort (Pixel * pix, int size)
{
// method to sort using the insertion sort
// parameters:  a, the array to be sorted
//              length, the size of the a array
  int k;
  for (k = 1; k < size; k++) {
    Pixel item = pix[k];
    int i = k-1;
    while ((i >= 0) && (!pixelCompare(pix[i], item))){
      pix[i+1] = pix[i];
      i--;
    }
    pix[i+1] = item;
  }
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

  rDisplayPicture (pic, "unsorted"); // before any changes to pic

  picToPixArray (pic, (*picArr)); // put Pixels from pic into array picArr

  pixelInsertionSort ((*picArr), width * height);
  
  rShowPicture (pic); // after sorting and before corner expansion

  cornerExpandReorder (pic, (*picArr)); // expand sorted Pixels from corner of pic

  rShowPicture (pic); // after both sorting and corner expansion

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
