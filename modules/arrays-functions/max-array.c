/* A program to store n/*  numbers, compute their maximum. */
/*  * This code illustrates the use of arrays within functions. */

#include <stdio.h>

#define n 10  /* number of elements to be processed in array */

double find_max (double arr[], int sizeOfArray)
{
  int j;
     
    double max = arr[0];    /* start with first array value */

    /* compare maximum with previous values, updating as needed */
     for (j = 1; j < sizeOfArray; j++)
       { if (arr[j] > max)
           max = arr[j];
       }

     return max;
}

int main (void)
{    double max, min, sum;

     printf ("Program to process real numbers.\n");

     /* declare array of n values  */
     double a[n] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

     double bigNumber = find_max (a, n);

     printf ("The maximum of ");
     int i;
     for (i = 0; i < n; i++)
       printf (" %5.2lf", a[i]);
     printf ("\n");

     printf ("is %5.2lf\n", bigNumber);

     return 0;
}
