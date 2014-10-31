#include <stdio.h>

/* illustration of parameter passage of an array */

void arrFunc (int arrayParm[])
{
  int i;
  printf ("values of array at start of function: ");
  for (i = 0; i < 5; i++)
    printf ("%8d", arrayParm[i]);
  printf ("\n");
  arrayParm[1] += 100;
  arrayParm[3] += 300;
  printf ("values of array at end of function:   ");
  for (i = 0; i < 5; i++)
    printf ("%8d", arrayParm[i]);
  printf ("\n");
}

int main () 
{
  int numberArr [5] = {43, 23, -56, 98, -40};
  int *refArr = numberArr;
  arrFunc(numberArr);
  int k;
  printf ("values of array at end of main:       ");
  for (k = 0; k < 5; k++)
    printf ("%8d", numberArr[k]); 
  printf ("\n");

  printf ("addresses:        %u \t %u\n", &numberArr, &refArr);
  printf ("variables:        %u \t %u\n", numberArr, refArr);
  printf ("addr of arr[0]:   %u \t %u\n", &numberArr[0], &refArr[0]);
  printf ("values at *arr:   %d \t %d\n", *numberArr, *refArr);
  printf ("values at arr[0]: %d \t %d\n", numberArr[0], refArr[0]);
  arrFunc(refArr);
  printf ("values of array at end of main:       ");
  for (k = 0; k < 5; k++)
    printf ("%8d", refArr[k]); 
  printf ("\n");

  return 0;
}
