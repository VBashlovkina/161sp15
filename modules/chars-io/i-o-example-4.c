/* Program to illustrate input of several numbers */
/*    this is program 4 */

#include <stdio.h>

double a, b;

main ()
{
  printf ("part 4:  reading two values, separated by the word walker\n");
  printf ("      enter values: ");
  scanf  ("%lfwalker%lf", &a, &b);
  printf ("      values read:  %lf  %lf\n\n", a, b);

  /* interesting test cases:
          1.5-3.5
          1.5walker2.5
          1.5 walker2.5
          1.5walker 2.5  */
}
