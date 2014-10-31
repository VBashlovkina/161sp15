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
  arrFunc(numberArr);
  int k;
  printf ("values of array at end of main:       ");
  for (k = 0; k < 5; k++)
    printf ("%8.2lf", numberArr[k]); 
  printf ("\n");

  return 0;
}
