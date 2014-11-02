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

/*
 The return value of rGetLightTxt ranges from 65408 
 for very dark to 0 for very bright. The second argument
 (in our case integer 3) is the number of times the sensor 
 samples the light. For details, see MyroC.h	
*/
  if (rGetLightTxt("center", 3) < 65409) 
    rBeep(1, 500);

  if (rGetLightTxt("center", 3) < 60000)
    rBeep(1, 500);

  if (rGetLightTxt("center", 3) < 55000)
    rBeep(1, 500);

  if (rGetLightTxt("center", 3) < 50000)
    rBeep(1, 500);

  if (rGetLightTxt("center", 3) < 45000)
    rBeep(1, 500);

  if (rGetLightTxt("center", 3) < 40000)
    rBeep(1, 500);

  if (rGetLightTxt("center", 3) < 35000)
    rBeep(1, 500);

  if (rGetLightTxt("center", 3) < 30000)
    rBeep(1, 500);

  if (rGetLightTxt("center", 3) < 25000)
    rBeep(1, 500);

  rDisconnect();

  return 0;
} //main
