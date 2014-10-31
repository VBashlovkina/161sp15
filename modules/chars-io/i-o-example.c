/* Program to illustrate input of several numbers */

#include <stdio.h>

double a, b;

main ()
{
  /*
  printf ("part 1:  reading two values, separated by white space\n");

  printf ("   approach 1:  use two scanf statements\n");
  printf ("      enter first value: ");
  scanf  ("%lf", &a);
  printf ("      enter second value: ");
  scanf  ("%lf", &b);
  printf ("      values read:  %lf  %lf\n\n", a, b);
  */
  /* interesting test cases:
          1.5 and 2.5 on separate lines
          1.5 2.5 on the same line */
 
  /*
  printf ("   approach 2:  combine into one scanf statement\n");
  printf ("      enter values: ");
  scanf  ("%lf%lf", &a, &b);
  printf ("      values read:  %lf  %lf\n\n", a, b);
  */
  /* interesting test cases:
          1.52.5
          1.5-2.5  */

  
  printf ("part 2:  reading two values, separated by hyphen\n");
  printf ("      enter values: ");
  scanf  ("%lf-%lf", &a, &b);
  printf ("      values read:  %lf  %lf\n\n", a, b);
  /* interesting test cases:
          1.5-3.5
          1.5'2.5  */

  /*
  printf ("part 3:  reading two values, separated by single quote\n");
  printf ("      enter values: ");
  scanf  ("%lf'%lf", &a, &b);
  printf ("      values read:  %lf  %lf\n\n", a, b);
  */
  /* interesting test cases:
          1.5-3.5
          1.5'2.5
          1.5 '2.5
          1.5' 2.5
          1.5 ' 2.5  */

  /*
  printf ("part 4:  reading two values, separated by the word walker\n");
  printf ("      enter values: ");
  scanf  ("%lfwalker%lf", &a, &b);
  printf ("      values read:  %lf  %lf\n\n", a, b);
  */
  /* interesting test cases:
          1.5-3.5
          1.5walker2.5
          1.5 walker2.5
          1.5walker 2.5  */
}
