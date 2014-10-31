/* program to solve a word-find puzzle
   command-line parameter used for name of file with data
   
   approach 2:  reading with fgets; white-space in input ignored
                one 16 by 33 array for input
                    each row has space for full file line, plus null character
                one 16 by 32 array for output
                one procedure searches input array for horizontal word placement
                similar procedure searches input array for vertical word placement
                some error checking for file name parameter, letters in words
*/

#define gridSize 16
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* check input table horizontally for string
   if found, 
      copy string to output table and return 1
   else
      return 0
*/
int processHorizontal (char inTable[][2*gridSize+1], char outTable[][2*gridSize], char * str)
{
  int i, j, k;
  for (i = 0; i < gridSize; i++)
    {
      for (j = 0; j < 2*gridSize - 2*strlen(str); j+=2)
        {
          for (k = 0; k < strlen(str); k++)
            if (inTable[i][j+2*k] != str[k])
              break;
          /* check if word matches */
          if (k == strlen(str))
            { /* word found */
              for (k = 0; k < strlen(str); k++)
                outTable[i][j+2*k] = str[k];
              return 1;  /* word found */
            }
        }
    }      
  return 0;   /* word not found */
}

/* check input table vertically for string
   if found, 
      copy string to output table and return 1
   else
      return 0
*/
int processVertical (char inTable[][2*gridSize+1], char outTable[][2*gridSize], char * str)
{
  int i, j, k;
  for (i = 0; i < gridSize; i++)
    {
      for (j = 0; j < 2*gridSize; j+=2)
        {
          for (k = 0; k < strlen(str); k++)
            if (inTable[i+k][j] != str[k])
              break;
          /* check if word matches */
          if (k == strlen(str))
            { /* word found */
              for (k = 0; k < strlen(str); k++)
                outTable[i+k][j] = str[k];
              return 1;  /* word found */
            }
        }
    }      
  return 0;   /* word not found */
}

int main (int argc, char * argv[])
{
  printf ("program to solve the word-find puzzle problem\n");
  if (argc != 2)
    {
      printf ("Run-time error:  include file name on command-line\n");
      return 1;
    }

  /* open file for input */
  printf ("input file for data:  %s\n", argv[1]);
  FILE * inFile = fopen (argv[1], "r");
  if (inFile == NULL)
    {
      printf ("Run-time error:  file not found\n");
      return 2;
    }

  /* load input table from file */
  char inGrid[gridSize][2*gridSize+1];
       /* each row is a null-terminated string */
  int i, j; /* indices for table */
  for (i = 0; i < gridSize; i++)
      {
        /* table contains both letters and separating spaces */
        fgets (inGrid[i], 2*gridSize+1, inFile);
      }

  /* initialize output grid to spaces */
  char outGrid[gridSize][2*gridSize];
       /* each row is a null-terminated string */
  for (i = 0; i < gridSize; i++)
    {
    for (j = 0; j < 2*gridSize-1; j++)
      {
        outGrid[i][j] = ' ';            /* rows are spaces, except */
      }
    outGrid [i][2*gridSize-1] = 0;      /* last character in row is null */
    }

  /* process successive words in file */
  char line [gridSize];    /* words cannot be larger than grid size */

  /* read entire line until EOF */
  while (fgets(line, gridSize, inFile) != NULL)
    {  /* since fgets includes '\n' in line, remove white space at end */
      int k = strlen(line)-1;
      while (!isalpha(line[k]))
        {
          line[k] = 0;   /* shorten string with null over whitespace */
          k--;
        }

      printf ("processing string:  %s\n", line);

      if (!processHorizontal (inGrid, outGrid, line))
        processVertical (inGrid, outGrid, line);
    }

  /* print resulting grid */
  for (i = 0; i < gridSize; i++)
    {
      printf ("%s\n", outGrid[i]);
    }
         
  return 0;
}
