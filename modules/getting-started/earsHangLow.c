/* Annotated program for Scribbler beeping "Do Your Ears Hang Low"
 */

#include "MyroC.h" /* reference to MyroC library. All the commands
                      that have to do with the robot are defined in the 
                      header file "MyroC.h". The header file has the functions 
                      that the robot uses declared.*/

/* Musical notes in the scale, as they correspond to beep frequency*/
/* const is a constant variable. It needs to be initiated when it's 
   declared because they will not be altered.
   int is an integer.*/
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


/* Semicolons (;) are used to terminate every statement in C.*/

/* Double slashes shows a comment, which is only for the human eye.*/
/* This is also a comment.*/

/* Each C program contains a driver function/program, called main. Here, main uses no
   input parameters (hence the parentheses with nothing between them following main).*/

int /* This line says that main returns an integer value upon completion. */
main() /* beginning of main program */
{
  rConnect ("/dev/rfcomm0"); /* connect to robot */

  /* Now beep the song! */

  /* line 1: "Do your ears hang low?" */
  /* robot beeps with the pitch A5 (references to 880 Hz.) for 0.25 seconds. */
  rBeep (0.25, pitchB5); 
  rBeep (0.25, pitchA5);
  rBeep (0.5, pitchG5);
  rBeep (0.5, pitchG5);
  rBeep (0.5, pitchG5);

  /* line 2: "Do they wobble to and fro?" */
  rBeep (0.25, pitchB4);
  rBeep (0.25, pitchC5);
  rBeep (0.20, pitchD5);
  rBeep (0.20, pitchE5);
  rBeep (0.20, pitchD5);
  rBeep (0.20, pitchB4);
  rBeep (0.40, pitchD5);
 
  /* line 3: "Can you tie them in a knot?" */ 
  rBeep (0.25, pitchG5);
  rBeep (0.25, pitchA5);
  rBeep (0.20, pitchB5);
  rBeep (0.20, pitchB5);
  rBeep (0.20, pitchB5);
  rBeep (0.20, pitchB5);
  rBeep (0.50, pitchB5);

  /* line 4: "Can you tie them in a bow?" */  
  rBeep (0.25, pitchG5);
  rBeep (0.25, pitchA5);
  rBeep (0.20, pitchB5);
  rBeep (0.20, pitchA5);
  rBeep (0.20, pitchA5);
  rBeep (0.20, pitchGs5);
  rBeep (0.50, pitchA5);

  /* line 5: "Can you throw them o'er your shoulder" */
  rBeep (0.25, pitchB5);
  rBeep (0.25, pitchA5);
  rBeep (0.20, pitchG5);
  rBeep (0.20, pitchA5);
  rBeep (0.20, pitchG5);
  rBeep (0.20, pitchA5);
  rBeep (0.20, pitchG5);
  rBeep (0.20, pitchD5);
 

  /* line 6: "like a continental soldier?" */
  rBeep (0.20, pitchB4);
  rBeep (0.20, pitchC5);
  rBeep (0.20, pitchD5);
  rBeep (0.20, pitchE5);
  rBeep (0.20, pitchD5);
  rBeep (0.20, pitchB4);
  rBeep (0.20, pitchD5);
  rBeep (0.20, pitchD5);


  /* line 7: "Do your ears hang low?" */
  rBeep (0.20, pitchG5);
  rBeep (0.20, pitchA5);
  rBeep (0.7, pitchB5);
  rBeep (0.8, pitchA5);
  rBeep (1.1, pitchG5);

  rDisconnect(); /* disconnect from robot */

  return 0; /* return 0 if no errors occurred */
} /* end of main program */
