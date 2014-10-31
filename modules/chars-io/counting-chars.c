/****************
 * counting-chars.c
 *
 * Program that counts the number and types of characters entered.
 *
 ****************/


#include <ctype.h>
#include <stdio.h>

int
main()
{
  char ch;

  /* Variables to count the various types of characters */
  int i = 1, unknown = 0, alpha = 0, digit = 0, punct = 0,
    blank = 0, capital = 0, lower = 0;

  printf ("Enter a sentence or phrase: ");

  ch = getchar();

  /* Loop that counts characters until a newline character is found. */
  while (!(ch == '\n'))
    {
      /* If the character is a letter, increment the number of letters*/
      if (isalpha(ch))
        {
          alpha++;
          /* If the letter is capitalized, increment the number of capitals.*/
          if (isupper(ch))
            capital++;
          /* Else, the letter is lowercase, so increment the number of
             lowercase letters */
          else
            lower++;
        }

      /* If the character is a number, increment the number of digits */
      else if (isdigit(ch))
          digit++;

      /* If the character is a punctuation mark, increment the number of 
         punctuation marks. */
      else if (ispunct(ch))
          punct++;

      /* If the character is a non-newline blank space character, increment
         the number of blank space characters. */
      else if (isspace(ch))
          blank++;

      /* Else, the type of character is unknown, so increment the number of
         unknown characters. */
      else
          unknown++;
      ch = getchar();

      /* Increment the total number of characters, with each call to getchar*/
      i++;
    }

  /* Print the number of each type of character, as well as the total number
     of characters. */
  printf ("Compared %d characters.\n", i);
  printf ("\tThere were %d letters, %d uppercase and %d lowercase.\n", 
          alpha, capital, lower);
  printf ("\tThere were %d numbers.\n", digit);
  printf ("\tThere were %d punctuation marks.\n", punct);
  printf ("\tThere were %d blank spaces.\n", blank);
  printf ("\tThere were %d unknown characters.\n", unknown);

  return 0;
} /* main */
