#include <stdio.h>

int main ()
{
  char a[16] = "CSC 161 ";
  char b[16] = "Computer science";
  char c[16] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
               's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

  printf ("&a = %u, a = %s\n", &a, a);
  printf ("&b = %u, b = %s\n", &b, b);
  printf ("&c = %u, c = %s\n", &c, c);

  return 0;
}
