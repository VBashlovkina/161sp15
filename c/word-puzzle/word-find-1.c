/* program to solve a word-find puzzle
   command-line parameter used for name of file with data
   
   approach 1:  reading with fgetc; white-space in input ignored
                one 16 by 16 array for input
                one 16 by 16 array for output
                entire algorithm in main (without additional procedures)
                some error checking for file name parameter, letters in words
*/

#define gridSize 16
#include <stdio.h>
#include <ctype.h>
#include <string.h>

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

  /* load input table from file 
     initialize output table to spaces */
  char inGrid[gridSize][gridSize];
  char outGrid[gridSize][gridSize];

  int i, j; /* indices for table */
  for (i = 0; i < gridSize; i++)
    for (j = 0; j < gridSize; j++)
      {
        inGrid[i][j] = fgetc(inFile);   /* put next letter into inGrid */
        outGrid[i][j] = ' ';            /* initialize outGrid */
        fgetc(inFile);                  /* read white space (space, \n' */
      }

  /* process successive words in file */
  char ch = fgetc (inFile);
  char line [gridSize];    /* words cannot be larger than grid size */
  while (ch != EOF)
    {  /* read word into string */
      int k = 0;
      while (ch != '\n')
        {
          //putchar(ch);
          if (isalpha(ch))
            { /* only store letters; ignore whitespace, if any */
              line[k] = ch;
              k++;
            }
          ch = fgetc (inFile);
        }
      line[k] = 0;  /* null at end of string */

      printf ("processing string:  %s\n", line);

      /* search for word in grid */
      int found = 0;
      /* first check horizontally */
      for (i = 0; ! found && i < gridSize; i++)
        {
          for (j = 0; !found && j < gridSize - strlen(line); j++)
            {
              for (k = 0; k < strlen(line); k++)
                if (inGrid[i][j+k] != line[k])
                  break;
              /* check if word matches */
              if (k == strlen(line))
                { /* word found */
                  for (k = 0; k < strlen(line); k++)
                    outGrid[i][j+k] = line[k];
                  found = 1;
                }
            }
        }      

      /* next check vertically, if necessary */
      for (i = 0; ! found && i < gridSize - strlen(line); i++)
        {
          for (j = 0; !found && j < gridSize; j++)
            {
              for (k = 0; k < strlen(line); k++)
                if (inGrid[i+k][j] != line[k])
                  break;
              /* check if word matches */
              if (k == strlen(line))
                { /* word found */
                  for (k = 0; k < strlen(line); k++)
                    outGrid[i+k][j] = line[k];
                  found = 1;
                }
            }
        }      

      /* start read of next possible word */
      ch = fgetc (inFile); 
    }

  /* print resulting grid */
  for (i = 0; i < gridSize; i++)
    {
      for (j = 0; j < gridSize; j++)
        printf ("%c ", outGrid[i][j]);
      printf ("\n");
    }
         
  return 0;
}
