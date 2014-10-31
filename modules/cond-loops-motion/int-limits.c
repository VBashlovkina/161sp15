/* program to display the integer limits for ints on this machine */

#include <limits.h>
#include <stdio.h>

int main () {
  printf ("For this machine\n");
  printf ("\tthe largest integer is %d\n", INT_MAX);
  printf ("\tthe smallest integer is %d\n", INT_MIN);

  return 0;
}
