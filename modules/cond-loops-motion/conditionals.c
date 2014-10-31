/*
 * conditionals.c
 *
 * This program will demonstrate the various types of and uses for 
 * conditionals in C.  
 */

#include "MyroC.h"

int
main ()
{
  rConnect("/dev/rfcomm0");
  rSetForwardnessTxt("scribbler-forward");

  /* Tests HERE! */

  rDisconnect();
  return 0;
}
