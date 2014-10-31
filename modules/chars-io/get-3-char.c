/* program to read three characters from the keyboard and print them */

#include <stdio.h>

int main ()
{
  /* read three characters */
  char ch1, ch2, ch3;
  printf ("enter three characters: \n");
  ch1 = getchar();
  ch2 = getchar();
  ch3 = getchar();

  /* print the three characters */
  printf ("printing the three characters on separate lines, enclosed in $ $\n");
  putchar ('$');   /* print enclosing $ */
  putchar (ch1);   /* print character */
  putchar ('$');   /* print enclosing $ */
  putchar ('\n');  /* move to new line */

  putchar ('$');   /* print enclosing $ */
  putchar (ch2);   /* print character */
  putchar ('$');   /* print enclosing $ */
  putchar ('\n');  /* move to new line */

  putchar ('$');   /* print enclosing $ */
  putchar (ch3);   /* print character */
  putchar ('$');   /* print enclosing $ */
  putchar ('\n');  /* move to new line */

  return 0;
}
