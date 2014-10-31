/* Example of using a random number generator */

#include <stdio.h>

/* libraries for the random number generator */
#include <stdlib.h>
#include <time.h>

int main ()
{
  int i;
  int value;

  // initialize random number generator
  // change the seed to the random number generator, based on the time of day
  srand (time ((time_t *) 0) );

  /* call the random number generator 10 times, 
     printing the value and the value mod 10 */

  for (i = 0; i < 10; i++)
    {
      value = rand();
      printf ("random number:  %12d,   random mod 10:  %3d\n",
              value, value % 10);
    }
   return 0;
}
