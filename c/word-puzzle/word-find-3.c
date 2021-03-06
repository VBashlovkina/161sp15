/* program to solve a word-find puzzle
   command-line parameter used for name of file with data
   
   approach 3:  reading with fgetc; white-space in input ignored
                one 16 by 33 array for input
                    each row has space for full file line, plus null character
                one 16 by 32 array for output
                processing word done in general procedure with parameters
                    that specify horizontal or vertical word location
                some error checking for file name parameter, letters in words
*/

#define gridSize 16
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/* check input table for string
   for horizontal search:  horizSearchInc = 0, vertSearchInc = 1
   for vertical search:    horizSearchInc = 1, vertSearchInc = 0
   if found, 
      copy string to output table and return 1
   else
      return 0
*/
int processDirection (char * inTable[], char * outTable[], char * str,
                       int horizSearchInc, int vertSearchInc)
{
  int horizSearchLimit = gridSize - horizSearchInc*strlen(str);
  int vertSearchLimit  = gridSize - vertSearchInc*strlen(str);
  int i, j, k;
  for (i = 0; i < horizSearchLimit; i++)
    {
      for (j = 0; j < vertSearchLimit; j++)
        {
          for (k = 0; k < strlen(str); k++)
            if (inTable[i+horizSearchInc*k][j+vertSearchInc*k] != str[k])
              break;
          /* check if word matches */
          if (k == strlen(str))
            { /* word found */
              for (k = 0; k < strlen(str); k++)
                outTable[i+horizSearchInc*k][2*(j+vertSearchInc*k)] = str[k];
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

  /* input and output tables are pointers to dynamically-allocated arrays
     initialize input table from file 
     and output file as spaces*/
  char * inGrid[gridSize];
  char * outGrid[gridSize];
      /* each row is a null-terminated string */
  int i, j; /* indices for table */


  for (i = 0; i < gridSize; i++)
      {
        /* allocate space for rows of tables */
        inGrid[i] = malloc ((gridSize+1) * sizeof(char));
        outGrid[i] = malloc ((2*gridSize+1) * sizeof(char));

        /* fill rows --- each successive letters, skipping whitespace */
        for (j = 0; j < gridSize; j++)
          {
            /* skip whitespace */                    /* alternative loop       */
            char ch;                                 /* ch = fgetc(inFile);    */
            while (!isalpha(ch = fgetc(inFile)));    /* while (!isalpha(ch))   */
                                                     /*    ch = fgetc(inFile); */
            /* store character */
            inGrid[i][j] = ch;
            outGrid[i][2*j] = ' ';       /* output will contain both letters and spaces */
            outGrid[i][2*j+1] = ' ';     /* initial output has spaces in both positions */
          }
        inGrid[i][j] = 0;    /* terminate strings with nulls */
        outGrid[i][2*j] = 0;

      }
  /* remove final '\n' from table in file */
  while (fgetc(inFile) != '\n');

  /* process successive words in file */
  char line [gridSize+1]; /* words cannot be larger than grid size (plus null char) */

  /* read entire line until EOF */
  int k = 0;
  line[k] = fgetc(inFile);
  while (line[k] != EOF)
    {  /* string present, so read string from a full line */
      while (line[k] != '\n')
        {
          if (isalpha (line[k]))
              k++;              /* reuse space storing whitespace */
          line[k] = fgetc(inFile);
        }
      line[k] = 0;     /* string read should be null terminated */

      printf ("processing string:  %s\n", line);

      if (!processDirection (inGrid, outGrid, line, 0, 1)) /* check for word horizontally */
        processDirection (inGrid, outGrid, line, 1, 0);    /* check for word vertically */

      /* reset index k to start next word in position 0 of line */
      k = 0;
      line[k] = fgetc(inFile);
     }

  /* print resulting grid */
  for (i = 0; i < gridSize; i++)
    {
      printf ("%s\n", outGrid[i]);
    }
         
  return 0;
}
