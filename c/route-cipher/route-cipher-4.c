/* This program implements encryption, using a route cipher
 */

#include <stdio.h>
#include <string.h>

/* Approach 4:  Declare a 2D array after row and column known
                read input string block by block:
                for each block,
                    read successive characters directly into 2D array
                    then print block column by column
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
  char table[rowSize][colSize];

   /* clear input line before reading string */
  while (getchar() != '\n');

  printf ("Enter string to be encrypted:  ");
  char ch = getchar();

 printf ("The encrypted string is:\n");
  while (ch != '\n')
    {
      /* put characters in table */
      int row, col;
      char fillCh = 'a';
      for (row = 0; row < rowSize; row++)
        for (col = 0; col < colSize; col++)
          {
            /* load table from string until out of characters
               thereafter use ch with 'a', 'b', etc.
            */
            if (ch != '\n')
              {
                table[row][col] = ch;
                ch = getchar();
              }
            else
              {
                table[row][col] = fillCh;
                if (fillCh < 'z')
                  fillCh++;
                else 
                  fillCh = 'a';  /* reset to 'a' after going through a..z*/
              }
          }

      /* print encrypted block */
      for (col = 0; col < colSize; col++)
        for (row = 0; row < rowSize; row++)
          printf ("%c", table[row][col]);
    }
  printf ("\nDone\n");
  
  return 0;
}
