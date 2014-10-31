/* Program to read an m by n word grid and count adjacent letters
 */

#include <stdio.h>
#include <ctype.h>

int isFound (int i, int j, int m, int n, char wordGrid[m][n])
{
  return (i >= 0) && (i < m) 
    && (j >= 0) && (j < n)
       && isalpha (wordGrid[i][j]);
}

int main ()
{
  int m, n;
  printf ("program to count adjacent letters in a word grid\n");
  printf ("enter number of rows and number of columns for grid");
  scanf ("%d %d", &m, &n);

  char wordGrid [m][n];
  int countGrid [m][n];

  int i, j;
  char ch;
  
  /* read grid */
  for (i = 0; i < m; i++)
    {
      /* discard remainder of previous line */
      while (getchar() != '\n');

      /* read line of charactgers */
       for (j = 0; j < n; j++)
        wordGrid [i][j] = getchar ();
    }


  /* echo grid for checking */
  printf ("\nThe grid read is\n");
  for (i = 0; i < m; i++)
    {
       for (j = 0; j < n; j++)
         printf ("%c", wordGrid[i][j]);
       printf ("\n");
    }

  /* count adjacent letters */
  for (i = 0; i < m; i++)
    {
       for (j = 0; j < n; j++)
         {
           countGrid[i][j] = 0;
           int r, s;
           for (r = -1; r <= 1; r++)
             for (s = -1; s <= 1; s++)
               countGrid[i][j] += isFound (i+r, j+s, m, n, wordGrid) && ((r!=0)||(s!=0));
         }
    }

  /* print counts */
  printf ("\nThe grid of counts is\n");
  for (i = 0; i < m; i++)
    {
       for (j = 0; j < n; j++)
         printf ("%1d", countGrid[i][j]);
       printf ("\n");
    }



  return 0;
}
