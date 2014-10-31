/* program to compute a circle's circumference and area

   example using function with a function parameter
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

/* printing function */
void myPrint (double x, double f (double))
{
  printf ("%12.4lf", f(x));
}

int main ()
{
  printf ("      radius   circumference   area\n");
  double radius;
  for (radius = 0; radius < 10; radius++)
    {
      myPrint (radius, iden); 
      /* could also be
         printf ("%12.4lf", radius);
      */
      myPrint (radius, circum);
      myPrint (radius, area);
      printf ("\n");
    }
  return 0;
}
