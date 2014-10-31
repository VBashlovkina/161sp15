/* A couple decides to have children.
   They decide to continue to have children until 
      they have at least one boy and one girl.
   Then they decide to stop having children.

   This program simulates family size for 1000 couples.
*/

#include <stdio.h>

/* libraries for the random number generator */
#include <stdlib.h>
#include <time.h>
/* Within the stdlib.h library,
 *    time returns a value based upon the time of day
 *    on some machines, rand returns a random integer between 0 and 2^31 - 1
 *        although on some machines rand gives values between 0 and 2^32 - 1
 *        and on other machines rand gives values between 0 and 2^15 - 1
 *    MaxRandInt is this maximum integer minus 1
 *        (Note: 2^32 = 2147483648, 2^31 = 1073741824 and 2^15 = 32768)
 *    Use 2^32-1 for SparkStations
 *    Use RAND_MAX for Linux machines,
 *    Use 2^15-1 for IBM Xstation 140s and HP 712/60s
 */
const int numberOfCouples = 1000;

int main ()
{
  /* initialize random number generator */
  /* change the seed to the random number generator, based on the time of day */
  srand (time ((time_t *) 0) );

  int couple;
  int numChildren = 0;

  for (couple = 0; couple < numberOfCouples; couple++)
    {
      /* couple starts with no children */
      int boys = 0;
      int girls = 0;
      
      /* couple has children */
      while ((boys == 0) || (girls == 0))
        {
          if ((rand() / (double) RAND_MAX) < 0.5) /* RAND_MAX is maximum random */
            boys++;
          else
            girls++;
        }

      numChildren += boys + girls;
    }

  /* reporting of family size */
  printf ("Simulation of family size for %d couples\n", numberOfCouples);
  printf ("     average numbe of children = %5.1lf\n", 
          numChildren / (double) numberOfCouples);
  return 0;
}
