/* Approximating the area under sqrt(4-x^2) on [0, 2]        *
 *     using the Trapezoidal Rule.                           *
 * Version 3:  A procedure performs the area computation.    */

#include <stdio.h>
#include <math.h>

#define n 50          /* number of subintervals to be used */

double f(double x);
/* function to be used in the area approximation */

void compute_area(double a, double b, int numInt, double *area);
/* Approximation of area under f(x) on [a, b] using the Trapezoidal Rule */

int main (void)
{  double new_area;
   printf ("Program approximates the area under a function using the ");
   printf ("Trapezoidal Rule, based on %d intervals.\n", n);

   compute_area(0.0, 2.0, n, &new_area);
   printf ("The approximate area is %7.4f\n", new_area);

   return 0;
}

double f(double x) 
/* function to be used in the area approximation */
{  return (sqrt(4.0 - x*x));
}
 
void compute_area (double a, double b, int numInt, double *area)
/* Finding area via the Trapezoidal Rule */
{  double width = (b - a) / (double) numInt; 
   double sum = (f(a) + f(b)) / 2.0;   /* first and last terms in sum */
   double xvalue;

   for (xvalue = a + width; xvalue < b; xvalue += width)
      sum += f(xvalue);
 
   *area = sum * width;
}
