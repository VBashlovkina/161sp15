/* A program to store n numbers, abd
   compute their maximum, minimum, and average.
 * This code illustrates built-in C-style arrays.
 */
#include <stdio.h>

#define n 10  /* number of elements to be processed in array */

int main (void)
{    int j;
     double max, min, sum;

     printf ("Program to process real numbers.\n");

     /* declare array of n values  */
     double a[n] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};  

     sum = max = min = a[0];    /* right to left assignment operator */

     for (j = 1; j < n; j++)
       { if (a[j] > max)
           max = a[j];     
         if (a[j] < min)
           min = a[j];
         sum += a[j];
       }

     printf ("Maximum:  %5.2f\n", max);
     printf ("Minimum:  %5.2f\n", min);
     printf ("Average:  %5.2f\n\n", sum/n);
     
     printf ("printing specific array elements\n");
     for (j = -2; j < 12; j++)
       printf ("a[%d] = %5.1lf\n", j, a[j]);

     return 0;
}
