/* This program implements encryption, using a route cipher
 */

#include <stdio.h>
#include <string.h>

/* Approach 1:  
       Read entire input into separate string array 
       Pre-conditions:  length of string <= maxSize
                        # rows, # cols <= maxSize
                        number of excess elements in table <= 26
       Use part of a large table for storage processing
       Variables row and col will indicate the amount of the
          table actually used
       Procedures used to organize processing into steps
*/

const int maxSize = 100;  // maximum length of string, table

/* procedure to read initial data (#rows, #columns, string)
 */
void readData(int * rows, int *cols, char origStr [maxSize]);

/* procedure to load string into table row by row */
void putStrInTable (char str [maxSize],  // initial string for encryption
                    int startPos,        // start encryption at this position
                    char table [maxSize][maxSize], 
                    int rowSize,         // number of rows used in table
                    int colSize);        // number of columns used in table

/* procedure to print string column by column */
void printEncryptedString (char table [maxSize][maxSize], 
                           int rowSize, int colSize);

int main ()
{
  char table [maxSize][maxSize];
  char origStr [maxSize];
  int rows;  // number of rows in encryption table
  int cols;  // number of columns in encryption table

  readData(&rows, &cols, origStr);
  int sizeOfTable = rows*cols;
  int startPos = 0;

  printf ("The encrypted string is:  \n");
  while (startPos < strlen(origStr))
    {
      putStrInTable (origStr, startPos, table, rows, cols);
      printEncryptedString (table, rows, cols);
      startPos += sizeOfTable;
    }
  printf ("\nDone\n");

  return 0;
}

/* procedure to read initial data (#rows, #columns, string)
 */
void readData(int * rows, int *cols, char origStr [maxSize])
{
  printf ("Enter number of rows and number of columns:  ");
  scanf ("%d %d", rows, cols);
  
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
}

/* procedure to load string into table row by row */
void putStrInTable (char str [maxSize],  // initial string for encryption
                    int startPos,        // start encryption at this position
                    char table [maxSize][maxSize], 
                    int rowSize,         // number of rows used in table
                    int colSize)         // number of columns used in table
{
  int row, col;
  int i = startPos;
  char ch = 'a';
  for (row = 0; row < rowSize; row++)
    for (col = 0; col < colSize; col++)
      {
        /* load table from string until out of characters
           thereafter use ch with 'a', 'b', etc.
        */
        if (i < strlen(str))
          table[row][col] = str[i];
        else
          {
            table[row][col] = ch;
            ch++;
          }
        i++;
      }
}

/* procedure to print string column by column */
void printEncryptedString (char table [maxSize][maxSize],
                           int rowSize, int colSize)
{
  int row, col;
  for (col = 0; col < colSize; col++)
    for (row = 0; row < rowSize; row++)
      printf ("%c", table[row][col]);
}
