/* motors-test.c
 *
 * Sets the motor speeds of the Scribbler to the given leftspeed and rightspeed.
 * Program written to teach assert statements in the testing lab. Contains the library
 * <assert.h>.
 *
 * Author: Dilan Ustek
 *
 * Date: 28 Jul 2011
 */

#include "MyroC.h"
#include <stdio.h>
#include <assert.h>

int
main()
{

  rConnect ("/dev/rfcomm0");
  rSetForwardnessTxt ("fluke-forward");

  double leftspeed;
  double rightspeed;

  /* Preconditions for rMotors:
     Postconditions for rMotors:
  */
  rMotors (leftspeed, rightspeed);
  sleep (2);

  rDisconnect();
}
