/* program to compute a circle's circumference and area
 */

# include <stdio.h>

const double pi = 3.1415926535;

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
  printf ("      radius   circumference   area\n");
  double radius;
  for (radius = 0; radius < 10; radius++)
    {
      printf ("%12.4lf", radius);
      printf ("%12.4lf", circum(radius));
      printf ("%12.4lf", area(radius));
      printf ("\n");
    }
  return 0;
}
