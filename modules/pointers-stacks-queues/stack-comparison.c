#include <stdio.h>
#include <string.h>
#include "stack-lab-5.c"

int main () 
{
  stringStack myStack;
  char item1 [4] = "abc";
  char item2 [4] = "xyz";
  char * str;

  initializeStack (&myStack);
  push (&myStack, item1);
  push (&myStack, item2);
  
  strcpy (item1, "new");

  str = pop (&myStack);
  printf ("popped item:  %s\n", str);

  str = pop (&myStack);
  printf ("popped item:  %s\n", str);

  printf ("item1:  %s\n", item1);
  printf ("item2:  %s\n", item2);

  return 0;
}
