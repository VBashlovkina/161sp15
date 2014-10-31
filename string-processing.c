/* program illustrating various string operations within C */

/* library needed for input and output */
#include <stdio.h>

/* library needed for string manipulation */
#include <string.h>

/* library needed for conversions from strings to numbers */
#include <stdlib.h>

/* library for testing types of characters */
#include <ctype.h>

/* parameters to main retrieve any arguments specified by a 
   user on the command line*/
int main (int argc, char * argv[])
{
  int i;  /* index variable used throughout */

  /* reading command-line parameters */
  if (argc == 1)
    printf ("no command-line arguments supplied to this program\n");
  else {
    printf ("parmaters entered from the command line\n");
    printf ("\t this program:  %s\n", argv[0]);
    for (i = 1; i < argc; i++)
      {
        printf ("\t parameter %d: %s\n", i, argv[i]);
      }
  }

  /* "computer science" has 16 characters.  Also, one array element
     is needed for the terminating null character */
  char myArray[18] = "computer science";

  /* accessing individual characters */
  printf ("accessing individual characters\n");
  for (i = 0; i < strlen(myArray); i++)
    printf ("\tmyArray[%d] = %c\n", i, myArray[i]);


  /* extracting substrings from a string */
  /* the example uses myArray from above as the starting point */
  printf ("extracting substrings from a string\n");
  char subArray[20];  /* for a string copy, remember to have allocated space! */
  strncpy (subArray, myArray, 8);
  subArray[8] = 0; /* null terminate array */
  printf ("\t extract the first 8 characters (plus the null): %s\n", subArray);

  strncpy (subArray, myArray+3, strlen(myArray)); /* copying past end of myArray fills will nulls */
  printf ("\t extract all characters after the first 3: %s\n", subArray);
  
  int start = strlen(myArray) - 8;
  strncpy (subArray, myArray+start, 8);
  subArray[strlen(myArray)-8] = 0; /* null terminate array */
  printf ("\t extract the last 8 characters (plus the null): %s\n", subArray);
  


  /* breaking a string into pieces */
  char year[] = "January,February,March,April,May,June,July,August,September,October,November,December" ;
  /* copy original array */  
  char * yearCopy = malloc(sizeof(char)*(strlen(year) + 1));
  strcpy (yearCopy, year);
  /* array to receive the string pieces, including space for NULL strtok at end */
  char * months[13];
  /* loop puts strings into successive elements of months array */
  months[0] = strtok(yearCopy, ",");
  i = 1;
  while (months[i] = strtok(NULL, ",")) /* continue as long as token not NULL */
    {
      i++;
    }
  printf ("result of using strtok to break up a string of months\n");
  for (i = 0; i < 12; i++)
    printf ("\t month %d: %s\n", i, months[i]);
  printf ("original year array:  %s\n", year);

  /* converstion of strings to numbers */
  printf ("using atoi\n");
  int a = atoi("1234");
  int b = atoi("3.14");
  printf ("\t atoi(\"1234\") --> %d\t atoi(\"1234\") --> %d\n", a, b);

  printf ("using atof\n");
  double c = atof("01234");
  double d = atof("03.14");
  printf ("\t atof(\"1234\") --> %lf\t atof(\"1234\") --> %lf\n", c, d);

  /* robot commands */
  printf ("robot commands entered from the command line\n");
  printf ("\t this program:  %s\n", argv[0]);

  
  for (i = 1; i < argc; i++)
    {
      printf ("\t full robot command: %s\n", argv[i]);

      /* process 1-character robot commands */
      if (isalpha(argv[i][0]) && isdigit(argv[i][1]))
        {
          char command1 = argv[i][0];
          char * numstr1 = malloc (sizeof(char)*strlen(argv[i]));
          strcpy(numstr1, argv[i]+1);
          int value1 = atoi(numstr1);
          printf ("\t\t command letter: %c\n", command1);
          printf ("\t\t integer value: %d\n", value1);
        }
    }
  return 0;
}
