/* This program implements encryption, using a route cipher
 */

#include <stdio.h>
#include <string.h>

/* Approach 2:  
       Read entire input into separate string array (size limited)
       Pre-conditions:  length of string <= maxSize
                        number of excess elements in table <= 26
       Declare a 2D array after row and column known
       Collect encrypted message in newStr array before printing
       All work done within a block in main
*/

const int maxSize = 100;  // maximum length of string, table

int main ()
{
  char origStr [maxSize]; // array for user input
  int rowSize;  // number of rows in encryption table
  int colSize;  // number of columns in encryption table

  /* read row, column, and string information */
  printf ("Enter number of rows and number of columns:  ");
  scanf ("%d %d", &rowSize, &colSize);

  char newStr [maxSize + rowSize*colSize]; // array for encrpyted message
  /* clear input line before reading string */
  while (getchar() != '\n');

  printf ("Enter string to be encrypted:  ");
  int i = 0;
  origStr[i] = getchar();
  while (origStr[i] != '\n' && i < maxSize-1)
    {
      i++;
      origStr[i] = getchar();
    }
  origStr[i] = 0;

  /* declare new table of desired size */
  /* variable-sized arrays allowed in Standard C 1999 */
  /* Reference:  http://gcc.gnu.org/onlinedocs/gcc/Variable-Length.html */
  char table[rowSize][colSize];
  int startPos, row, col;

  printf ("The encrypted string is:\n");
  for (startPos = 0; startPos < strlen(origStr); startPos += rowSize*colSize)
    {
      /* put characters in table */
      int i = 0;
      char fillCh = 'a';
      for (row = 0; row < rowSize; row++)
        for (col = 0; col < colSize; col++)
          {
            /* load table from string until out of characters
               thereafter use ch with 'a', 'b', etc.
            */
            if (startPos + i < strlen(origStr))
              table[row][col] = origStr[startPos + i];
            else
              {
                table[row][col] = fillCh;
                fillCh++;
              }
            i++;
          }

      /* print encrypted block */
      i = 0;
      for (col = 0; col < colSize; col++)
        for (row = 0; row < rowSize; row++)
          {
            newStr [startPos + i] = table[row][col];
            i++;
          }
    }
  newStr[startPos] = 0; /* terminate string with null */

  /* full message now encoded, so can print entire encrypted text */
  printf ("%s", newStr);
  printf ("\nDone\n");
  
  return 0;
}
