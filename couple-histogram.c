/* A couple decides to have children.
   They decide to continue to have children until 
      they have at least one boy and one girl.
   Then they decide to stop having children.

   This program simulates family size for 1000 couples
   and prints a histogram of the results.
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


int main ()
{
  /* the number of couples in the simulation */
  const int numberOfCouples = 60;

  /* number of children is recorded for sizes 1 .. maxRecordedSize */
  const int maxRecordedSize = 30;
  int famSize [maxRecordedSize + 1];

  /* the highest point of the histogram will have heightOfHistogram *'s */
  const int heightOfHistogram = 20;

  /* initialize random number generator */
  /* change the seed to the random number generator, based on the time of day */
  srand (time ((time_t *) 0) );

   int numChildren = 0;

  int maxNumChildren = 0;

  int i, j;
  for (i = 0; i < maxRecordedSize + 1; i++)
    famSize[i] = 0;

  int couple;

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

      /* tabulate number of children for average computation */
      numChildren += boys + girls;
      /* record size of family for histogram */
      if (boys+girls > maxRecordedSize)
        famSize[maxRecordedSize]++;
      else
        famSize[boys+girls]++;
      /* update maximum size */
      if (boys+girls > maxNumChildren)
        maxNumChildren = boys+girls;
    }

  /* reporting of family size */
  printf ("Simulation of family size for %d couples\n", numberOfCouples);
  printf ("    family sizes truncated to %d\n", maxRecordedSize);
  printf ("    maximum height of histogram: %d\n\n",  heightOfHistogram);
  printf ("    average number of children = %.1lf\n",
          numChildren / (double) numberOfCouples);
  printf ("    maximum number of children = %d\n\n", maxNumChildren);

  /* print tabulated results */
  printf ("family size counts\n");
  printf ("# children: count\n");
       for (j = 0; j <= maxRecordedSize; j++)
         { printf ("   %5d  : %5d\n", j, famSize[j]);
         }

  /* print histogram */
       printf ("\n\nHistorgram of family sizes\n");
       printf ("# couples\n");
  for (i = heightOfHistogram; i > 0; i--)
    {
      printf ("%5d :", (i * famSize[2])/ heightOfHistogram);
      
      for (j = 0; j <= maxRecordedSize; j++)
        {
          if (famSize[j] > ((i-1) * famSize[2])/ heightOfHistogram)
            printf ("*");
          else
            printf (" ");
        }
      printf ("\n");
    }

  /* print histogram axis */
  printf ("       +");
  for (j = 1; j <= maxRecordedSize; j+=10)  
    printf ("---------+");
  printf ("\n");

  /* label histogram axis */
  for (j = 0; j <= maxRecordedSize; j+=10)  
    printf ("%8d  ", j);
  printf ("\n");

  return 0;
}
