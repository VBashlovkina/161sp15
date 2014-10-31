/* Simple program to introduce robot commands for the scribbler robot
   this program causes the scribbler to beep once
*/

#include "MyroC.h"

/* ***********************************************************
 * define initial variables regarding tempo, beats, and pitch
 * ************************************************************ */

/* tempo gives seconds per beat */
/*const double tempo = 1.0/2.0; */ // a beat is 1/2 second 
/* C does not allow a constant identifier to be used in defining other 
   constants, so use #define to define tempo as a computable number */
#define tempo 0.5

/* variable beatm_n indicates m.n beats,
 *   so beat1_5 is 1 1/2 beats */
const double beat_5   = tempo / 2.0;
const double beat1    = tempo;
const double beat1_5  = tempo * 1.5;
const double beat2    = tempo * 2;
const double beat2_5  = tempo * 2.5;
const double beat3    = tempo * 3;
const double beat3_5  = tempo * 3.5;
const double beat4    = tempo * 4;
const double beat5    = tempo * 5;
const double beat6    = tempo * 6;
const double beat7    = tempo * 7;
    
/* pitches in treble clef, with octave 1 just above middle C
 *   all pitches are tuned to concert A = 440
 *   for variable names, s or f means sharp or flat
 *   number at end of variable name gives octave above middle C
 *   the following frequencies are from the Piano_key_frequencies article 
 in Wikipedia */
const int silence  = 0;
const int pitchB0  = 246;
const int pitchC1  = 261;
const int pitchDf1 = 277;
const int pitchCs1 = 277; /* = pitchDf1; */
const int pitchD1  = 293;
const int pitchEf1 = 311;
const int pitchDs1 = 311; /* = pitchEf1; */
const int pitchE1  = 329;
const int pitchF1  = 349;
const int pitchGf1 = 369;
const int pitchFs1 = 369; /* = pitchGf1; */
const int pitchG1  = 391;
const int pitchAf1 = 415;
const int pitchGs1 = 415; /* = pitchAf1; */
const int pitchA1  = 440;
const int pitchBf1 = 466;
const int pitchAs1 = 466; /* = pitchBf1; */
const int pitchB1  = 493;
const int pitchC2  = 523;

/* ***********************************************************
 * playing a note includes separating notes from each other 
 *     (by amount 0.1 * tempo)
 * ************************************************************ */
void play (double duration, int pitch) 
{
  rBeep (duration - 0.1 * tempo, pitch);
  rBeep (0.1 * tempo, 0.0);
}

/* ***********************************************************
 * play Spirit Song by John Wimbar (from Songs book, page 170A)
 * ************************************************************ */
void play_spirit_song ()
{
  // introduction
  //speak("Spirit Song by John Wimbar");

  /*
  sleep(0.25);
  if (tempo == 1)
    speak("The song is played with 1 beat taking 1 second.");
  else
    {
      char str[80];  
      sprintf (str, "The song is played with 1 beat taking %0.2f seconds.",
		      tempo);
      speak(str);    
	  }
  sleep(0.25);
  */

  // first phrase
  // sleep(beat5);
  play (beat1  , pitchE1);
  play (beat1  , pitchF1);
  play (beat1  , pitchG1);
  play (beat1_5, pitchA1);
  play (beat_5 , pitchA1);
  play (beat1_5, pitchA1);
  play (beat_5 , pitchA1);
  play (beat1  , pitchA1);
  play (beat1  , pitchD1);
  sleep(beat1);
    
  // second phrase
  play (beat_5 , pitchE1);
  play (beat_5 , pitchF1);
  play (beat1_5, pitchG1);
  play (beat_5 , pitchG1);
  play (beat1_5, pitchG1);
  play (beat_5 , pitchA1);
  play (beat2  , pitchC1);
  sleep(beat1);
    
  // third phrase 
  play (beat_5 , pitchD1);
  play (beat_5 , pitchE1);
  play (beat1_5, pitchF1);
  play (beat_5 , pitchF1);
  play (beat1_5, pitchF1);
  play (beat_5 , pitchF1);
  play (beat1  , pitchF1);
  play (beat1  , pitchB0);
  play (beat1_5, pitchC1);
  play (beat_5 , pitchD1);
  play (beat4  , pitchE1);
    
  // fourth phrase = first phrase
  sleep(beat1);
  play (beat1  , pitchE1);
  play (beat1  , pitchF1);
  play (beat1  , pitchG1);
  play (beat1_5, pitchA1);
  play (beat_5 , pitchA1);
  play (beat1_5, pitchA1);
  play (beat_5 , pitchA1);
  play (beat1  , pitchA1);
  play (beat1  , pitchD1);
  sleep(beat1);
    
  // fifth phrase = second phrase
  play (beat_5 , pitchE1);
  play (beat_5 , pitchF1);
  play (beat1_5, pitchG1);
  play (beat_5 , pitchG1);
  play (beat1_5, pitchG1);
  play (beat_5 , pitchA1);
  play (beat2  , pitchC1);
  sleep(beat1);
    
  // sixth phrase = third phrase with different ending 
  play (beat_5 , pitchD1);
  play (beat_5 , pitchE1);
  play (beat1_5, pitchF1);
  play (beat_5 , pitchF1);
  play (beat1  , pitchF1);
  play (beat1  , pitchE1);
  play (beat1_5, pitchD1);
  play (beat_5 , pitchD1);
  play (beat1  , pitchC1);
  play (beat1  , pitchB0);
  play (beat7  , pitchC1);
  sleep(beat1);
    
  // Chorus
  play (beat4  , pitchA1);
  play (beat3  , pitchB1);
  play (beat1  , pitchA1);
  play (beat4  , pitchG1);
  play (beat3  , pitchE1);
  sleep(beat1);
    
  play (beat3  , pitchF1);
  play (beat1  , pitchA1);
  play (beat3  , pitchG1);
  play (beat1  , pitchF1);
  play (beat5  , pitchE1);
  sleep(beat3);
  
  play (beat4  , pitchA1);
  play (beat3  , pitchB1);
  play (beat1  , pitchA1);
  play (beat4  , pitchG1);
  play (beat3  , pitchE1);
  sleep(beat1);
    
  play (beat3  , pitchF1);
  play (beat1  , pitchE1);
  play (beat3  , pitchD1);
  play (beat1  , pitchC1);
  play (beat5  , pitchC1);
}

/* ***********************************************************
 * organize overall interaction with scribbler robot:
 *   correct to scribbler
 *        in connecting on Bluetooth, use password:
 *             1234
 *    play Spirit Song by John Wimbar (from Songs book, page 170A)
 *    disconnect from scribbler
 * ************************************************************ */

int main() 
{

   rConnect("/dev/rfcomm0");

   play_spirit_song();

   rDisconnect ();

} 
