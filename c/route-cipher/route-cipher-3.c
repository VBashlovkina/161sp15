/* This program implements encryption, using a route cipher
 */

#include <stdio.h>
#include <string.h>

/* Approach 3:  Declare
                     an input string for one block of size rowSize*colSize
                     a 2D array after row and column known
                Read and process input block by block
                For each block
                    read block from input
                    put block into table row by row
                    print block from table column by column
*/

int main ()
{
  int rowSize;  // number of rows in encryption table
  int colSize;  // number of columns in encryption table

  /* read row, column, and string information */
  printf ("Enter number of rows and number of columns:  ");
  scanf ("%d %d", &rowSize, &colSize);
  
  /* declare new table of desired size */
  /* variable-sized arrays allowed in Standard C 1999 */
  /* Reference:  http://gcc.gnu.org/onlinedocs/gcc/Variable-Length.html */
  int sizeOfTable = rowSize * colSize;
  char blockInput [sizeOfTable];
  char table[rowSize][colSize];

   /* clear input line before reading string */
  while (getchar() != '\n');

  printf ("Enter string to be encrypted:  ");
  char ch = getchar();

 printf ("The encrypted string is:\n");
  while (ch != '\n')
    {  /* process block of input */
      int i;
      char fillCh = 'a';

      for (i = 0; i < sizeOfTable; i++)
        {
          if (ch != '\n')
            { /* process user input */
              blockInput[i] = ch;
              ch = getchar();
            }
          else
            { /* fill rest of block with successive letters a, b, ... */
              blockInput[i] = fillCh;
              if (fillCh < 'z')
                fillCh++;
              else
                fillCh = 'a';
            }
        }

      int row, col;
      i = 0;
      /* put characters of block into table */
      for (row = 0; row < rowSize; row++)
        for (col = 0; col < colSize; col++)
          {
            table[row][col] = blockInput[i];
            i++;
          }
      
      /* print encrypted block */
      for (col = 0; col < colSize; col++)
        for (row = 0; row < rowSize; row++)
          printf ("%c", table[row][col]);
    }
  printf ("\nDone\n");
  
  return 0;
}
