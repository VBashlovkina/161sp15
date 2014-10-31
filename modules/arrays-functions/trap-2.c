/* Approximating area under sqrt(4-x^2) on [0, 2] using the Trapezoidal Rule.*
 * Version 2:  A function performs the area computation.                     */

#include <stdio.h>
#include <math.h>

#define n 50          /* number of subintervals to be used */

double f(double x);     
/* function to be used in the area approximation */

double area(double a, double b, int numInt);
/* Approximation of area under f(x) on [a, b] using the Trapezoidal Rule */

int main (void)
{  printf ("Program approximates the area under a function using the ");
  printf ("Trapezoidal Rule, based on %d intervals.\n", n);
   printf ("The approximate area is %7.4f\n", area (0.0, 2.0, n));
   return 0;
}

double f(double x) 
/* function to be used in the area approximation */
{  return (sqrt(4.0 - x*x));
}
 
double area (double a, double b, int numInt)
/* Finding area via the Trapezoidal Rule */
{  double width = (b - a) / numInt; 
   double sum = (f(a) + f(b)) / 2.0;   /* first and last terms in sum */
   double xvalue;

   for (xvalue = a + width; xvalue < b; xvalue += width)
      sum += f(xvalue);
   return (sum * width);
}
