/* music composition assistant */

#include "pitch.h"
#include "noteNode.h"
#include <stdio.h>
#include <ctype.h>  /* for character function isalpha */

/* print composer's operation menu 
   read desired menu option
   returns a lower-case letter
   input line cleared 
*/
char printAndChooseMenu ();

/* select tune choice
   returns:
     m:  melody
     p:  separate musical phrase
*/ 
char readTune ();

int main (void)
{
  /* pointer to first note of the melody */
  noteNode_t melodyFirst = NULL;
  /* pointer to first note of the separate musical phrase */
  noteNode_t phraseFirst = NULL;

  printf ("Music composition assistant\n");

  int done = 0;
  while (!done)
    {
      char option = printAndChooseMenu();
      char tune;
      switch (option)
        {
        case 'n':
          tune = readTune();
          if (tune == 'm')
            setNull(&melodyFirst);
          else
            setNull(&phraseFirst);
          break;
        case 'a':
          tune = readTune();
          if (tune == 'm')
            addAtEnd(&melodyFirst);
          else
            addAtEnd(&phraseFirst);
          break;
        case 'p':
          tune = readTune();
          if (tune == 'm')
            printTuneTable(melodyFirst);
          else
            printTuneTable(phraseFirst);
          break;
        case 'q':
          printf ("program completed\n");
          return 0;
        default:
          printf ("unrecognized option\n");
        }
    }

  return 0;
}


/* print composer's operation menu 
   read desired menu option
   returns a lower-case letter
   input line cleared 
*/
char printAndChooseMenu ()
{
  printf ("menu options: \n");
  printf ("  n:  set tune (melody or musical phrase) to NULL\n");
  printf ("  a:  add notes to end of tune\n");
  printf ("  p:  print table of current notes in tune\n");
  printf ("  q:  quit\n");
  char ch;

  /* get menu option */
  while (!isalpha(ch = getchar()));

  /* strip remaining characters on line */
  while (getchar() != '\n');

  return tolower(ch);
}


/* select tune choice
   returns:
     m:  melody
     p:  separate musical phrase
*/ 
char readTune ()
{
  printf ("Enter tune type:  m - melody, p - separate musical phrase:\n");\
  char ch = ' ';

  while (1)
    {
      while (!isalpha(ch = getchar()));
      ch = tolower(ch);

      /* strip remaining characters on line */
      while (getchar() != '\n');

      if (ch == 'm' || ch == 'p')
        break;
      else
        printf ("   enter 'm' or 'p'\n");
    }
  
  return tolower(ch);

}

