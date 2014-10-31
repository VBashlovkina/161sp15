#include "MyroC.h"
int
main ()
{
  rConnect ("/dev/rfcomm0");
  
  Picture * pic = rTakePicture();

  Pixel white = {0, 0, 0};

  rDisplayPicture (pic, "start");
  int i, j;
  for (i = 0; i < 100; i++)
    for (j = 0; j < 100; j++)
      {
        rSetPicturePixel(pic, i, j, white);
      }

    rDisplayPicture (pic, "start");

    sleep (20);

    rDisconnect();

    return 0;
}
