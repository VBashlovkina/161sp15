/* program to store elements in an array of expanding size */

#include <stdio.h>
#include <stdlib.h>

/* procedure to print elements in an array */
void printArray (int arr [], int numValues)
{
  int i;
  printf ("array elements:  ");
  if (numValues > 0)
    {
      printf ("%d", arr[0]);
      for (i = 1; i < numValues; i++)
        printf ("   %d", arr[i]);
    }
  printf ("\n");
  
}

void add (int newValue, int * arr[], int * currentNum, int * size)
{
  if (*currentNum == *size)
    { /* if the current array is full, expand it */
      int * newArr = malloc (2*(*size)*sizeof(int));
      int i;
      /* copy elements in old array to new one */
      for (i = 0; i < *size; i++)
        newArr[i] = (*arr)[i];
      /* deallocate space from old array */
      free (*arr);
      /* update array reference to new array */
      *arr = newArr;
    }
  /* add new value at end */
  (*arr)[*currentNum] = newValue;
  (*currentNum)++;
}

int main ()
{
  int arraySize = 1;  /* initial size of array */
  int currentNumInArray = 0;
  /* active array */
  int * myArray = malloc (arraySize * sizeof (int));

  int item;
  for (item = 0; item < 101; item++)
    add(3*item, &myArray, &currentNumInArray, &arraySize );

  printArray (myArray, currentNumInArray);

  return 0;
}
