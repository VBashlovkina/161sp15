/* program to illustrate 4 functions related to the quadratic formula 
   given a, b, and c, the formula computes solutions to
      a * x^2 +b * x + c = 0
   if discriminate = sqrt (b*b - 4*a*c), a != 0, and discriminate > 0,
   then the two real solutions of this equation are
     (-b + discriminate) / (2.0 * a)
  and
     (-b - discriminate) / (2.0 * a)

  compile using the math library with the line
      gcc -lm -o quadratic quadratic.c
*/

#include <stdio.h>
#include <math.h>

/* print equation */
void printEqn (double coeff2, double coeff1, double coeff0)
{
  printf ("Equation:  %lf*x^2 + %lf*x + %lf = 0\n", coeff2, coeff1, coeff0);
}

/* computation of the discriminate */
double disc (double r, double s, double t)
{
  return sqrt (s*s - 4*r*t);
}

/* print roots of the quadratic formula */
void printRoots (double a, double b, double c)
{
  double discriminate = disc (a, b, c);
  double root1 =  (-b + discriminate) / (2.0 * a);
  double root2 =  (-b - discriminate) / (2.0 * a);

  printf ("    Roots:  %lf and %lf\n", root1, root2);
}

/* control processing for x^2 - 3*x + 2.0 = 0 */
void eqn1 ()
{
  printEqn   (1.0, -3.0, 2.0);
  printRoots (1.0, -3.0, 2.0);
}

/* control processing for 2.0*x^2 - 7.0*x - 4.0 = 0 */
void eqn2 ()
{
  printEqn   (2.0, -7.0, -4.0);
  printRoots (2.0, -7.0, -4.0);
}

int main ()
{
  printf ("program illustrating functions and the quadratic formula\n");

  eqn1();
  eqn2();

  return 0;
}
