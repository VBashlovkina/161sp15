#include <stdio.h>

#define arraylen 10

void printArray (unsigned * array, int length)
{
  int i;

  printf ("[ ");
  for (i = 0; i < length; i++)
    printf ("%d ", array[i]);
  printf ("]\n");
} //printArray


int main()
{
  int i, j, temp;
  int array[arraylen];

  printf ("Enter ten integers (not separated by punctuation), which will be placed in an array to sort.\n");
  for (i = 0; i < arraylen; i++)
    {
      scanf("%d", &temp);
      array[i] = temp;
    }

  printArray (array, arraylen);

  for (i = 1; i < arraylen; ++i)
    {
      temp = array[i];
      j = i - 1;
      while ((j > 0) && (temp < array[j]))
        {
          array[j + 1] = array[j];
          --j;
        }
      array[j + 1] = temp;
    }

  printArray (array, arraylen);

  return 0;
}
