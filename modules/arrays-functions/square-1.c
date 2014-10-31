#include <stdio.h>

/* program to compute the perimeter and area of a square
 */

/* function to compute the perimeter */
double perimeter_func (double side)
{
  double perim = 4 * side;
  return perim;
}

/* function to compute the area */
double area_func (double side)
{
  return side * side;
}

/* main program that puts the pieces together */
int main ()
{
  double width = 2.5;
  double perimeter, area;

  perimeter = perimeter_func(width);
  area = area_func(width);

  printf ("for a square with side %lf\n", width);
  printf ("   the perimeter is %lf\n", perimeter);
  printf ("   and the area is %lf\n", area);
  
  return 0;

}
