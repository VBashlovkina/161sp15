/* A simple program to find the smallest of three numbers            *
 * Version 2:  using if-then-else statements with intermediate steps */
 
#include <stdio.h>

int main (void) 
{  int i1 = 7;
   int i2 = 3;
   int i3 = 5;

   int smaller, smallest;

   printf ("Program to determine the smallest of three integers\n");
   printf ("   the three numbers:  %d %d %d", i1, i2, i3);

   if (i1 <= i2)
        smaller = i1;
   else smaller = i2;

   if (smaller <= i3)
        smallest = smaller;
   else smallest = i3;

   printf ("The smallest value is %d\n", smallest);

   return 0;
}
