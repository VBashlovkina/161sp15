/* Approximating area under y = f(x) on [a, b] using the Trapezoidal Rule.   *
 * Version 4:  Approximating area under sqrt(4-x^2) on [0, 2].               *
 *    Here sqrt is computed via Newton's Method, rather than through math.h. */

#include <stdio.h>
#include <assert.h>

const double a = 0.0;                 /* alternative constant definitions */
const double b = 2.0;                   /* [a, b] gives interval for area */
const double root_accuracy = 0.00005;   /* sqrt computes to this accuracy */
#define n 50          /* number of subintervals to be used */

double sqrt(double r) 
/* function to compute square root of r using Newton's Method */
{ double change = 1.0;
  double x;              /* current approximation for sqrt(r)             */
  if (r == 0.0)
     return 0.0;         /* the square root of 0.0 is a special case      */
  assert (r > 0.0);      /* negative square roots are not defined         */
  x = r;                 /* r is used as a first approximation to sqrt(r) */
  while ((change > root_accuracy)||(change < - root_accuracy))
    { change = (x*x - r) / (2*x);
      x -= change; }
  return x;
}

double f(double x) /* function to be used in the area approximation */
{  return sqrt(4.0 - x*x); }

int main (void)
{  double width, sum, xvalue, area;

   printf ("Program approximates the area under a function using the ");
   printf ("Trapezoidal Rule, based on %d intervals.\n", n);

   width = (b - a) / n; 

   /* compute the sum in the area approximation */
   sum = (f(a) + f(b)) / 2.0;            /* first and last terms in sum */
   for (xvalue = a + width; xvalue < b; xvalue += width)
      sum += f(xvalue);

   area = sum * width;
   printf ("The approximate area is %7.4f\n", area);
   return 0;
}
