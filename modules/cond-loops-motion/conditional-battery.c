/* * * * *
 * conditional-battery.c
 *
 * The goal of this lab is to find the remaining battery value by counting 
 * beeps using if statements.
 *
 * Authors: Dilan Ustek, Erik Opavsky
 *
 * Date: 7 July 2011
 */

#include "MyroC.h"

int main()
{
  rConnect("/dev/rfcomm0");

  if (rGetBattery() > 1)
    rBeep(1, 500);

  if (rGetBattery() > 2)
    rBeep(1, 500);

  if (rGetBattery() > 3)
    rBeep(1, 500);

  if (rGetBattery() > 4)
    rBeep(1, 500);

  if (rGetBattery() > 5)
    rBeep(1, 500);

  if (rGetBattery() > 6)
    rBeep(1, 500);

  if (rGetBattery() > 7)
    rBeep(1, 500);

  if (rGetBattery() > 8)
    rBeep(1, 500);

  if (rGetBattery() > 9)
    rBeep(1, 500);

  rDisconnect();

  return 0;
} //main
