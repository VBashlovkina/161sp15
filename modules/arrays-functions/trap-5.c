/* Approximating the area under several functions                      *
 *      using the Trapezoidal Rule.                                    *
 * Version 5:  An area function has numeric and functional parameters. */

#include <stdio.h>
#include <math.h>

#define n 50          /* number of subintervals to be used */

double circle(double x);
/* function for a circle of radius 2, centered at the origin */

double parabola(double x);
/* function for the standard parabola y = x^2 */

double area(double a, double b, int numInt, double f (double));
/* Approximation of area under f(x) on [a, b] using the Trapezoidal Rule */

int main (void)
{  int number;
   printf ("Program approximates the area under a function using the ");
   printf ("Trapezoidal Rule, based on %d intervals.\n", n);

   printf ("\n");;
   printf ("Approximation of 1/4 area of circle of radius 2 is %7.5f .\n\n",
                    area (0.0, 2.0, n, circle));
   printf ("Approximation of area under y = x^2 between 1 and 3 is%8.5f .\n\n",
                    area (1.0, 3.0, n, parabola));
   return 0;
}

double circle(double x) 
/* function for a circle of radius 2, centered at the origin */
{  return (sqrt(4.0 - x*x));
}
 
double parabola(double x)
/* function for the standard parabola y = x^2 */
{ return x*x;
}

double area (double a, double b, int numInt, double f (double))
/* Finding area via the Trapezoidal Rule */
{  double width = (b - a) / numInt; 
   double sum = (f(a) + f(b)) / 2.0;   /* first and last terms in sum */
   double xvalue;

   for (xvalue = a + width; xvalue < b; xvalue += width)
      sum += f(xvalue);
   return (sum * width);
}
