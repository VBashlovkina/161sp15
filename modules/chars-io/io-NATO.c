/*********************
 * io-NATO.c
 *
 * Program to take a word as input and output the word in NATO's phonetic
 *   alphabet.
 * The NATO phonetic alphabet is the most common spelling alphabet; a 
 *   spelling alphabet assigns code words to letters and numbers of the 
 *   English alphabet so that critical combinations can be clearly understood
 *   by people who send/receive voice message by radio, to avoid endangering
 *   people or navigation due to transmission static.
 * NATO phonetic alphabet source: http://www.dynamoo.com/technical/phonetic.htm
 *
 * Author: April O'Neill
 * 
 * Date: 25 July 2011
 **********************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>


/* Function to return the NATO phonetic alphabet equivalent letter */
char *
wordReturn (char letter)
{
  switch (tolower (letter))
    /* If letter is already lowercase, no harm. If not, tolower 
       changes letter to lowercase. */
    {
    case 'a':
      return "alpha";
    case 'b':
      return "bravo";
    case 'c':
      return "charlie";
    case 'd':
      return "delta";
    case 'e':
      return "echo";
    case 'f':
      return "foxtrot";
    case 'g':
      return "golf";
    case 'h':
      return "hotel";
    case 'i':
      return "india";
    case 'j':
      return "juliet";
    case 'k':
      return "kilo";
    case 'l':
      return "lima";
    case 'm':
      return "mike";
    case 'n':
      return "november";
    case 'o':
      return "oscar";
    case 'p':
      return "papa";
    case 'q':
      return "quebec";
    case 'r':
      return "romeo";
    case 's':
      return "sierra";
    case 't':
      return "tango";
    case 'u':
      return "uniform";
    case 'v':
      return "victor";
    case 'w':
      return "whiskey";
    case 'x':
      return "xray";
    case 'y':
      return "yankee";
    case 'z':
      return "zulu";
    case '1':
      return "one";
    case '2':
      return "two";
    case '3':
      return "three";
    case '4':
      return "four";
    case '5':
      return "five";
    case '6':
      return "six";
    case '7':
      return "seven";
    case '8':
      return "eight";
    case '9':
      return "niner";
    case '0':
      return "zero";
    default:
      return "*unknown*";
    }
}

int
main()
{
  int i, length;
  char inString[50];

  printf("Enter a word: \n");
  scanf("%s", &inString);
  length = strlen(inString);
  for (i = 0; i < length; i++)
    {
      printf ("%s ", wordReturn (inString[i]));
    }

  printf("\n");

  return 0;
}
