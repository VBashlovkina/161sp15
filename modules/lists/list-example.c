/* A simple program to maintain an ordered linked list of integers 
   version 1:  infinite loop for insertion and printing

   Author:  Henry M. Walker
   File:  /home/walker/c/lists/list-1.c
   Created:  September 30, 1996
   Last Revised:  February 28, 2005
*/

/* library for standard I/O */
#include <stdio.h>

/* library for memory allocation */
#include <stdlib.h>

struct node
{ int data;
  struct node * next;
};

void insert (struct node ** firstPtr);
/* procedure to place value into a new node and put new node into an
   ordered linked list, so resulting list remains ordered */

void print (struct node *first);
/* procedure to print elements on a linked list */

int main ()
{ struct node * first = NULL;
  printf ("Program to maintain linked list of integers\n");
  while (1)
    {insert(&first);
     print (first);
    }
  return 0;
}

void insert (struct node ** firstPtr)
/* procedure to place value into a new node and put new node into an
   ordered linked list, so resulting list remains ordered */
{  struct node *newNode = (struct node *)malloc(sizeof(struct node));
   struct node *temp;

   printf ("Enter value to be inserted into list: ");
   scanf ("%d", &(newNode->data));

   if ((*firstPtr == NULL) || (newNode->data <= (*firstPtr)->data))
     {  /* insert at front of list */
        newNode->next = *firstPtr;
        *firstPtr = newNode;
     }
   else 
     {  /* insert later in list */
        temp = *firstPtr;
        while ((temp->next != NULL) && (newNode->data > (temp->next)->data))
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
     }
}


void print (struct node *first)
/* procedure to print elements on a linked list 
   6 numbers are printed per line */
{ 
  struct node *ptr = first; /* temporary pointer to move through list */
  int number = 0;           /* count number of numbers printed on line */
  printf ("The current values on the linked list are:\n");
   while (ptr)
      { printf ("\t%d", ptr->data);
        number = (number+1) % 6;
        if (number == 0) /* test also could be !number, but number == 0 
                            seems clearer in context of counting */
          printf ("\n");
        ptr = ptr->next;
      }
   if (number) printf ("\n");
}
