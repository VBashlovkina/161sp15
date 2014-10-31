#include "MyroC.h"
#include <stdio.h>

int main ()
{
  Picture * pic = rLoadPicture ("blank-short.jpg");

  printf ("picture dimensions:  width = %d, height = %d\n",
          rGetPictureWidth (pic), rGetPictureHeight (pic));
  
  Pixel px = {0, 0, 0};

  rSetPicturePixel (pic, 3, 140, px);

  Pixel newpx = rGetPicturePixel (pic, 3, 140);
  printf ("pixel values at 3, 140:  R: %d, G: %d, B: %d\n",
          newpx.R, newpx.G, newpx.B);

  newpx = rGetPicturePixel (pic, 140, 3);
  printf ("pixel values at 140, 3:  R: %d, G: %d, B: %d\n",
          newpx.R, newpx.G, newpx.B);

  rShowPicture (pic);
  



  return 0;

}
