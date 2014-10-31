/* program illustrating functions that compute 
   the volume and surface area of a sphere 
*/
#include <stdio.h>

/* volume function */
double get_volume (double radius)
{
  double rad_cubed = radius * radius * radius;
  return (4.0/3.0) * 3.1415926535 * rad_cubed;
}

/* surface area function */
double get_area (double radius)
{
  return 4.0 * 3.1415926535 * radius * radius;
}

int main ()
{
  /* using these functions */
  /* printing table */
  printf (" sphere            surface\n");  
  printf (" radius   volume     area\n");
  double rad;
  for (rad=1.0; rad <= 10; rad++)
    { double volume = get_volume(rad);
      double area = get_area(rad);
        printf ("%4.0lf  %8.2lf  %10.3lf\n", rad, volume, area);
    }


  /* computing cost of paint */
  printf ("\n\ncost of paint for sphere\n");
  printf ("  computed at $0.3 per square inch\n");

  printf (" radius  cost\n");
  for (rad=1.0; rad <= 10; rad++)
    {
      printf ("%4.0lf  %8.2lf\n", rad, get_area(rad) * 0.3);
    }

  return 0;
}
