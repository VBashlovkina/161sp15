/* program to solve a word-find puzzle
   command-line parameter used for name of file with data
   
   approach 4:  reading with scanf; white-space in input ignored
                a single 16 by 16 array contains a struct
                   one field stores a character (letter)
                   one field stores whether or not the character should be printed in output
*/

#define gridSize 16
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* entry in I/O table */
typedef struct {
  char ch;
  char print; /* 'y' indicates print character, 
                 'n' indicates print space */
} entry;

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
  entry grid[gridSize][gridSize];

  int i, j, k; /* indices for table or array */
  for (i = 0; i < gridSize; i++)
    for (j = 0; j < gridSize; j++)
      {
        char item[2];
        fscanf(inFile, "%s", item);   /* reading string skips initial whitespace */
        grid[i][j].ch = item[0];     /* with whitespace between letters, 
                                         relevant character always in first position */
        grid[i][j].print = 'n';
      }

  /* process successive words in file */
  char line [gridSize];    /* words cannot be larger than grid size */
  while (fscanf(inFile, "%s", line) != EOF)
    {  
      printf ("processing string:  %s\n", line);
  
      /* search for word in grid */
      int found = 0;
      /* first check horizontally */
      for (i = 0; ! found && i < gridSize; i++)
        {
          for (j = 0; !found && j < gridSize - strlen(line); j++)
            {
              for (k = 0; k < strlen(line); k++)
                if (grid[i][j+k].ch != line[k])
                  break;
              /* check if word matches */
              if (k == strlen(line))
                { /* word found, so set print field */
                  for (k = 0; k < strlen(line); k++)
                    grid[i][j+k].print = 'y';
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
                if (grid[i+k][j].ch != line[k])
                  break;
              /* check if word matches */
              if (k == strlen(line))
                { /* word found, so set print field */
                  for (k = 0; k < strlen(line); k++)
                    grid[i+k][j].print = 'y';
                  found = 1;
                }
            }
        }      
    }
  
  /* print resulting grid */
  for (i = 0; i < gridSize; i++)
    {
      for (j = 0; j < gridSize; j++)
        {
          if (grid[i][j].print == 'y')
            printf ("%c ", grid[i][j].ch);
          else
            printf ("  ");
        }
      printf ("\n");
    }
         
  return 0;
}
