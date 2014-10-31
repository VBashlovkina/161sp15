/* Program to count the number of times each letter in a file occurs *
 * Version 1:  reading file name within program, all work in main    */

#define MAX 20             /* maximum length of file name            */
#include <stdio.h>         /* library for file and keyboard I/O      */
#include <ctype.h>         /* library for testing character data     */

int main (void) 
{ FILE *file_var;
  char file_name[MAX];     /* string array for file name */
  int counts[26];          /* counts[0]..counts[25] for individual letters. */
  int non_letters = 0;     /* counter for non-letters  */
  int control_chars = 0;   /* counter for control characters (e.g., eol) */
  int i;                   /* loop index */
  char ch;                 /* character read from file */
 
  printf ("This program counts letter frequencies in a file\n");

  /* initialization */
  for (i=0; i<26; i++)
     counts[i] = 0;

  printf ("Enter file name: ");
  scanf ("%s", file_name);
  file_var = fopen (file_name, "r");

  /* processing the file */
  while ((ch = getc (file_var)) != EOF)
    { if (islower(ch))
         counts[ch - 'a']++;
      else if (isupper(ch))
         counts[ch - 'A']++;
      else if (iscntrl(ch))
         control_chars++;
      else non_letters++;
    }
  fclose (file_var);  /* finish up file */

  /* printing results */
  printf ("Frequency counts of letters in %s.\n\n", file_name);

  for (i='a'; i<= 'z'; i++)   /* integer i takes character values */
    printf ("  %c", i);      /* print integer value in integer format */
  printf ("\n");

  for (i=0; i < 26; i++)
    printf ("%3d", counts[i]);

  printf ("\nNon-letters:  %d\n", non_letters);
  printf ("Control characters:  %d\n", control_chars);
}
