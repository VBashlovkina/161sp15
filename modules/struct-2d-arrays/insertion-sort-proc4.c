
#include <stdio.h>

void
printArray (int * array, int length)
{
  int i;

  printf ("[ ");
  for (i = 0; i < length; i++)
    printf ("%d ", array[i]);
  printf (" ]\n");
} //printArray


//Bubble sort
int
main ()
{
  int length, temp, i, j;
  length = 6;
  int array[] = {1, 3, 2, 5, 5, 4};

  printArray (array, length);
  
  for (i = 1; i < length; i++)
    {
      for (j = i; j > -1; j--)
        {
          temp = array[j-1];
          if (array[j] < array[j-1])
            {
              array[j-1] = array[j];
              array[j] = temp;
            }
        }
    }

   printArray (array, length);

  return 0;
} /* main */
