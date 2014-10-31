/* program to convert a number of gallons, quarts, and pints
   to liters */
#include <stdio.h>

int main ()
{
  int gallons, quarts, pints;
  double total_quarts, liters;

  gallons = 23;
  quarts = 6;
  pints = 5;

  total_quarts = 4*gallons + quarts + pints/2.0; /* carefull: integer division */
  liters = total_quarts / 1.056710;
  
  printf ("%lf total quarts = %lf liters\n", total_quarts, liters);
  
  return 0;
}
