/* C program illustrating how 2-dimensional arrays
   are passed in C
*/

#include <stdio.h>

void printArray (int arr[][10])
{
  int a, b;
  printf ("The 2-dimensional array is:\n");
  for (a = 0; a < 5; a++)
    {
      for (b = 0; b < 10; b++)
        printf ("%5d", arr[a][b]);
      printf ("\n");
    }
}

int main () 
{
  /* declare the 2-dimensional array */
  int table [5][10];
  int i, j;  /* loop indices */

  /* initialize the array */
  for (i = 0; i < 5; i++)
    for (j = 0; j < 10; j++)
      table[i][j] = 10*i + j;

  printArray (table);

  printf ("table element [3][7]:  %d\n", table [3][7]);
  printf ("table element [3][12]:  %d\n", table [3][12]);
  printf ("table element [3][-4]:  %d\n", table [3][-4]);

  return 0;
}
