/* A simple program to find the smallest of three numbers   *
 * Version 1:  using simple if-then statements              */
 
#include <stdio.h>

int main (void) 
{  int i1 = 7;
   int i2 = 3;
   int i3 = 5;

   printf ("Program to determine the smallest of three integers\n");
   printf ("   the three numbers:  %d %d %d", i1, i2, i3);

   if ((i1 <= i2) && (i1 <= i3))
      printf ("The smallest value is %d\n", i1);

   if ((i2 < i1) && (i2 <= i3))
      printf ("The smallest value is %d\n", i2);

   if ((i3 < i1) && (i3 < i2))
      printf ("The smallest value is %d\n", i3);

   return 0;
}
