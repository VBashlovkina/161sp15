/*
 * This program simulates 100 coin flips and counts the number of 
 * pairs of tails flipped.  A value of 1 represents tails, and a 
 * value of 0 represents heads.  Two tails in a row are a single
 * pair, then each consecutive tails flip counts as another pair.
 * For example, two tails are 1 pair, three tails are 2 pairs,
 * four tails are 3 pairs, etc. A heads flip breaks the continuation.
 *
 * Author: Erik Opavsky
 * 
 * Date: 10/9/11
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int
main()
{
  int pairs = 0;        // the number of pairs of tails
  int i;                // the counter variable
  int previousFlip = 0; // remember what the previous coin flip had
  

  srand (time (NULL));  /* seed the random number generator with
                           the current system time so it is different
                           every time the program is run */

  for (i = 0; i < 100; i++) 
    {
      if (rand() % 2) // if we flipped 1 (tails)
        {
          if (previousFlip)
            pairs++;
          previousFlip = 1; // make sure we remember the flip
        }
      else // if we flipped 0 (heads)
        previousFlip = 0;
    } // for

  printf ("The number of pairs flipped was %d.\n", pairs);

  return 0;
} // main
