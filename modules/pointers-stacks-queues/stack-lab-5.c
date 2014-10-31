/* Stacks with Arrays Lab
   Version 5:  Stack uses a linked-list implementation
               copies of strings made during push, top, get_nth operations
*/

#include <stdlib.h>

typedef struct node * stringStack;
typedef struct node {
  char * stackData;
  stringStack next;
} stringStackNode;      /* type for a stack of strings */

/* index of standard stack operations            changes from Version 1*/
void initializeStack (stringStack * stack);   /* only printf changed */
int size (stringStack stack);                 /* unchanged */
int empty (stringStack stack);                /* unchanged */
int full (stringStack stack);                 /* unchanged */
int push (stringStack *stack, char * item);   /* must allocate mem, copy string */
/* post-condition:  item string is added to stack
                    length of string is returned 
*/
char * pop (stringStack *stack);              /* unchanged */
char * top (stringStack stack);               /* must allocate mem, copy string */
void print (stringStack stack);               /* unchanged */
char * get_nth (stringStack stack, int nth);  /* must allocate mem, copy string */
/* assume nth indexing starts at 1 */

/* ---------------------------------------------------------------------- */
/* Implementation of stack operations */

void initializeStack (stringStack * stack) {
  printf ("initialization of stack --- implementation 5\n");
  printf ("    linked list with strings copied before being put on stack\n");
  *stack = NULL;
}

int size (stringStack stack) {
  stringStack ptr = stack;
  int count = 0;
  while (ptr) {
    count++;
    ptr = ptr->next;\
  }
  return count;
}

int empty (stringStack stack){
  /* determine if there are any items in a stackArray */
  return stack == NULL;
}

int full (stringStack stack) {
  /* determine if there are more positions in a stackArray */
  return 1;
}

int push (stringStack *stack, char * item) {
/* post-condition:  item string is added to stack
                    length of string is returned 
*/

  /* add item to stack */
  stringStack newNode = malloc (sizeof(stringStackNode));
  newNode->stackData = malloc (sizeof(char)*(1+strlen(item)));
  strcpy (newNode->stackData, item);
  newNode->next = *stack;
  *stack = newNode;
  return strlen(item);
}

char * pop (stringStack *stack) {
  /* return -1 if stack empty */
  if (empty (*stack)) {
    printf ("attempt to pop item from an empty stack\n");
    return (char *) -1;
  }
  /* remove item from stack */
  stringStack firstItem = *stack;
  char *item = (*stack)->stackData;
  *stack = (*stack)->next;
  free (firstItem);
  return item;
}
  
char * top (stringStack stack){
  /* return -1 if stack empty */
  if (full (stack)) {
    printf ("attempt to access item on an empty stack\n");
    return (char *) -1;
  }
  /* retrieve item from stack */
  return stack->stackData;
}

void print (stringStack stack) {
  stringStack ptr = stack;
  printf ("contents of stack from top to bottom:\n");
  while (ptr)
    {
      printf ("    %s\n", stack->stackData);
      ptr = ptr->next;
    }
  printf ("end of stack\n");
}

char * get_nth (stringStack stack, int nth) {
  /* assume nth indexing starts at 1
     translate to 0-indexed arrays, counting from topPosition 
     return null if invalid index specified */
  if (nth < 1) {
    printf ("position %d is not a valid location in this stack\n", nth);
    return "error";
  }
  stringStack ptr = stack;
  while ((nth>=2) && (ptr != NULL))
    {
      ptr = ptr->next;
      nth--;
    }
  if (ptr != NULL)
    return ptr->stackData;
  else
    {
    printf ("position %d is not a valid location in this stack\n", nth);
    return "error";
    }
}

