/* Program to illustrate input of several numbers */
/*    this is program 2 */

#include <stdio.h>

double a, b;

main ()
{
  printf ("part 2:  reading two values, separated by hyphen\n");
  printf ("      enter values: ");
  scanf  ("%lf-%lf", &a, &b);
  printf ("      values read:  %lf  %lf\n\n", a, b);
  /* interesting test cases:
          1.5-3.5
          1.5'2.5  */

}
