#include <stdio.h>

/* illustration of parameter passage of an array */

void arrFunc (double arrayParm[])
{
  int i;
  printf ("values of array at start of function: ");
  for (i = 0; i < 5; i++)
    printf ("%8.2lf", arrayParm[i]);
  printf ("\n");
  arrayParm[1] += 100;
  arrayParm[3] += 300;
  printf ("values of array at end of function:   ");
  for (i = 0; i < 5; i++)
    printf ("%8.2lf", arrayParm[i]);
  printf ("\n");
}

int main () 
{
  double numberArr [5] = {43.7, 23.1, -56.2, 98.6, -40.0};
  double *refArr = numberArr;
  arrFunc(numberArr);
  int k;
  printf ("values of array at end of main:       ");
  for (k = 0; k < 5; k++)
    printf ("%8.2lf", numberArr[k]); 
  printf ("\n");

  printf ("addresses:        %u \t %u\n", &numberArr, &refArr);
  printf ("variables:        %u \t %u\n", numberArr, refArr);
  printf ("addr of arr[0]:   %u \t %u\n", &numberArr[0], &refArr[0]);
  printf ("values at *arr:   %lf \t %lf\n", *numberArr, *refArr);
  printf ("values at arr[0]: %lf \t %lf\n", numberArr[0], refArr[0]);
  arrFunc(refArr);
  printf ("values of array at end of main:       ");
  for (k = 0; k < 5; k++)
    printf ("%8.2lf", refArr[k]); 
  printf ("\n");

  return 0;
}
