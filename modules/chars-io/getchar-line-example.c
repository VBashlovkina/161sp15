/******
 * getchar-line-example.c
 *
 * A simple program illustrating the uses of getchar and putchar.
 * Program prompts the user to type two lines of text
 *         the first line is read character-by-character
 *             and immediately echoed to the terminal
 *         the second line is read character-by-character into an array
 *             a null character is added at the end of input
 *             after all reading is done, the array is printed as a string
 *
 * Author: Henry M. Walker
 * 
 * Date: 2 March 2013
 ******/

#include <stdio.h>

int
main()
{
  char a;

  printf ("Enter a line of text: ");
  /* read character by character until new line (\n) is read */
  a = getchar();
  
  printf ("line read:  ");
  while (a != '\n')
    {
      /* echo previous character
         read next character
      */
      putchar(a);
      a = getchar();
    }
  /* reading of line done, so move to next line */
  putchar('\n');

  printf ("Enter a second line of text (no more than 80 characters): ");
  /* size of array set for 80 character input plus null character at end */
  char line[81];

  int i = 0;
  /* loop guard combines reading, placing in array and newline check */
  while ((line[i] = getchar()) != '\n')
    {
      i++;
    }

  /* new line character at end --- replace by null for end of string */
  line[i] = 0;

  /* print line as a string */
  printf ("second line read:  %s\n", line);

  return 0;
}
