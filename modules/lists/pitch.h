#ifndef _PITCH_H
#define _PITCH_H

/* structure for one musical pitch */
typedef struct pitch
{
  char * name;
  char * altName;
  int octave;
  int freq;
} pitch;

#endif
