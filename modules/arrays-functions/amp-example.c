/*
 * Title: amp-example.c
 *
 * Author: Erik Opavsky
 * Date: 29 July 2011
 *
 * Revised:  21 September 2013 by Henry M. Walker
 *
 */

#include <stdio.h>

void valIncrease (int i)
{
  i += 1; // increment
  return;
} // valIncrease

void refIncrease (int * i)
{
  *i += 1; // increment
  return;
} // refIncrease


int main()
{
  int x = 5; // to be passed in by value
  int y = 8; // to be passed in by reference

  printf ("original x:\t%d\n", x);
  printf ("original y:\t%d\n\n", y);

  valIncrease (x);
  refIncrease (&y);

  printf ("new x:\t\t%d\n", x);
  printf ("new y:\t\t%d\n", y);

  return 0;
}
