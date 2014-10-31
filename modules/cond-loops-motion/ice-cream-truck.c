/* * * * *
 * icecreamtruck.c
 *
 * Scribbler moves in a circle while playing "Do Your Ears Hang Low" (looped). 
 * User needs to press Ctrl-C to stop.
 *
 * Authors: April O'Neill, Dilan Ustek
 *
 * Date: 7 July 2011
 */

#include "MyroC.h"

/*  Musical notes in the scale, as they correspond to beep frequency */
const int pitchA4  = 440;
const int pitchBf4 = 466;
const int pitchAs4 = 466; 
const int pitchB4  = 493;
const int pitchC5  = 523;
const int pitchDf5 = 554;
const int pitchCs5 = 554; 
const int pitchD5  = 587;
const int pitchEf5 = 622;
const int pitchDs5 = 622;
const int pitchE5  = 659;
const int pitchF5  = 698;
const int pitchGf5 = 739;
const int pitchFs5 = 739; 
const int pitchG5  = 783;
const int pitchAf5 = 830;
const int pitchGs5 = 830;
const int pitchA5  = 880;
const int pitchBf5 = 932;
const int pitchAs5 = 932;
const int pitchB5  = 987;


int 
main()
{ /* connect to the Scribbler 2 robot */
  rConnect("/dev/rfcomm0");
  /* The Scribbler 2 has some sensors on its body, pointing one way,
     and additional sensors on the Fluke dongle with Bluetooth, pointing
     the other way.  The rSetForwardnessTxt command specifies which
     way should be considered as forward */
  rSetForwardnessTxt("fluke-forward");

  int i;

  /*  Infinite loop to play the song while moving 
      while(1)*/

  /*  repeat song 3 times */
  for (i = 1; i <= 3; i++)
    {

      /*  Move in a circle */
      rMotors(.1,1.0);  /* left motor moves at speed 0.1 (with max 1.0),
                           right moto moves at full speed (max 1.0),
                           so robot moves left until another command
                           changes the movement */

      /*  line 1: "Do your ears hang low?" */
 
      rBeep(0.25, pitchB5);
      rBeep(0.25, pitchA5);
      rBeep(0.5, pitchG5);
      rBeep(0.5, pitchG5);
      rBeep(0.5, pitchG5);

      rMotors(-.1,-1.0);  /* negative motor speeds indicate wheels will
                             turn backwards */

      /*  line 2: "Do they wobble to and fro?" */

      rBeep(0.25, pitchB4);
      rBeep(0.25, pitchC5);
      rBeep(0.20, pitchD5);
      rBeep(0.20, pitchE5);
      rBeep(0.20, pitchD5);
      rBeep(0.20, pitchB4);
      rBeep(0.40, pitchD5);

      rMotors(1.0,.1);

      /*  line 3: "Can you tie them in a knot?" */
  
      rBeep(0.25, pitchG5);
      rBeep(0.25, pitchA5);
      rBeep(0.20, pitchB5);
      rBeep(0.20, pitchB5);
      rBeep(0.20, pitchB5);
      rBeep(0.20, pitchB5);
      rBeep(0.50, pitchB5);

      rMotors(-1.0,-.1);

      /*  line 4: "Can you tie them in a bow?" */
  
      rBeep(0.25, pitchG5);
      rBeep(0.25, pitchA5);
      rBeep(0.20, pitchB5);
      rBeep(0.20, pitchA5);
      rBeep(0.20, pitchA5);
      rBeep(0.20, pitchGs5);
      rBeep(0.50, pitchA5);

      rMotors(.1,1.0);

      /*  line 5: "Can you throw them o'er your shoulder" */
 
      rBeep(0.25, pitchB5);
      rBeep(0.25, pitchA5);
      rBeep(0.20, pitchG5);
      rBeep(0.20, pitchA5);
      rBeep(0.20, pitchG5);
      rBeep(0.20, pitchA5);
      rBeep(0.20, pitchG5);
      rBeep(0.20, pitchD5);
 
      rMotors(-.1,-1.0);

      /*  line 6: "like a continental soldier?" */

      rBeep(0.20, pitchB4);
      rBeep(0.20, pitchC5);
      rBeep(0.20, pitchD5);
      rBeep(0.20, pitchE5);
      rBeep(0.20, pitchD5);
      rBeep(0.20, pitchB4);
      rBeep(0.20, pitchD5);
      rBeep(0.20, pitchD5);

      rMotors(1.0,.1);

      /*  line 7: "Do your ears hang low?" */

      rBeep(0.20, pitchG5);
      rBeep(0.20, pitchA5);
      rBeep(0.7, pitchB5);
      rBeep(0.8, pitchA5);
      rBeep(1.1, pitchG5);
      
    }

  rDisconnect();

  return 0;
} /*  main */
