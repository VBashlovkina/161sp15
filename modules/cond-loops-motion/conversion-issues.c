/*
 * Conversion Issues
 *
 * This program highlights the issues that can happen when casting.
 * Author:  David Cowden
 * Revised:  26 September 2011 by Henry M. Walker
 * Revised:  10 September 2013 by Henry M. Walker
 */

#include <stdio.h>

int main () {
  
  char c;
  int i;
  float f;
  double d;

  printf("Before initialization..\n");

  printf("char   c = %c\n", c);
  printf("int    i = %d\n", i);
  printf("float  f = %f\n", f);
  printf("double d = %f\n", d);

  printf("\n");

  c = '0'; // the zero character
  i = 0;   
  f = 0.0;
  d = 0.0;

  printf("After initialization..\n");

  printf("char   c = %c\n", c);
  printf("int    i = %d\n", i);
  printf("float  f = %f\n", f);
  printf("double d = %f\n", d);

  printf("\n");
  
  return 0;
}
