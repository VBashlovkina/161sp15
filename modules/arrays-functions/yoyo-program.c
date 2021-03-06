/* program to use functions with value parameters to control a robot */

#include <stdio.h>
#include "MyroC.h"

/* yoyo illustrates:
      function with 1 parameter:  count
                    2 local variables: i, reps
                    1 return value
*/
int yoyo (int count) 
{
  int i;
  int reps = 3*count;

  /* repeat motion */
  for (i = 0; i < reps; i++) 
    { 
      rForward (1, .5); 
      rBackward (1, .5); 
    } 
                  
   sleep (3); 
                  
  /* print local variables */
  printf ("in yoyo:  count = %d, reps = %d\n", count, reps);

   return reps; 
} // yoyo


int main ()
{
  rConnect ("/dev/rfcomm0");

  int repetitions, result;
  
  repetitions = 2;
  result = yoyo (repetitions);
  printf ("repetitions = %d,   result = %d\n", repetitions, result);

  rDisconnect ();
}
