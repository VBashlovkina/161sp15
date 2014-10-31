#include <stdio.h>

/* program to compute the perimeter and area of a rectangle */

/* compute the perimeter and area of a rectangle, 
   given the lengths of the two sides */
void compute (double side1, double side2, double* perimeter, double* area)
{
  double lengthPlusWidth = side1 + side2;
  *perimeter = 2.0 * lengthPlusWidth;
  *area = side1 * side2;

  printf ("compute:  addresses, values, and pointer references\n");
  printf ("             side1:  address: %u, value: %lf\n",
          &side1, side1);
  printf ("             side2:  address: %u, value: %lf\n",
          &side2, side2);
  printf ("   lengthPlusWidth:  address: %u, value: %lf\n", 
          &lengthPlusWidth, lengthPlusWidth);
  printf ("   perimeter:        address: %u, value: %u, *perimeter: %lf\n", 
          &perimeter, perimeter, *perimeter);
  printf ("   area:             address: %u, value: %u, *area: %lf\n", 
          &area, area, *area);
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

  printf ("main:  variable addresses and values\n");
  printf ("   length:  address: %u, value: %lf\n", &length, length);
  printf ("   width:   address: %u, value: %lf\n", &width, width);
  printf ("   perim:   address: %u, value: %lf\n", &perim, perim);
  printf ("   ar:      address: %u, value: %lf\n", &ar, ar);

  return 0;

}
