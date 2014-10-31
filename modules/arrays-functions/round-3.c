/* program to compute a circle's circumference and area

   example using an array of functions
 */

# include <stdio.h>

const double pi = 3.1415926535;

/* identity function */
double iden (double radius)
{
  return radius;
}

/* circumference function */
double circum (double radius)
{
  return 2 * pi * radius;
}

/* area function */
double area (double radius)
{
  return pi * radius * radius;
}

int main ()
{
  double (*funcarr[3]) (double) = {iden, circum, area};
  printf ("      radius   circumference   area\n");
  double radius;
  for (radius = 0; radius < 10; radius++)
    {
      int i;
      for (i = 0; i < 3; i++)
        {
          printf ("%12.4lf", funcarr[i](radius));
        }
      printf ("\n");
    }
  return 0;
}
