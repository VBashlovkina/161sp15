/* * * * *
 * array-notes.c
 *
 * Notes for a song.
 *
 * Authors: Dilan Ustek, Erik Opavsky
 *
 * Date: 8 July 2011
 */

#include "MyroC.h"


// Musical notes in the scale, as they correspond to beep frequency

#define PITCHA4 440.0
#define PITCHBf4 466.164
#define PITCHAs4 466.164
#define PITCHB4  493.883
#define PITCHC5  523.251
#define PITCHDf5 554.37
#define PITCHCs5 554.37
#define PITCHD5  587.33
#define PITCHEf5 622.25
#define PITCHDs5 622.25
#define PITCHE5  659.26
#define PITCHF5  698.46
#define PITCHGf5 739.99
#define PITCHFs5 739.99
#define PITCHG5  783.99
#define PITCHAf5 830.61
#define PITCHGs5 830.61
#define PITCHA5  880
#define PITCHBf5 932.33
#define PITCHAs5 932.33
#define PITCHB5  987.77


int
main()
{
  rConnect("/dev/rfcomm0");

  /* notes for the song */
  double notes[] = { PITCHD5, 
                    PITCHD5,
                    PITCHA5, 
                    PITCHA5, 
                    PITCHB5, 
                    PITCHB5,
                    PITCHA5,
                    PITCHA5,
                    PITCHG5,
                    PITCHG5, 
                    PITCHFs5, 
                    PITCHFs5,
                    PITCHE5, 
                    PITCHE5,
                    PITCHD5 };

  /* Now beep each of the notes for 0.5 seconds. */
	/* --- Your Code Here --- */


  rDisconnect();

  return 0;
} // main



