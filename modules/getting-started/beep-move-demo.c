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
const int pitchB3  = 246;
const int pitchC4  = 261;
const int pitchDf4 = 277;
const int pitchCs4 = 277; /* = pitchDf4; */
const int pitchD4  = 293;
const int pitchEf4 = 311;
const int pitchDs4 = 311; /* = pitchEf4; */
const int pitchE4  = 329;
const int pitchF4  = 349;
const int pitchGf4 = 369;
const int pitchFs4 = 369; /* = pitchGf4; */
const int pitchG4  = 391;
const int pitchAf4 = 415;
const int pitchGs4 = 415; /* = pitchAf1; */
const int pitchA4  = 440;
const int pitchBf4 = 466;
const int pitchAs4 = 466; /* = pitchBf4; */
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

/* ***********************************************************
 * playing a note includes separating notes from each other 
 *     (by amount 0.1 * tempo)
 * ************************************************************ */
void play (double duration, double pitch) 
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
  play (beat1  , pitchE5);
  play (beat1  , pitchF5);
  play (beat1  , pitchG5);
  play (beat1_5, pitchA5);
  play (beat_5 , pitchA5);
  play (beat1_5, pitchA5);
  play (beat_5 , pitchA5);
  play (beat1  , pitchA5);
  play (beat1  , pitchD5);
  play (beat1  , silence);
    
  // second phrase
  play (beat_5 , pitchE5);
  play (beat_5 , pitchF5);
  play (beat1_5, pitchG5);
  play (beat_5 , pitchG5);
  play (beat1_5, pitchG5);
  play (beat_5 , pitchA5);
  play (beat2  , pitchC5);
  play (beat1  , silence);
    
  // third phrase 
  play (beat_5 , pitchD5);
  play (beat_5 , pitchE5);
  play (beat1_5, pitchF5);
  play (beat_5 , pitchF5);
  play (beat1_5, pitchF5);
  play (beat_5 , pitchF5);
  play (beat1  , pitchF5);
  play (beat1  , pitchB4);
  play (beat1_5, pitchC5);
  play (beat_5 , pitchD5);
  play (beat4  , pitchE5);
  play (beat1  , silence);
    
  // fourth phrase = first phrase
  play (beat1  , pitchE5);
  play (beat1  , pitchF5);
  play (beat1  , pitchG5);
  play (beat1_5, pitchA5);
  play (beat_5 , pitchA5);
  play (beat1_5, pitchA5);
  play (beat_5 , pitchA5);
  play (beat1  , pitchA5);
  play (beat1  , pitchD5);
  play (beat1  , silence);
    
  // fifth phrase = second phrase
  play (beat_5 , pitchE5);
  play (beat_5 , pitchF5);
  play (beat1_5, pitchG5);
  play (beat_5 , pitchG5);
  play (beat1_5, pitchG5);
  play (beat_5 , pitchA5);
  play (beat2  , pitchC5);
  play (beat1  , silence);
    
  // sixth phrase = third phrase with different ending 
  play (beat_5 , pitchD5);
  play (beat_5 , pitchE5);
  play (beat1_5, pitchF5);
  play (beat_5 , pitchF5);
  play (beat1  , pitchF5);
  play (beat1  , pitchE5);
  play (beat1_5, pitchD5);
  play (beat_5 , pitchD5);
  play (beat1  , pitchC5);
  play (beat1  , pitchB4);
  play (beat7  , pitchC5);
  play (beat1  , silence);
    
  // Chorus
  play (beat4  , pitchA5);
  play (beat3  , pitchB5);
  play (beat1  , pitchA5);
  play (beat4  , pitchG5);
  play (beat3  , pitchE5);
  play (beat1  , silence);
    
  play (beat3  , pitchF5);
  play (beat1  , pitchA5);
  play (beat3  , pitchG5);
  play (beat1  , pitchF5);
  play (beat5  , pitchE5);
  play (beat3  , silence);
  
  play (beat4  , pitchA5);
  play (beat3  , pitchB5);
  play (beat1  , pitchA5);
  play (beat4  , pitchG5);
  play (beat3  , pitchE5);
  play (beat1  , silence);
    
  play (beat3  , pitchF5);
  play (beat1  , pitchE5);
  play (beat3  , pitchD5);
  play (beat1  , pitchC5);
  play (beat5  , pitchC5);
  play (beat1  , silence);
}

void pirates ()
{
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

   double left = 0.33;
   double right = 0.66;
   int i;

   for (i = 0; i < 3; i++)
     {
       rMotors (left, right);
       play_spirit_song();

       left = 1 - left;
       right = 1 - right;

       pirates ();
       left = 1 - left;
       right = 1 - right;
      }

   rDisconnect ();

} 
