/******
 * getchar-example.c
 *
 * A simple program illustrating the uses of getchar and putchar.
 * Program prompts the user to type a letter, 
 *         reads the single character, and
 *         prints the single letter read
 * Program ignores any characters beyond the first one read
 *
 * Author: April O'Neill
 * 
 * Date: 2 August 2011
 * Revised 11 August 2011
 ******/

#include <stdio.h>

int
main()
{
  char a;

  printf ("Enter a letter: ");
  a = getchar();
  
  if (a != '\n')
    putchar(a);
  putchar('\n');
  return 0;
}
