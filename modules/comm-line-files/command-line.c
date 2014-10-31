/* example to show the use of command-line arguments */

#include <stdio.h>
#include <string.h>

#define line_size 500

int main(int argc, char *argv [])
{
  printf ("program to illustrate the use of command-line arguments\n");
  printf ("in running this program, you supplied %d argument(s):\n", argc);

  int i;
  for (i = 0; i < argc; i++)
    printf ("\t%2d:   %s\n", i, argv[i]);

  char line[line_size] = "";

  for (i = argc-1; i >= 0; i--)
    {
      strcat(line, argv[i]);
      if (i > 0)
        strcat(line, " ");
    }

  printf ("\na string with reversed arguments: %s\n", line);
  return 0;
}
