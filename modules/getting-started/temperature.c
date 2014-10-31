/* program to convert a temperature in fahrenheit
   to a temperature in celsius */

#include <stdio.h>

int main ()
{
  int fahrenheit;
  double celsius;

  fahrenheit = 72;
  celsius = (fahrenheit - 32.0) * 5.0 / 9.0;

  printf (" %d degrees fahrenheit = %5.2lf degrees celsius\n", 
          fahrenheit, celsius);

  return 0;

}
