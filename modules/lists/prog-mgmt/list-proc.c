/* implementation details for a list abstract data type,
   based on a general interface */
/* author:  Henry M. Walker  */

#include "list-proc.h"

/* library for standard I/O */
#include <stdio.h>

/* C library for memory allocation */
#include <stdlib.h>

void addName(struct node ** firstPtr) {
/* pre-condition:  firstPtr points to the pointer designating the head of a list
  post-condition:  a name is read and
                   inserted into the list at a designated place
*/

  char oldName [strMax];
  struct node * newNode = (struct node *)malloc(sizeof(struct node));
  struct node * listPtr;
  struct node * prevPtr;

   printf ("Enter name to be inserted into list: ");
   scanf (" %s", newNode->data);

   if (*firstPtr == NULL) {
     /* insert name's node at start of list */
     newNode->next = *firstPtr;
     *firstPtr = newNode;
   }
  
   else {
     printf ("Enter old name which new name should preceed, \n");
     printf ("or enter ? if new name should be placed last\n");
     scanf (" %s", oldName);

     if (strcmp (oldName, (*firstPtr)->data) == 0) {
       /* insert name's node at start of list */
       newNode->next = *firstPtr;
       *firstPtr = newNode;
     }
     else {
       /* insert name's node after start of the list */
       
       /* start at beginning of list */
       listPtr = (*firstPtr)->next;  /* the current node to search */
       prevPtr = *firstPtr;          /* the node behind listPtr */
       
       while (listPtr && (strcmp (oldName, listPtr->data) != 0)) {
         prevPtr = listPtr;
         listPtr = prevPtr->next;
       }

       newNode->next = prevPtr->next;
       prevPtr->next = newNode;
     }
   }
   printf ("%s inserted into the list\n\n", newNode->data);
}

void countList (struct node * first) {
/* pre-condition:  first designates the first node of a list 
  post-condition:  the number of items on the lsit is counted and printed
                   the list itself is unchanged
*/
  int count = 0;
  struct node * ptr = first;
  while (ptr != NULL)
    {
      count++;
      ptr = ptr->next;
    }
  printf ("The list contains %d nodes\n\n", count);
}

void deleteName(struct node ** firstPtr) {
/* pre-condition:  firstPtr points to the pointer designating the head of a list
  post-condition:  a name is read and
                   that name is deleted from the list
*/
  char name [strMax];
  struct node * listPtr;
  struct node * prevPtr;

  if (*firstPtr) {
    printf ("Enter name to be deleted: ");
    scanf ("%s", name);

    if (strcmp (name, (*firstPtr)->data) == 0) {
      /* remove first item on list */
      listPtr = *firstPtr;
      *firstPtr = (*firstPtr)->next;
      free(listPtr);
      printf ("%s removed as first item on list\n\n", name);
    }
    else {
      /* item to remove is not at beginning of list */
      /* start at beginning of list */
      listPtr = (*firstPtr)->next;  /* the current node to search */
      prevPtr = *firstPtr;          /* the node behind listPtr */

      while (listPtr && (strcmp (name, listPtr->data) != 0)) {
        prevPtr = listPtr;
        listPtr = prevPtr->next;
      }
             
      if (listPtr) {
        /* remove item from list */
        prevPtr->next = listPtr->next;
        free (listPtr);
        printf ("%s deleted from list\n\n", name);
      }
      else {
        printf ("%s not found on list\n\n", name);
      }
    } /* end processing of name */
  }
  else {
    printf ("List is empty - no deletions are possible\n");
  } 
}

void print(struct node * first){
/* pre-condition:  first designates the first node of a list 
  post-condition:  The items on the list are printed from first to last
                   the list itself is unchanged
*/    
  struct node * listElt = first;
  printf ("The names on the list are:\n\n");

  while (listElt) {
    printf ("\t%s\n", listElt->data);
    listElt = listElt->next;
  }

  printf ("\nEnd of List\n\n");
}

void printLast (struct node * first) {
/* pre-condition:  first designates the first node of a list 
  post-condition:  the last item on the list is printed; 
                   the list itself is unchanged
*/
  if (first == NULL)
    {
      printf("The list is empty --- no last element\n\n");
      return;
    }
  struct node * ptr = first;
  while (ptr->next != NULL)
    {
      ptr = ptr->next;
    }
  printf ("The last name on the list is %s\n\n", ptr->data);
}

/* the following function is used as a helper to printReverse,
   so this function is declared before printReverse
   The function is not included in the prototypes at the start,
   because it is used only as a private helper */
void printReverseHelper (struct node * first) {
/* pre-condition:  first designates the first node of a list 
  post-condition:  The items on the list are printed from last to first
                   the list itself is unchanged
*/
  if (first != NULL)
    {
      printReverseHelper (first->next);
      printf("\t%s\n", first->data);
    }
}

void printReverse (struct node * first) {
/* pre-condition:  first designates the first node of a list 
  post-condition:  The items on the list are printed from last to first
                   the list itself is unchanged
                   Printing includes initial yitle
*/
  printf ("The list in reverse order is:\n");
  printReverseHelper (first);
  printf("\n\n");
}

void putFirst (struct node ** firstPtr) {
/* pre-condition:  first designates the first node of a list 
  post-condition:  a name is read, located on the list,
                   and placed at the beginning of the list
*/
  printf ("Function to move an item to the front of the list\n");
  if (*firstPtr == NULL)
    {
      printf ("list is empty, so no items available to move\n\n");
      return;
    }
  printf ("Enter name of item:  ");
  char str[strMax];
  scanf ("%s", str);

  if (strcmp ((*firstPtr)->data, str) == 0)
    {
      printf ("item already first\n\n");
      return;
    }

  struct node * ptr = (*firstPtr)->next;
  struct node * prevPtr = *firstPtr;
  while ((ptr != NULL) && (strcmp (ptr->data, str) != 0))
    {/* move along list to find item */
      prevPtr = ptr;
      ptr = ptr->next;
    }

  if (ptr == NULL)
    printf ("item not found\n\n");
  else
    { /* move item's node to front */
      prevPtr->next = ptr->next;
      ptr->next = (*firstPtr);
      *firstPtr = ptr;
      printf ("item moved to front\n\n");
    }
}
