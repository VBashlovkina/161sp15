#include "MyroC.h"

  typedef struct myPixel {
    unsigned char R;
    unsigned char G;
    unsigned char B;
  } myPixel;

int main () {
  myPixel black1;
  black1.R = 0;
  black1.G = 0;
  black1.B = 0;

  Pixel black2 = {0,  0, 0};

  Picture * pic = rLoadPicture ("blank.jpg");





}
