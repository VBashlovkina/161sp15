#include <stdio.h>

int main ()
{
  printf ("enter three characters\n");
  char a, b, c;
  scanf ("%c", &a);
  scanf ("%c%c", &b, &c);

  printf ("the three characters read are '%c', '%c', '%c'\n", a, b, c);

  return 0;
}
