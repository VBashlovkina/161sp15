/* Problem:
 * print scores for a designated test or the average test score for each person, 
 * according to a command-line parameter:
 *
 *  -- print name and scores for test 1 if command line parameter is 1
 *  -- print name and scores for test 2 if command line parameter is 2
 *  -- print name and scores for test 3 if command line parameter is 3
 *  -- print name and average on the three tests if command line parameter is all
 *
 * Approach 2:  Read name into array and read scores with fprintf
 */

#include <stdio.h>    /* for printf, fprintf,scanf */
#include <ctype.h>    /* for EOF */
#include <string.h>   /* for strcmp, strncpy */
#include <stdlib.h>   /* for strtod */
int main (int argc, char * argv[])
{
  printf ("program to display test scores/average\n");
  /* check commandline */
  if (argc != 2)
    {  printf ("need one command-line parameter ('1', '2', '3', or 'all')\n");
      return 1;
    }
  int command;
  if (strcmp(argv[1], "1") == 0)
    command = 1;
  else if (strcmp(argv[1], "2") == 0)
    command = 2;
  else if (strcmp(argv[1], "3") == 0)
    command = 3;
  else if (strcmp(argv[1], "all") == 0)
    command = 4;
  else 
    {  printf ("only valid command-line parameter is '1', '2', '3', or 'all'\n");
      return 1;
    }

  /* open file */
  char data_file[16] = "class-tests.dat";
  FILE * tfile = fopen (data_file, "r");

  /* read and throw away header (4 lines) */
  int i;
  char ch;
  for (i = 1; i <= 4; i++)
    while ((ch = fgetc(tfile)) != '\n');

  /* print headers */
  switch (command) {
  case 1: printf ("name                 test 1\n");
    break;
  case 2: printf ("name                 test 2\n");
    break;
  case 3: printf ("name                 test 3\n");
    break;
  case 4: printf ("name               test average\n");
    break;
  }

  int done = 0;
  while (!done)
    {
      

      /* process line */
      /* read 20 charactes as name */
      char line[51]; /* problem indicates maximum line length is 50 */
      char name[21];
      for (i = 0; (i < 50); i++)
        {
          line[i] = fgetc (tfile);
          if (line[i] == '\n')
            {
              line[i+1] = 0;
              break;
            }
        }
      if (line[i-1] == EOF)  /* processing stops if EOF found in name */
        break;

      strncpy (name, line, 20);
      name[20] = 0;  /* end string with null characer */

      double score;  /* value to be printed for each class member */
      /* if command is 1, 2, or 3, skip needed characters before score */
      if (command <= 3)
        {
          /* desired field starts at column 20 + (command-1) * 10 characters */
          /* read desired number */
          char * endpt;
          score = strtod (&(line[20+(command-1)*10]), &endpt);
        }
      else
        {
          double test1, test2, test3;
          /* read three numbers */
          /* could use strtod as shown above 
             or sscanf alternative to fscanf */
          sscanf (line+20, "%lf", &test1); 
          sscanf (line+30, "%lf", &test2);
          sscanf (line+40, "%lf", &test3);
          score = (test1 + test2 + test2) / 3.0;
        }
      printf ("%20s %6.2lf\n", name, score);
    } /* end of processing for class member */

  /* finish up */
  fclose (tfile);
  return 0;
}


