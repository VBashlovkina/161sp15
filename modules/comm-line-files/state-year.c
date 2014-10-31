#include <stdio.h>
#include <stdlib.h>


int main (int argc, char * argv[] )
{
  if (argc != 2)
    {
      printf ("program requires a year as command-line parameter\n");
      return 1;
    }

  int year = atoi(argv[1]);
  printf ("Statistics for %d\n", year);

  FILE * ifile = fopen("state-income.dat", "r");

  // read 5 lines (in 3 different ways for illustration)
  char line [200];
  fgets(line, 200, ifile);
  char * anotherline = malloc (sizeof(char) * 200);
  fgets(anotherline, 200, ifile);
  int i;
  for (i = 0; i < 3; i++)
    while (fgetc(ifile) != '\n');


  // read and process individual lines
  // read first state, and continue line by line until the end

  // read 21 characters from file
  // fgets returns null when it reaches the end of file
  while (fgets(line, 22, ifile))
    {
      line [22] = 0; // not actually needed, as this is done by fgets
      printf (line);
      
      // skip initial columns
      for (i = 0; i < 1997-year; i++)
        {
          int j;
          for (j = 0; j < 6; j++)
            fgetc(ifile);
        }
      
      // read and print median for given year
      int median;
      fscanf (ifile, "%d", &median);
      printf ("%d\n", median);
      
      //ignore rest of line;
      while (fgetc(ifile) != '\n');

    }

  return 0;
}
