/* program to produce a histogram of letters from entered input 
   the program reads until a number sign (#) is entered
   non-letters are ignored in the count
   counts are case insensitive
*/

#include <stdio.h>
#include <ctype.h>
#

int main ()
{
  printf ("this program prints a histogram of letters\n");
  printf ("input continues until character # is entered\n");

  int count[26];
  int i, let;
  for (let = 0; let < 26; let++)
    count[let] = 0;

  int maxCount = 0;
  char ch;
  while ((ch = (tolower(getchar()))) != '#')
    {
      /*printf ("%c", ch);*/
      if (isalpha(ch))
        {
          count[ch-'a']++;
          if (maxCount < count[ch-'a'])
            maxCount = count[ch-'a'];
        }
    }

    printf ("Histogram follows:\n");
    for (i = maxCount - 1; i >= 1; i--)
      {
        for (let = 0; let < 26; let++)
          {
            if (count[let] >= i)
              printf (" *");
            else
              printf ("  ");
          }
        printf ("\n");
      }

    for (let = 'a'; let <= 'z'; let++)
      printf (" %c", let);
    printf ("\n");
  return 0;
}
