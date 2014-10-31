#include <stdio.h>

/* program to compute the perimeter and area of a rectangle */

/* compute the perimeter and area of a rectangle, 
   given the lengths of the two sides */
void compute (double side1, double side2, double* perimeter, double* area)
{
  double lengthPlusWidth = side1 + side2;
  *perimeter = 2.0 * lengthPlusWidth;
  *area = side1 * side2;
}

int main ()
{
  /* declare variables */
  double length = 5.0;
  double width  = 7.0;
  double perim;  /* perimeter variable */
  double ar;     /* area variable */

  /* print header */
  printf ("working with a rectangle of width %lf and length %lf\n",
          width, length);
 
  /* compute desired quantities */
  compute (length, width, &perim, &ar);

  /* print results */
  printf ("the rectangle's perimeter is %lf\n", perim);
  printf ("the rectangle's area is %lf\n", ar);

  return 0;

}
