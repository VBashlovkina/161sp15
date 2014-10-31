/* Program to count the number of times each letter in a file occurs *
 * Version 2:  with main organized into procedures                   */

#define MAX 20             /* maximum length of file name            */
#include <stdio.h>         /* library for file and keyboard I/O      */
#include <ctype.h>         /* library for testing character data     */

void initialize (int counts[], char file_name[], FILE **filev);
/* procedure to initialize all program variables */

void process_file (FILE **filev, int counts[], int *others, int *control);
/* procedure to read file and determine character frequency counts */

void print_results (char name[], int counts [], int others, int control);
/* procedure to print the frequency counts in various categories */

int main (void) 
{ FILE *file_var;
  char file_name[MAX];     /* string array for file name */
  int counts[26];          /* counts[0]..counts[25] for individual letters. */
  int non_letters = 0;     /* counter for non-letters  */
  int control_chars = 0;   /* counter for control characters (e.g., eol) */
 
  printf ("This program counts letter frequencies in a file\n");
  initialize (counts, file_name, &file_var);
  process_file (&file_var, counts, &non_letters, &control_chars);
  print_results (file_name, counts, non_letters, control_chars);
}

void initialize (int counts[], char file_name[], FILE **filev)
/* procedure to initialize all program variables */
{ int i;
  for (i=0; i<26; i++)
     counts[i] = 0;
  printf ("Enter file name: ");
  scanf ("%s", file_name);
  (*filev) = fopen (file_name, "r");
}

void process_file (FILE **filev, int counts[], int *others, int *control)
/* procedure to read file and determine character frequency counts */
{  char ch;
   while ((ch = getc (*filev)) != EOF)
    { if (islower(ch))
         counts[ch - 'a']++;
      else if (isupper(ch))
         counts[ch - 'A']++;
      else if (iscntrl(ch))
         (*control)++;
      else (*others)++;
    }
  fclose (*filev);  /* finish up file */
}

void print_results (char name[], int counts[], int others, int control)
/* procedure to print the frequency counts in various categories */
{ int i;
  printf ("Frequency counts of letters in %s.\n\n", name);

  for (i='a'; i<= 'z'; i++)   /* integer i takes character values */
    printf ("  %c", i);      /* print integer value in integer format */
  printf ("\n");

  for (i=0; i < 26; i++)
    printf ("%3d", counts[i]);

  printf ("\nNon-letters:  %d\n", others);
  printf ("Control characters:  %d\n", control);
}
