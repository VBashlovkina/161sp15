/* Annotated version of the program that plays "Spirit Song". 
   Only the chorus is taken and the beats are turned into seconds. 
*/

#include "MyroC.h"  /* reference to MyroC library */

/* Musical notes in the scale, as they correspond to beep frequency */
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


int main()  /* beginning of main program */
{

rConnect("/dev/rfcomm0"); /* connect to robot */

/* Now beep the song! */

/* Chorus */
rBeep (1, pitchA5); /* robot beeps with the pitch A5 (references to 880 Hz.) 
                       for beat4 seconds. */
rBeep (0.75, pitchB5);
rBeep (0.25, pitchA5);
rBeep (1, pitchG5);
rBeep (0.75, pitchE5);
    
rBeep (0.75, pitchF5);
rBeep (0.25, pitchA5);
rBeep (0.75, pitchG5);
rBeep (0.25, pitchF5);
rBeep (1.25, pitchE5);

rBeep (1, pitchA5);
rBeep (0.75, pitchB5);
rBeep (0.25, pitchA5);
rBeep (1, pitchG5);
rBeep (0.75, pitchE5);
    
rBeep (0.75, pitchF5);
rBeep (0.25, pitchE5);
rBeep (0.75, pitchD5);
rBeep (0.25, pitchC5);
rBeep (1.0, pitchC5);

rDisconnect (); /* disconnect from robot */

return 0; /* return 0 if no errors occurred */
} /* end of main */
