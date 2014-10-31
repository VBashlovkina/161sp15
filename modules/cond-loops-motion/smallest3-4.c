/* A simple program to find the smallest of three numbers   *
 * Version 4:  using nested if-then-else statements         */
 
#include <stdio.h>

int main (void) 
{  int i1 = 7;
   int i2 = 3;
   int i3 = 5;
   int smallest;

   printf ("Program to determine the smallest of three integers\n");
   printf ("   the three numbers:  %d %d %d", i1, i2, i3);

   if (i1 <= i2)
        /* compare i1 and i3; i2 cannot be smallest */
        {if (i1 <= i3)
           smallest = i1;
           else smallest = i3;
        }
     else 
        /* compare i2 and i3; i1 cannot be smallest */
        {if (i2 <= i3)
           smallest = i2;
           else smallest = i3;
        }

   printf ("The smallest value is %d\n", smallest);

   return 0;
}
