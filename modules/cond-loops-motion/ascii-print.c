/****
 * Program to generate ASCII table.
 ***/

#include <stdio.h>

int
main()
{
  int c; /* counter that will go through all the ASCII values */ 

  /* print table headings */
  printf("\n\t\tThe ASCII Table\n\n");
  printf("ASCII value in decimal:\t");
  printf("Character:\n");

  /* go through all the ASCII values and print it along with their correspondings */
  for( c=32; c<=126; c++)
    {
      /* Print the integer value of the ASCII value in decimal */
      printf("%d\t\t", c);
      /* Print the character value to which the integer corresponds */
      printf("%c\n", c);
    }

  return 0;
}
