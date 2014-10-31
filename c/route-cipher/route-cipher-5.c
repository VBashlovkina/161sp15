/* This program implements encryption, using a route cipher
 */

#include <stdio.h>
#include <string.h>

/* Approach 5:  Declare a 2D array after row and column known
                read input string block by block:
                for each block,
                    place successive characters directly into 2D array
                    then print block column by column
                main steps organized as procedures
                    with array parameters of variable size
*/

/* read block of characters from input
   place characters row-by-row into table
   if input line too short to complete table,
      fill with a, b, c, ...
   lastCharRead indicates next input character to be processed
      checking lastCharRead for '\n' indicates all input read
*/
void readBlockFromInput (int rowSize, int colSize, 
                         char table[rowSize][colSize],
                         char * lastCharRead);

/* print encrypted block
   by printing table elements column by column
*/
void printTable (int rowSize, int colSize, char table[rowSize][colSize]);

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

  /* read first character to start process
  */

  char lastCharRead = getchar();

  printf ("The encrypted string is:\n");

  /* process block by block */
  while (lastCharRead != '\n')  /* lastCharRead is '\n' when input empty */
    {
      readBlockFromInput (rowSize, colSize, table, &lastCharRead);
      printTable (rowSize, colSize, table);
    }

  printf ("\nDone\n");
  
  return 0;
}

/* read block of characters from input
   place characters row-by-row into table
   if input line too short to complete table,
      fill with a, b, c, ...
   lastCharRead indicates next input character to be processed
      checking lastCharRead for '\n' indicates all input read
*/
void readBlockFromInput (int rowSize, int colSize,
                         char table[rowSize][colSize],
                         char * lastCharRead)
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
        if (*lastCharRead != '\n')
          {
            table[row][col] = *lastCharRead;
            *lastCharRead = getchar();
          }
        else
          { /* input completed, filling with extra letters a, b, ... */
            table[row][col] = fillCh;
            if (fillCh < 'z')
              fillCh++;
            else 
              fillCh = 'a';  /* reset to 'a' after going through a..z*/
          }
      }
}

/* print encrypted block
   by printing table elements column by column
*/
void printTable (int rowSize, int colSize, char table[rowSize][colSize])
{ int row, col;
  for (col = 0; col < colSize; col++)
    for (row = 0; row < rowSize; row++)
      printf ("%c", table[row][col]);
}
