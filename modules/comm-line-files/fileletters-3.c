/* Program to count the number of times each letter in a file occurs *
 * Version 3:  with the possibility of command-line input            */

#define MAX 20             /* maximum length of file name            */
#include <stdio.h>         /* library for file and keyboard I/O      */
#include <ctype.h>         /* library for testing character data     */
#include <string.h>        /* library for common string functions    */

void process_file (FILE **filev, int counts[], int *others, int *control);
/* procedure to read file and determine character frequency counts */

void process_char(char ch, int counts[], int *others_var, int *cntl_var);
/* procedure to increment frequency counts for the given character */

void print_results (char name[], int counts [], int others, int control);
/* procedure to print the frequency counts in various categories */

int main (int argc, char *argv[]) 
{ FILE *file_var;
  char file_name[MAX];     /* string array for file name */
  int counts[26]          /* counts[0]..counts[25] for individual letters. */
    = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};  /*initialize array with 0's */
  int non_letters = 0;     /* counter for non-letters  */
  int control_chars = 0;   /* counter for control characters (e.g., eol) */
 
  printf ("This program counts letter frequencies in a file\n");

  /* determine file name from command line, if present, or ask user */
  if (argc > 1)
     strcpy (file_name, argv[1]);/* copy command-line string to file_name */
  else {
     printf ("Enter file name: ");
     scanf ("%s", file_name);}

  /* work with file and file data */
  file_var = fopen (file_name, "r");
  process_file (&file_var, counts, &non_letters, &control_chars);
  fclose (file_var);  /* finish up file */

  /* report frequencies */
  print_results (file_name, counts, non_letters, control_chars);
}

void process_file (FILE **filev, int counts[], int *others, int *control)
/* procedure to read file and determine character frequency counts */
{  char ch;
   while ((ch = getc (*filev)) != EOF)
     process_char (ch, counts, others, control);
}


void process_char (char ch, int counts[], int *others_var, int *cntl_var)
/* procedure to increment frequency counts for the given character */
{ if (islower(ch))
       counts[ch - 'a']++;
    else if (isupper(ch))
       counts[ch - 'A']++;
    else if (iscntrl(ch))
       (*cntl_var)++;
    else (*others_var)++;
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
