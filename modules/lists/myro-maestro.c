/* *
 * myro-maestro.c 
 * This program facilitates creation, editing, and playback of a song
 * implemented as a doubly linked list.
 *
 * Playback occurs through the Scribbler robot's speaker.
 * 
 * Author: David Cowden
 * First version:  July-August 2011
 * Major revision: 4 August 2011
 * Revised:  November 13, 2011  by Henry M. Walker
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "MyroC.h"

/* Doubly linked list implementation should be in the "dlist.h" header. */
#include "dnode.h"

#define STRMAX 64

/* Unique identifier for list nodes */
int uid = 1;

/**************************************************************
 * Function prototypes and documentation
 *
 **************************************************************/

/* start the editor interface where the creative magic happens */
int editor (dnode_t *song);

/* play the notes in the list song */
void playSong (dnode_t song);

/* print a visual representation of the list song */
void printSong (dnode_t song);
void printNode (dnode_t current);

/***
 * saveSong and loadSong are provided for your convenience.  Do not worry 
 * about their implementation at this time.  It is beyond the scope of this 
 * project.
 */
/* Write the contents of song to a file for later use. */
int saveSong (dnode_t song);

/* 
   Read a saved song back in and populate song with the note data. */
int loadSong (dnode_t *song);

/* extract a yes/no response from the user */
int promptYN (char * prompt);

int main (void) {
  /* program to coordinate the menu options and calls the requested 
     function */ 

  dnode_t song = NULL;

  char option[STRMAX];          /* user response to menu selection */
  int dirty = 0;
  
  /* printf (  "@======================================================@\n"); */
  printf ("\n||+-.,.,.-~*'`'*~-.,_.~`~.,.-.,.~`~._,.-~*'`'*~-.,_,.-~|\n");
  printf (  "||*-.,_, -~*'`'*~ .,_.~`* - - Myro-+-Maestro - - *,`.,/\n");
  printf (  "||>_,*'*,.-~*'-.,A robot music suite!*.- ' - `',  `- |\n");
  printf (  "||*,.~.,_,. ~*'`'*~-.,_.~` . .-.,.~` ._, -~ '   -. _ /\n");
  printf (  "||+-.,_,. ~*'`'*~-.,_. `~,.  .~` . ,. ~ 'v1.7-.   , / \n\n");

  while (1) {
    /* print menu options */
    printf ("Options available\n");
    printf ("E - Enter the song editor\n");
    printf ("P - Play song on robot\n");
    printf ("D - Display all the notes in the song\n");
    printf ("S - Save the current song\n");
    printf ("L - Load a previous song\n");
    printf ("N - New song, start a new project\n");
    printf ("Q - Quit\n");

    /* determine user selection */
    printf ("Enter desired option: ");
    fgets (option, STRMAX, stdin);
    printf ("\n");
    
    switch (option[0])
      {
      case 'E': /* enter the song editor */
      case 'e': 
        editor   (&song);
        dirty = 1;
        break;
      case 'P': /* play song on robot */
      case 'p': 
        playSong  (song);
        break;
      case 'D': /* display all the notes in the song */
      case 'd': 
        printSong (song);
        break;
      case 'N': /* new song, start a new project */
      case 'n':
        if (dirty && !promptYN ("Unsaved changes will be lost!! Proceed?")) 
            song = NULL; 
        break;
      case 'S': /* save  the current song */
      case 's': 
        if (!saveSong  (song))
          dirty = 0;
        break;
      case 'L': /* load a previous song */
      case 'l': 
        if (!dirty)
          dirty = loadSong (&song); 
        else if (!promptYN ("Unsaved changes will be lost!! Proceed?")) 
          dirty = loadSong (&song); 
        break;
      case 'Q': /* quit */
      case 'q':
        if (dirty) 
          if (!promptYN ("Discard unsaved changes and exit anyway?"))
            { printf ("\n\n"); continue;} 
        printf ("Program terminated\n"); 
        return 0; 
        break;
      default: printf ("Invalid Option - Try Again!\n\n\n");  
        continue;
      }
    printf ("\n");
  }
}

/* prompt the user and print out a representation of the next N notes */
void printSong (dnode_t current) {
  if (!current)
    return (void) printf ("A masterpiece awaits your attention..\n\n");

  while (current) {
    printNode(current);
    current = (nextNode (current));
  }
  
}

/* prompt the user and play the next N notes */
void playSong (dnode_t current) {
  if (!current)
    return (void) printf ("Your song is yet unwritten..\n\n");
  
  rConnect("/dev/rfcomm0");
  while (current) {
    rBeep((getNodeNote (current)).time, (getNodeNote (current)).freq);
    current = (nextNode (current));
  }
  rDisconnect();
}

/*
 * Editor function prototype declarations...
 *
 */
/* gostart advances current to the beginning of the song */
void goStart (dnode_t *current);

/* gostart advances current to the end of the song */
void goEnd (dnode_t *current);

/* findID advances current to the location of the node who's id matches uid.
   If no matching id is found, current remains unchanged. */
void findID (dnode_t *current);

/* advance current one note (or none if at the end) */
void advance (dnode_t *current);

/* retreat current one note (or none if at the beginning) */
void retreat (dnode_t *current);

/* advance prompts the user for a number and advances current that many 
   notes */
void nAdvance (dnode_t *current);

/* retreatN prompts the user for a number and advances current backwards 
   that many notes */
void nRetreat (dnode_t *current);

/* prompt the user for note information (time and frequency) and add a node 
   containing that note structure BEFORE the current note. current becomes
   the new node */
void addNoteBefore (dnode_t *current);

/* prompt the user for note information (time and frequency) and add a node 
   containing that note structure AFTER the current note. current becomes
   the new node */
void addNoteAfter (dnode_t *current);

/* play the current note on the robot */
void playNote (dnode_t current);

/* remove note from the song and free its memory.
 * 
 * current becomes the next note if there is one.
 * if current is the last note, current becomes the previous note.
 * if current was the only note, current becomes NULL */
void removeNote (dnode_t *current);

/* prompt the user for new values (time and freq) for the current note */
void changeNote (dnode_t current);

/* print a count the total number of notes currently in the song */
void countNotes (dnode_t current);

/* prompt the user and print out a representation of the next N notes */
void nPrintSong (dnode_t current);

/* prompt the user and play the next N notes */
void nPlaySong (dnode_t current);

/* ---
 * -
 * Editor Control Function */
int editor(dnode_t * song) {

  dnode_t current = *song;  /* save the location of the first node */
  char option[STRMAX];   /* user response to menu selection */

  while(1) {
    printf ("Song Editor:\n");
    if (current)
      printf ("\tCurrent node id: %5u\tTime: %5lf sec\t\tNote: %5d Hz\n\n",
              (getNodeID (current)), (getNodeNote (current)).time, 
              (getNodeNote (current)).freq);
    else
      printf ("\tSong is currently EMPTY\n\n");
    printf ("Options\n");
    printf ("S - Go to start of song\n");
    printf ("E - Go to end of song\n");
    printf ("F - Find id and go to it\n");
    printf ("J - Advance 1 note\n");
    printf ("K - Move backwards 1 note\n");
    printf ("A - Advance N notes\n");
    printf ("B - Move backwards N notes\n");
    printf ("H - Insert a note into the song BEFORE current note\n");
    printf ("I - Insert a note into the song AFTER current note\n");
    printf ("Y - Play the current note through the robot\n");
    printf ("R - Remove the current note from the song\n");
    printf ("C - Change the values of the current note\n");
    printf ("N - Count the number of remaining notes in the song\n");
    printf 
      ("D - Display the next N notes in the song and the UIDs of the nodes\n");
    printf ("P - Play the remaining N notes in the song\n");
    printf ("X - Exit the editor\n");
  
    printf ("Enter desired option: ");
    fgets (option, STRMAX, stdin);

    printf("\n");

    switch (*option) {    
    case 'S': /* go to start of song */
    case 's': 
      goStart    (&current);
      break;
    case 'E': /* go to end of song */
    case 'e': 
      goEnd      (&current);
      break;
    case 'F': /* find id and go to it */
    case 'f':
      findID     (&current);
      break;
    case 'J': /* advance 1 note */
    case 'j': 
      advance    (&current);
      break;
    case 'K': /* move backwards 1 note */
    case 'k':
      retreat    (&current);
      break;
    case 'A': /* advance N notes */
    case 'a': 
      nAdvance   (&current);
      break;
    case 'B': /* move backwards N notes */
    case 'b':
      nRetreat    (&current);
      break;
    case 'H': /* insert a note into the song before current note */
    case 'h': 
      addNoteBefore    (&current);
      break;
    case 'I': /* insert a note into the song after current note */
    case 'i': 
      addNoteAfter    (&current);
      break;
    case 'Y': /* play the current note through the robot */
    case 'y': 
      playNote    (current);
      break;
    case 'R': /* remove the current note from the song */
    case 'r': 
      removeNote (&current);
      break;
    case 'C': /* change the values of the current note */
    case 'c': 
      changeNote  (current);
      break;
    case 'N': /* count the number of remaining notes in the song */
    case 'n': 
      countNotes  (current);
      break;
    case 'D': /* display the next N notes in the song and the UIDs of the node */
    case 'd': 
      nPrintSong  (current);
      break;
    case 'P': /* play the remaining N notes in the song */
    case 'p': 
      nPlaySong   (current);
      break;
    case 'X': /* exit the editor */
    case 'x':
      printf ("Finished editing\n");
      goStart(&current);
      *song = current;
      return 0;
      break;
    default: printf ("Invalid Option - Try Again!\n");
      continue;     
    }
  }
}

/* litter helper prototypes */
int promptINT (char * prompt);
unsigned int promptUINT (char * prompt);
double promptDBL (char * prompt);

/* gostart advances current to the beginning of the song */
void goStart (dnode_t *current) {
  dnode_t p = NULL;
  while (*current) {
    p = *current;
    *current = prevNode (p);
  }
  *current = p;    
}

/* gostart advances current to the end of the song */
void goEnd (dnode_t *current) {
  dnode_t n = NULL;
  while (*current) {
    n = *current;
    *current = nextNode (n);
  }
  *current = n;
}

/* findID advances current to the location of the node who's id matches uid.
   If no matching id is found, current remains unchanged. */
void findID (dnode_t *current) { 
  if (!(*current))
    return (void) printf ("No notes have been added yet..\n\n");
  
  dnode_t r;
  if (r = findNodeByID (*current, 
                        promptUINT("Enter the UID you wish to locate")))
    *current = r;
}

/* advance current one note (or none if at the end) */
void advance (dnode_t *current) {
  if (*current && (*current)->next)
    *current = nextNode (*current);
  else
    printf ("Cannot advance further. End of song reached!\n");
}

/* retreat current one note (or none if at the beginning) */
void retreat (dnode_t *current) {
  if (*current && prevNode (*current))
    *current = prevNode (*current);
  else
    printf ("Cannot retreat further. Beginning of song reached!\n");
}

/* advance prompts the user for a number and advances current that many 
   notes */
void nAdvance (dnode_t *current) {
  unsigned int n = promptUINT ("Enter the amount you wish to advance: ");
  dnode_t t = NULL;
  while ( *current && n-- ) {
    t = *current;
    *current = nextNode (t);
  }
  *current = t;
}

/* retreatN prompts the user for a number and advances current backwards 
   that many notes */
void nRetreat (dnode_t *current) {
  
  unsigned int n = promptUINT ("Enter the amount you wish to retreat: ");
  dnode_t t = NULL;
  while ( *current && n-- ) {
    t = *current;
    *current = prevNode (t);
  }
  *current = t;
}

/* prompt the user for note information (time and frequency) and add a node 
   containing that note structure before the current note. current becomes
   the new node */
void addNoteBefore (dnode_t *current) {
  int frequency = promptINT("Enter the note frequency: ");
  double duration = promptDBL("Enter the note duration (between 0.0 and 8.0): ");
  
  dnode_t new = createNode();
  Note d = { frequency, duration }; 

  setNodeNote (new, d);
  setNodeID (new, uid++);
  
  if (*current)
    insertNodeBefore (new, *current);
  *current = new;
}

/* prompt the user for note information (time and frequency) and add a node 
   containing that note structure after the current note. current becomes
   the new node */
void addNoteAfter (dnode_t *current) {
  int frequency = promptINT("Enter the note frequency: ");
  double duration = promptDBL("Enter the note duration (between 0.0 and 8.0): ");
  
  dnode_t new = createNode();
  Note d = { frequency, duration }; 

  setNodeNote (new, d);
  setNodeID (new, uid++);
  
  if (*current)
    insertNodeAfter (new, *current);
  *current = new;
}

/* play the current note on the robot */
void playNote (dnode_t current) {
  if (!current)
    return (void) printf ("No notes have been added yet..\n\n");
  
  rConnect("/dev/rfcomm0");
  rBeep((getNodeNote (current)).time, (getNodeNote (current)).freq);
  rDisconnect();
}

/* remove note from the song and free its memory. */
void removeNote (dnode_t *current) {
  if (!(*current))
    return (void) printf ("No note to remove..\n\n");
  

  dnode_t old = removeNode (*current);
  
  if (nextNode (old))
    *current = nextNode (old);
  else if (prevNode (old))
    *current = prevNode (old);
  else
    *current = NULL;  

  deleteNode(old);  
}

/* prompt the user for new values (time and freq) for the current note */
void changeNote (dnode_t current) {
  if (!current)
    return (void) printf ("No note to alter..\n\n");

  int frequency = promptINT("Enter the new note frequency: ");
  double duration = promptDBL
    ("Enter the new note duration (between 0.0 and 8.0): ");
  
  Note d = {frequency, duration};
  setNodeNote (current, d);
}

/* print a count the total number of notes currently in the song */
void countNotes (dnode_t current) {
  unsigned int c = 0;
  
  dnode_t rev = NULL;
  if (current)
    rev = (prevNode (current));
  
  while (current)
    current = (c++, (nextNode (current)));

  while (rev)
    rev = (c++, prevNode (rev));

  printf ("There are currently %5u notes in the song.\n\n", c);
}

/* prompt the user and print out a representation of the next N notes */
void nPrintSong (dnode_t current) {
  if (!current)
    return (void) printf ("No notes to print..\n\n");

  unsigned int n = promptUINT ("Enter the number of notes to print out: ");
  
  while (current && n--) {
    printNode(current);
    current = (nextNode (current));
  }
  
}

/* prompt the user and play the next N notes */
void nPlaySong (dnode_t current) {
  if (!current)
    return (void) printf ("No notes to play..\n\n");

  unsigned int n = promptUINT ("Enter the number of notes to play: ");
  
  rConnect("/dev/rfcomm0");
  while (current && n--) {
    rBeep((getNodeNote (current)).time, (getNodeNote (current)).freq);
    current = (nextNode (current));
  }
  rDisconnect();
}

void printNode(dnode_t current) {
  printf("Node   ID: %7u\tNote TIME: %7lf\tNote FREQ: %7d\n", 
         (getNodeID (current)), (getNodeNote (current)).time, 
         (getNodeNote (current)).freq);
}

int promptINT (char * prompt) {
  char buff[STRMAX];
  printf (prompt);
  fgets (buff, STRMAX, stdin);
  printf ("\n\n");
  return atoi (buff);
}

double promptDBL (char * prompt) {
  char buff[STRMAX];
  printf (prompt);
  fgets (buff, STRMAX, stdin);
  printf ("\n\n");
  return strtod (buff, NULL);
}

unsigned int promptUINT (char * prompt) {
  char buff[STRMAX];
  printf (prompt);
  fgets (buff, STRMAX, stdin);
  printf ("\n\n");
  return (int) strtoul (buff, NULL, 0);
}

int promptYN (char * prompt) {
  char ans[5];
    printf ("%s [y/n]", prompt);
    fgets (ans, 5, stdin);
    return ( *ans == 'Y' || *ans == 'y' );
}

/* **D***********o********************************************************* /
/ ***********************N************************************************* /
/ ************************o************************************************ /
/ ****************************t******************************************** /
/ ***********************************************E************************* /
/ *********************************************************n*************** /
/ **********************************************************t************** /
/ ******************************************************************e****** /
/ *********************************************************************r*** /
/ **********************************************************************!! */

#define VERSION 1177l
#define MAXFILE 256
/* Write the contents of song to a file for later use. 
 */
int saveSong (dnode_t song)
{
  if (!song)
    return (void) printf 
      ("List contains no note information to save..\n\n"), 1;
      
  char buff[MAXFILE];
  printf ("Write to file: ");
  fgets(buff, MAXFILE, stdin);
  
  char * ret = strchr(buff, '\n');
  if (ret)
    *ret = '\0';

  FILE * f = fopen(buff, "r");
  
  if (f) {    
    if (!promptYN ("File %s already exists, overwrite?"))
      return (void) printf ("Save failed.. please try again.\n"), 2;
  }

  f = fopen(buff, "w");
  
  long version = VERSION;
  fwrite (&version, sizeof(long), 1, f);
  
  Note d;
  while (song) {
    d = getNodeNote (song);
    fwrite (&d, sizeof(Note), 1, f);
    song = nextNode (song);
  }
  
  fclose(f);
  printf ("Save successful!\n\n");
  return 0;
}

/* Read a saved song back in and populate song with the note data.
 */
 int loadSong (dnode_t *song)
 {
   char buff[MAXFILE];
   printf ("Load from file: ");
   fgets(buff, MAXFILE, stdin);

   char * ret = strchr(buff, '\n');
   if (ret)
     *ret = '\0';

   FILE * f = fopen(buff, "r");
   
   if (!f)
     return (void) printf ("File: '%s' does not exist.. load failed.\n\n", 
                           buff), 0;
   
   long version;
   fread (&version, sizeof(long), 1, f);
   if (version != VERSION)
     return (void) printf ("Incompatible save format.. load failed.\n\n"), 0;

   int stat;
   Note dat;
   dnode_t nd;
   dnode_t current = *song = NULL;
   while ( (stat = fread (&dat, sizeof(Note), 1, f)) == 1 ) {
     nd = createNode();
     setNodeNote (nd, dat);
     setNodeID (nd, uid++);

     if ( !(*song) )
       *song = current = nd;
     else
       insertNodeAfter ( nd, current );  
     
     current = nd;
   }
   
   fclose(f);
   printf ("Load successful!\n\n");   
   return 0;
 }
