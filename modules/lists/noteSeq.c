/* implimentation of
   list operations for a linked list of notes */

#include "pitch.h"
#include "noteNode.h"
#include <stdio.h>
#include <stdlib.h>

extern pitch scale[88];

/* set list to null */
void setNull (noteNode_t * first)
{
  /* deallocate space for any nodes in current melody */
    noteNode_t ptr = *first;
    while (ptr != NULL)
      {
        noteNode_t oldPtr = ptr;
        ptr = ptr->next;
        free (oldPtr);
      }

    /* set original pointer to NULL */
    *first = NULL;
 }

/* read a note's name, octave, and duration 
   return noteNode (with index of note in the "scale" array within pitch.h)
           or NULL indicating the note was not found.
   input line is cleared when procedure finishes
*/
noteNode_t readNote ()
{
  char name[10];
  int octave;
  double duration;
  printf ("enter note-name octave duration: ");
  scanf ("%s", name);
  name[0] = toupper(name[0]);  /* letter is capitalized in table */
  name[1] = tolower(name[1]);  /* sharp/flat is in lower case */
  if (name[0] == 'Q')
    {
      /* clear rest of input line */
      while (getchar() != '\n');
      return NULL;
    }
  scanf ("%d", &octave);
  scanf ("%lf", &duration);

  /* clear rest of input line */
  while (getchar() != '\n');

  int i;
  /* search through notes on the piano */
  for (i = 0; i < 88; i++)
    {
      if (((strcmp(name, scale[i].name) == 0) 
           || (strcmp(name, scale[i].altName) == 0))
          && (octave == scale[i].octave))
        {  /* note found on piano */
          printf("note found with index %d\n", i);
          noteNode_t newNote = malloc (sizeof (noteNode));
          newNote->arrInd = i;
          newNote->duration = duration;
          newNote->next = NULL;
          return newNote;
        }
    }
 
  /* note not found in scale */
  return NULL;
}

/* add notes at end of a tune (a melody or musical phrase) */
void addAtEnd (noteNode_t * first)
{
  printf ("enter note information, concluding with Q for the note-namen\n");
  
  noteNode_t newNote = readNote ();
  if (newNote == NULL)
    { 
      printf ("note addition completed\n");
      return;
    }

  noteNode_t ptrToLast;  /* pointer to the last node in the tune */

  if (*first == NULL)
    {
      /* list is null, so read and insert first item */
      *first = newNote;
      ptrToLast = *first;
      newNote = readNote ();
    }
  else
    {
      /* find end of tune in linked list */
      ptrToLast = *first;
      while (ptrToLast->next != NULL)
        {
          ptrToLast = ptrToLast->next;
        }
    }

  while (newNote != NULL)
    {
      /* insert note at end and read next note */
      ptrToLast->next = newNote;
      ptrToLast = newNote;
      newNote = readNote ();
    }    
  printf ("note addition completed\n");
}

/* print notes in a tune (a melody or musical phrase) in tabular form */
void printTuneTable (noteNode_t first)
{
  noteNode_t ptr = first;
  if (ptr == NULL)
    {
      printf ("The tune contains no notes\n");
    }
  else
    { 
      printf ("  index  name  octave  frequency  duration\n");
      int seqNumber = 1;
      while (ptr != NULL)
        {
          /* print table entry */
          printf ("%5d", seqNumber);
          int arrIndex = ptr->arrInd;
          printf ("     %-2s", scale[arrIndex].name);
          printf ("%7d", scale[arrIndex].octave);
          printf ("%11d", scale[arrIndex].freq);
          printf ("%10.2lf", ptr->duration);
          printf ("\n");

          /* move to next note */
          seqNumber++;
          ptr = ptr->next;
        }
      printf ("end of tune\n");
    }
}
