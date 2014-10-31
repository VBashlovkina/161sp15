#include "MyroC.h"

/*********
 * pirates.c
 *
 * Program plays the Pirates of the Caribbean theme song using the Scribbler
 *  2 robot beep function.
 *
 * Authors: Erik Opavsky, April O'Neill
 *
 * Date: 13 July 2011
 *********/

// Musical notes in the scale, as they correspond to beep frequency
const int pitchG4  = 415;
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
const int pitchC6 = 1046;

int
main()
{
  rConnect ("/dev/rfcomm0");

  // First section (43 notes)
  rBeep (0.5, pitchE5);
  rBeep (0.25, pitchE5);
  rBeep (0.25, pitchF5);
  rBeep (0.25, pitchE5);
  rBeep (0.25, pitchF5);
  rBeep (0.5, pitchE5);
  rBeep (0.25, pitchE5);
  rBeep (0.25, pitchF5);
  rBeep (0.25, pitchE5);
  rBeep (0.25, pitchF5);
  rBeep (0.5, pitchE5);
  rBeep (0.25, pitchE5);
  rBeep (0.25, pitchF5);
  rBeep (0.25, pitchE5);
  rBeep (0.25, pitchF5);
  rBeep (0.5, pitchE5);
  rBeep (0.25, pitchE5);
  rBeep (0.25, pitchF5);
  rBeep (0.25, pitchG5);
  rBeep (0.25, pitchF5);
  rBeep (0.5, pitchE5);
  rBeep (0.25, pitchE5);
  rBeep (0.25, pitchF5);
  rBeep (0.25, pitchE5);
  rBeep (0.25, pitchF5);
  rBeep (0.5, pitchE5);
  rBeep (0.25, pitchE5);
  rBeep (0.25, pitchF5);
  rBeep (0.25, pitchE5);
  rBeep (0.25, pitchF5);
  rBeep (0.5, pitchE5);
  rBeep (0.25, pitchE5);
  rBeep (0.25, pitchF5);
  rBeep (0.25, pitchE5);
  rBeep (0.25, pitchF5);
  rBeep (0.5, pitchE5);
  rBeep (0.25, pitchE5);
  rBeep (0.25, pitchF5);
  rBeep (0.25, pitchG5);
  rBeep (0.25, pitchF5);
  rBeep (0.5, pitchE5);
  rBeep (0.5, pitchE5);
  rBeep (0.5, pitchE5);


  // Second section (21 notes)
  rBeep (0.5, pitchD5);
  rBeep (0.25, pitchC5);
  rBeep (0.25, pitchD5);
  rBeep (0.25, pitchE5);
  rBeep (0.25, pitchF5);
  rBeep (0.25, pitchA4);
  rBeep (0.5, pitchD5);
  rBeep (0.25, pitchF5);
  rBeep (0.25, pitchE5);
  rBeep (0.25, pitchC5);
  rBeep (0.25, pitchD5);
  rBeep (0.25, pitchA4);
  rBeep (0.5, pitchD5);
  rBeep (0.25, pitchC5);
  rBeep (0.25, pitchD5);
  rBeep (0.25, pitchE5);
  rBeep (0.25, pitchF5);
  rBeep (0.25, pitchG5);
  rBeep (0.5, pitchE5);
  rBeep (0.5, pitchA5);
  rBeep (0.5, pitchA5);


  // Pause
  sleep (1);

  // Third Section (29 notes)
  rBeep (0.5, pitchD5);
  rBeep (0.5, pitchE5);
  rBeep (1, pitchF5);
  rBeep (0.5, pitchG5);
  rBeep (0.5, pitchA5);
  rBeep (0.5, pitchG5);
  rBeep (0.5, pitchF5);
  rBeep (0.5, pitchE5);
  rBeep (0.5, pitchF5);
  rBeep (0.5, pitchG5);
  rBeep (0.5, pitchA5);
  rBeep (0.5, pitchG5);
  rBeep (0.25, pitchF5);
  rBeep (0.25, pitchG5);
  rBeep (0.5, pitchA5);
  rBeep (0.5, pitchG5);
  rBeep (0.5, pitchF5);
  rBeep (0.5, pitchE5);
  rBeep (0.5, pitchF5);
  rBeep (0.5, pitchE5);
  rBeep (1, pitchD5);
  rBeep (0.5, pitchF5);
  rBeep (0.5, pitchE5);
  rBeep (0.25, pitchC5);
  rBeep (0.25, pitchC5);
  rBeep (0.25, pitchG4);
  rBeep (0.25, pitchG4);
  rBeep (0.25, pitchG4);
  rBeep (0.25, pitchG4);


  // Pause
  sleep (1);

  // Fourth section (31 notes)
  rBeep (0.5, pitchD5);
  rBeep (0.25, pitchE5);
  rBeep (0.25, pitchFs5);
  rBeep (0.25, pitchG5);
  rBeep (0.25, pitchE5);
  rBeep (0.5, pitchFs5);
  rBeep (0.5, pitchE5);
  rBeep (0.5, pitchD5);
  rBeep (0.5, pitchE5);
  rBeep (0.25, pitchE5);
  rBeep (0.25, pitchFs5);
  rBeep (0.25, pitchG5);
  rBeep (0.25, pitchE5);
  rBeep (0.5, pitchFs5);
  rBeep (0.5, pitchG5);
  rBeep (0.5, pitchA5);
  rBeep (0.5, pitchA5);
  rBeep (0.25, pitchA5);
  rBeep (0.25, pitchB5);
  rBeep (0.25, pitchC6);
  rBeep (0.25, pitchE5);
  rBeep (0.5, pitchG5);
  rBeep (0.5, pitchFs5);
  rBeep (0.5, pitchE5);
  rBeep (0.5, pitchFs5);
  rBeep (0.5, pitchE5);
  rBeep (0.5, pitchD5);
  rBeep (0.5, pitchE5);
  rBeep (0.5, pitchE5);
  rBeep (0.5, pitchE5);
  rBeep (1, pitchE5);


  // Pause
  sleep (1);

  // Fifth section (33 notes)
  rBeep (0.5, pitchE5);
  rBeep (0.25, pitchE5);
  rBeep (0.25, pitchFs5);
  rBeep (0.25, pitchG5);
  rBeep (0.25, pitchE5);
  rBeep (0.5, pitchFs5);
  rBeep (0.5, pitchE5);
  rBeep (0.5, pitchD5);
  rBeep (0.5, pitchE5);
  rBeep (0.25, pitchE5);
  rBeep (0.25, pitchFs5);
  rBeep (0.25, pitchG5);
  rBeep (0.25, pitchE5);
  rBeep (0.5, pitchFs5);
  rBeep (0.5, pitchG5);
  rBeep (0.5, pitchA5);
  rBeep (0.5, pitchA5);
  rBeep (0.25, pitchA5);
  rBeep (0.25, pitchB5);
  rBeep (0.25, pitchC6);
  rBeep (0.25, pitchE5);
  rBeep (0.5, pitchG5);
  rBeep (0.5, pitchFs5);
  rBeep (0.5, pitchE5);
  rBeep (0.5, pitchFs5);
  rBeep (0.5, pitchE5);
  rBeep (0.5, pitchD5);
  rBeep (0.5, pitchE5);
  rBeep (0.25, pitchG5);
  rBeep (0.25, pitchG5);
  rBeep (0.25, pitchB5);
  rBeep (0.25, pitchB5);
  rBeep (0.5, pitchB5);

  rDisconnect();
  return 0;
} // main
