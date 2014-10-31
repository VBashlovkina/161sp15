/* Stacks with Arrays Lab
   Version 1 (include stack-lab-1.c:  Stack contains pointers to strings
   Version 2 (include stack-lab-2.c:  Stack contains arrays of real strings
   Version 3 (include stack-lab-3.c:  Stack contains pointers to strings
                                         allocating space for strings as needed
   Version 4 (include stack-lab-2.c:  Stack contains arrays of real strings
                                  copying strings in, but returning a reference
*/
#include <stdio.h>
#include <string.h>
#include "stack-lab-4.c"

int main () {
  /* identify stack variables */
  stringStack billStack;
  stringStack magStack;
  stringStack notesStack;
  char * str;
  printf ("Program to test stack operations\n");

  /* initialize stacks */
  initializeStack (&billStack);
  initializeStack (&magStack);
  initializeStack (&notesStack);

  /* experiment with stacks */
  printf ("\npushing 3 items on billStack\n");
  printf ("   string of length %2d added to billStack\n", 
          push (&billStack, "mortgage"));
  printf ("   string of length %2d added to billStack\n", 
          push (&billStack, "doctor's bill"));
  printf ("   string of length %2d added to billStack\n", 
          push (&billStack, "credit card"));

  /* check status of stacks */
  if (empty(billStack))
    printf ("billStack is empty\n");
  else
    printf ("billStack is NOT empty\n");
  if (empty(magStack))
    printf ("magStack is empty\n");
  else
    printf ("magStack is NOT empty\n");
  if (empty(notesStack))
    printf ("notesStack is empty\n");
  else
    printf ("notesStack is NOT empty\n");

  printf ("size of billStack:  %d\n", size(billStack));
  printf ("size of magStack:   %d\n", size(magStack));
  printf ("size of notesStack: %d\n", size(notesStack));
  printf ("\nbill stack:  ");
  print (billStack);
  printf ("mag stack:  ");
  print (magStack);
  printf ("notes stack:  ");
  print (notesStack);

  /* more experimentation with stacks */
  printf ("\npushing 2 items on magStack\n");
  printf ("   string of length %2d added to magStack\n", 
          push (&magStack,"Communications of the ACM - March 2009" ));
  printf ("   string of length %2d added to magStack\n", 
          push (&magStack, "CS Education Bulletin - Spring 2009"));

  /* checking nth positions in stacks */
  printf ("\nfirst item from top in billStack:  %s\n", get_nth (billStack, 1));
  printf ("second item from top in magStack:  %s\n", get_nth (magStack, 2));
  printf ("third item from top in notesStack:  %s\n", get_nth (magStack, 3));
  printf ("third item from top in billStack:  %s\n\n", get_nth (billStack, 3));

  /* checking pop operation on several stacks */
  str = pop (&billStack); /* pop 1 from billStack */
  if (str == (char *) -1)
    printf ("pop from bill stack yielded code for invalid string\n");
  else
    printf ("item popped from bill stack:  %s\n", str); 
  str = pop (&billStack); /* pop 2 from billStack */
  if (str == (char *) -1)
    printf ("pop from bill stack yielded code for invalid string\n");
  else
    printf ("item popped from bill stack:  %s\n", str); 
  str = pop (&billStack); /* pop 3 from billStack */
  if (str == (char *) -1)
    printf ("pop from bill stack yielded code for invalid string\n");
  else
    printf ("item popped from bill stack:  %s\n", str); 
  str = pop (&billStack); /* pop 4 from billStack */
  if (str == (char *) -1)
    printf ("pop from bill stack yielded code for invalid string\n");
  else
    printf ("item popped from bill stack:  %s\n", str); 

  str = pop (&magStack); /* pop 1 from magStack */
  if (str == (char *) -1)
    printf ("pop from mab stack yielded code for invalid string\n");
  else
    printf ("item popped from mag stack:  %s\n", str); 

  str = pop (&notesStack); /* pop 1 from notesStack */
  if (str == (char *) -1)
    printf ("pop from notes stack yielded code for invalid string\n");
  else
    printf ("item popped from notes stack:  %s\n", str); 
  str = pop (&notesStack); /* pop 2 from notesStack */
  if (str == (char *) -1)
    printf ("pop from notes stack yielded code for invalid string\n");
  else
    printf ("item popped from notes stack:  %s\n", str); 

  /* check status of stacks */
  if (empty(billStack))
    printf ("\nbillStack is empty\n");
  else
    printf ("\nbillStack is NOT empty\n");
  if (empty(magStack))
    printf ("magStack is empty\n");
  else
    printf ("magStack is NOT empty\n");
  if (empty(notesStack))
    printf ("notesStack is empty\n");
  else
    printf ("notesStack is NOT empty\n");

  printf ("\nsize of billStack:  %d\n", size(billStack));
  printf ("size of magStack:   %d\n", size(magStack));
  printf ("size of notesStack: %d\n", size(notesStack));
}
