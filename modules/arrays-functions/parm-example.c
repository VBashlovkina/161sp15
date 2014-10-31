#include <stdio.h>

void func (int *x) {
  printf ("old x = %d, addr %d, value pointed to %d\n", x, &x, *x);

  *x += 2;

  printf ("new x = %d, addr %d, value pointed to %d\n", x, &x, *x);

}

int main () 
{  int a;

  a = 7;

  printf ("old a = %d, address = %d\n", a, &a);

  func(&a);

  printf ("new a = %d\n", a);

}
