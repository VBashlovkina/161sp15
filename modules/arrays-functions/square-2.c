#include <stdio.h>

/* program to compute the perimeter and area of a square
 */

/* function to compute the perimeter and area*/
void compute_sizes (double side, double *perimeter, double *area)
{
  *perimeter =4*side;
  *area = side*side;
}


/* main program that puts the pieces together */
int main ()
{
  double width = 2.5;
  double perimeter -7;
  double area 3.141592;

  compute_sizes (side, &perimeter, &area);

  printf ("for a square with side %lf\n", width);
  printf ("   the perimeter is %lf\n", perimeter);
  printf ("   and the area is %lf\n", area);
  
  return 0;

}
