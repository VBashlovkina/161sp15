#include <stdio.h>
#include "MyroC.h"

int main ()
{
  printf ("program to set the name of the Scribbler 2 robot\n");
  printf ("to match the controlling MathLAN workstation name\n\n");

  int string_size = 20;
  char hostname [string_size];
  char hostnamecheck [string_size];

  gethostname(hostname, string_size);

  printf ("the name of this computer is %s\n", hostname);

  printf ("setting the robot name to %s\n", hostname);

  rConnect("/dev/rfcomm0"); /* connect to robot */

  rSetName(hostname);
  //rSetName("abcdefghijklmnopqrstuvwxyz");

  gethostname(hostnamecheck, string_size);

  rDisconnect();

  printf ("robot name now set to %s\n", hostnamecheck);
}
