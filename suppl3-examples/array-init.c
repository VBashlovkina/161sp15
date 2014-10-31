#include <stdio.h>

int a[26] = {7};  // first element is 7, rest are 0
int b[26];        // global array initialized to 0
int x;            // global variable initialized to 0

/* program to illustrate initialization */
int main ()
{

  int c[26] = {7};  // first element is 7, rest are 0
  int d[26];        // local array not initialized
  int y;            // local variable not initialized

  printf ("uninitialized int variables\n");
  printf ("x = %d, \t y = %d\n", x, y);
  printf ("initialized array values\n");
  int i;

  printf ("index:   ");
  for (i = 0; i < 26; i++)
    printf ("%3d", i);
  printf ("\n");

  printf ("array a: ");
  for (i = 0; i < 26; i++)
    printf ("%3d", a[i]);
  printf ("\n");

  printf ("array b: ");
  for (i = 0; i < 26; i++)
    printf ("%3d", b[i]);
  printf ("\n");

  printf ("array c: ");
  for (i = 0; i < 26; i++)
    printf ("%3d", c[i]);
  printf ("\n");

  printf ("array d: ");
  for (i = 0; i < 26; i++)
    printf ("%3d", d[i]);
  printf ("\n");

  return 0;
}
