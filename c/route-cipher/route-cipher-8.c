/* This program implements encryption, using a route cipher
 */

#include <stdio.h>
#include <string.h>

/* Approach 8:  Read input string block by block:
                for each block,
                    read into 1D input array
                    load 1D output array in order, chosing elements from input
                    print output string
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
  char inputStr [sizeOfTable];
  char encryptedLine [sizeOfTable + 1];

   /* clear input line before reading string */
  while (getchar() != '\n');

  printf ("Enter string to be encrypted:  ");
  char ch = getchar();

 printf ("The encrypted string is:\n");
  while (ch != '\n')
    {
      /* put characters into input array */
      /* reading simulates row-major order
         identify location in column-major order for output 
      */
      int row, col;
      char fillCh = 'a';

      int inputPos = 0; // position in input array      
      for (inputPos = 0; inputPos < sizeOfTable; inputPos++)
        {
          if (ch != '\n')
            { /* process user input */
              inputStr[inputPos] = ch;
              ch = getchar();
            }
          else
            { /* fill rest of block with successive letters a, b, ... */
              inputStr[inputPos] = fillCh;
              if (fillCh < 'z')
                fillCh++;
              else
                fillCh = 'a';
            }
        }

      int outputPos; // position in output array
      for (outputPos = 0; outputPos < sizeOfTable; outputPos++)
        {
          /* compute row and column where encryptedLine[outputPos]
             would appear in table (using column-major order*/
          row = outputPos % rowSize;
          col = outputPos / rowSize;
          /* locate row, col element when consider row-major order */
          int posInInput = row * colSize + col;
            encryptedLine [outputPos] = inputStr [posInInput];
          }
      /* terminate string with null character */
      encryptedLine [sizeOfTable] = 0;

      /* print encrypted block */
      printf ("%s", encryptedLine);
    }
  printf ("\nDone\n");
  
  return 0;
}
