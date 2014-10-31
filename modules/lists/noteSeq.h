#ifndef _NOTESEQ_H
#define _NOTESEQ_H
#include "pitch.h"
/* list operations for a linked list of notes */

/* set list to null */
void setNull (noteNode_t * first);

/* add notes at end of a tune (a melody or musical phrase) */
void addAtEnd (noteNode_t * first);

/* print notes in a tune (a melody or musical phrase) in tabular form */
void printTuneTable (noteNode_t first);

#endif
