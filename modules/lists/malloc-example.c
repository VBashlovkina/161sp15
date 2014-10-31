#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () 
{

  /* use of a character array for a string */
  /*                0123456789012345  */
  char str1 [17] = "computer science";
  int i;

  /* access character array as a string */
  printf ("str1 is %s\n", str1);
  /* access individual characters in the character array */
  printf ("str1 backward is ");
  for (i = strlen(str1)-1; i >= 0; i--)
    printf ("%c", str1[i]);
  printf ("\n");

  /* using a pointer to reference an existing character array */
  char * str2 = str1;
  printf ("str2 is %s\n", str2);

  printf ("str2 backward is ");
  for (i = strlen(str2)-1; i >= 0; i--)
    printf ("%c", str2[i]);
  printf ("\n");

  /* using a pointer to reference a new string */
  char * str3;
  /* allocate space for 27 characters */
  str3 = malloc (27 * sizeof(char));

  /* initialize to lower case alphabet */
  char ch;
  for (ch = 'a', i = 0; ch <= 'z'; ch++, i++)
    str3[i] = ch;
  str3[26] = 0;

  printf ("str3 is %s\n", str3);

  printf ("str3 backward is ");
  for (i = strlen(str3)-1; i >= 0; i--)
    printf ("%c", str3[i]);
  printf ("\n");



  return 0;
}
