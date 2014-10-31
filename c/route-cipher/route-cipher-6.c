/* This program implements encryption, using a route cipher
 */

#include <stdio.h>
#include <string.h>

/* Approach 6:  Read input string block by block:
                for each block,
                    place successive characters directly into 1D array,
                       with positions interpreted as offsets 
                       for column-major storage
                    print string
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
  char encryptedLine [sizeOfTable + 1];

   /* clear input line before reading string */
  while (getchar() != '\n');

  printf ("Enter string to be encrypted:  ");
  char ch = getchar();

 printf ("The encrypted string is:\n");
  while (ch != '\n')
    {
      /* put characters in encrypted string array */
      /* reading simulates row-major order
         identify location in column-major order for output 
      */
      int row, col;
      char fillCh = 'a';
      for (row = 0; row < rowSize; row++)
        for (col = 0; col < colSize; col++)
          {
            /* load table from string until out of characters
               thereafter use ch with 'a', 'b', etc.
            */
            int posInArray = col * rowSize + row;
            if (ch != '\n')
              {
                encryptedLine [posInArray] = ch;
                ch = getchar();
              }
            else
              {
                encryptedLine [posInArray] = fillCh;
                if (fillCh < 'z')
                  fillCh++;
                else 
                  fillCh = 'a';  /* reset to 'a' after going through a..z*/
              }
          }
      /* terminate string with null character */
      encryptedLine [sizeOfTable] = 0;

      /* print encrypted block */
      printf ("%s", encryptedLine);
    }
  printf ("\nDone\n");
  
  return 0;
}
