#include <stdio.h>

/* program to compute the perimeter and area of a rectangle */

/* function to compute the perimeter of a rectangle, 
   given the lengths of the two sides */
double perimeter (double side1, double side2)
{
  double lengthPlusWidth = side1 + side2;
  return 2.0 * lengthPlusWidth;
}

/* function to compute the area of a rectangle, 
   given the lengths of the two sides */
double area (double side1, double side2)
{
  return side1 * side2;
}

int main ()
{
  /* declare rectangle's size */
  double length = 5.0;
  double width  = 7.0;

  /* print header */
  printf ("working with a rectangle of width %lf and length %lf\n",
          width, length);
 
  /* compute desired quantities */
  double perim = perimeter (length, width);
  double ar  = area (length, width);

  /* print results */
  printf ("the rectangle's perimeter is %lf\n", perim);
  printf ("the rectangle's area is %lf\n", ar);

  return 0;

}
