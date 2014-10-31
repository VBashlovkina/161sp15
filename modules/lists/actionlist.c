/* A program shell  to maintain a linked list of names */

/* library for Myro functions */
#include "MyroC.h"

/* library for standard I/O */
#include <stdio.h>

/* library for memory allocation */
#include <stdlib.h>

/* Maximum length of names */
#define strMax 20

/* actionData is a structure which represents a robot action.  The structure
   contains a pointer to the function that executes the action, and the name of
   the action referenced by the function pointer. */
struct actionData 
{
  void ( * fp)(void);
  const char * name;
};

/* node with which you construct a linked list */
struct node 
{ 
  struct actionData data;
  struct node * next;
  unsigned int UID; 
};

/* nodes contain a UID or Unique IDentifier. This allows future reference to
   an individual node in the list regardless of the data stored in data. */

unsigned int id = 1; /* Current UID to assign to a node when created. UIDs
                        will start at 1 */

/* function prototypes, listed in alphabetical order */

void addAction (struct node ** firstPtr);
/* pre-condition:  firstPtr points to the pointer
   designating the head of a list
   post-condition:  a name is read and
   inserted into the list at a designated place
*/

void countList (struct node * first);
/* pre-condition:  first designates the first node of a list 
   post-condition:  the number of items on the lsit is counted and printed
   the list itself is unchanged
*/

void deleteAction (struct node ** firstPtr);
/* pre-condition:  firstPtr points to the pointer designating the head of a list
   post-condition:  a name is read and
   that name is deleted from the list
*/

void print (struct node * first);
/* pre-condition:  first designates the first node of a list 
   post-condition:  The items on the list are printed from first to last
   the list itself is unchanged
*/

void printLast (struct node * first);
/* pre-condition:  first designates the first node of a list 
   post-condition:  the last item on the list is printed; 
   the list itself is unchanged
*/

void printReverse (struct node * first);
/* pre-condition:  first designates the first node of a list 
   post-condition:  The items on the list are printed from last to first
   the list itself is unchanged
*/

void putFirst (struct node ** firstPtr);
/* pre-condition:  first designates the first node of a list 
   post-condition:  a UID is read, located on the list,
   and placed at the beginning of the list
*/

struct actionData createAction (int option);
/*  createAction returns an actionData structure depending on the specified
    option.*/

void executeActions (struct node * first);
/*   execute all the actions contained in the action list    */

int main (void) {
  /* program to coordinate the menu options and calls the requested 
     function */ 

  struct node * first = NULL;   /* pointer to the first list item */
  char option[strMax];          /* user response to menu selection */

  printf ("Program to Maintain a List of Robot Actions\n");

  while (1) {
    /* print menu options */
    printf ("Options available\n");
    printf ("I - Insert an action into the list\n");
    printf ("D - Delete an action from the list\n");
    printf ("C - Count the number of items in the list\n");
    printf ("F - Move an item to the front of the list\n");
    printf ("L - Print the last item in the list\n");
    printf ("P - Print the actions in the list and the UIDs of the nodes\n");
    printf ("R - Print the actions and UIDs in reverse order\n");
    printf ("E - Execute all the action commands contained in the list\n");
    printf ("Q - Quit\n");

    /* determine user selection */
    printf ("Enter desired option: ");
    scanf ("%s", option);
    
    switch (option[0])
      { case 'I':
      case 'i': 
        addAction(&first);
        break;
      case 'D':
      case 'd': 
        deleteAction(&first);
        break;
      case 'C':
      case 'c': 
        countList(first);
        break;
      case 'F':
      case 'f': 
        putFirst(&first);
        break;
      case 'L':
      case 'l': 
        printLast(first);
        break;
      case 'P':
      case 'p': 
        print(first);
        break;
      case 'R':
      case 'r': 
        printReverse(first);
        break;
      case 'E':
      case 'e':
        executeActions(first);
        break;
      case 'Q':
      case 'q':
        printf ("Program terminated\n");
        return 0;
        break;
      default: printf ("Invalid Option - Try Again!\n");
        continue;
      }
  }
}
        
void addAction (struct node ** firstPtr) {
  /* pre-condition:  firstPtr points to the pointer designating the head of a 
     list 
     post-condition:  an action is read and
     inserted into the list at a designated place
  */

  int ret;
  unsigned int oldUID;
  struct node * newNode = (struct node *)malloc(sizeof(struct node));
  struct node * listPtr;
  struct node * prevPtr;

  printf ("Choose action to be inserted into list:\n");
  printf ("1: move robot forward\n");
  printf ("2: move robot backward\n");
  printf ("3: turn robot left\n");
  printf ("4: turn robot right\n");
  scanf ("%d", &ret);
  newNode->data = createAction( ret );
  newNode->UID = id++; /* id is incremented when it is used */
  printf("\n");

  if ( * firstPtr == NULL) {
    /* insert name's node at start of list */
    newNode->next = *firstPtr;
    *firstPtr = newNode;
  }
  
  else {
    printf ("Enter old action UID which new action should preceed, \n");
    printf ("or enter 0 if new action should be placed last\n");
    scanf ("%u", &oldUID);

    if (oldUID == (*firstPtr)->UID) {
      /* insert name's node at start of list */
      newNode->next = *firstPtr;
      *firstPtr = newNode;
    }
    else {
      /* insert name's node after start of the list */
       
      /* start at beginning of list */
      listPtr = (*firstPtr)->next;  /* the current node to search */
      prevPtr = *firstPtr;          /* the node behind listPtr */
       
      while (listPtr && oldUID != listPtr->UID) {
        prevPtr = listPtr;
        listPtr = prevPtr->next;
      }

      newNode->next = prevPtr->next;
      prevPtr->next = newNode;
    }
  }
  printf ("Action:    %s - inserted into the list\n", newNode->data.name);
  printf ("Node UID:  %u\n\n", newNode->UID);
}

void countList (struct node * first) {
  /* pre-condition:  first designates the first node of a list 
     post-condition:  the number of items on the lsit is counted and printed
     the list itself is unchanged
  */
  printf ("Function countList is not implemented at present\n\n");
}

void deleteAction (struct node ** firstPtr) {
  /* pre-condition:  firstPtr points to the pointer designating the head of a list
     post-condition:  a name is read and
     that name is deleted from the list
  */
  unsigned int ret;
  struct node * listPtr;
  struct node * prevPtr;

  if ( * firstPtr) {
    printf ("Enter UID of list node to be deleted: ");
    scanf ("%u", &ret);

    if (ret == ( * firstPtr) -> UID) {
      /* remove first item on list */
      listPtr = * firstPtr;
      * firstPtr = ( * firstPtr) -> next;
      free (listPtr);
      printf ("Node: %u - removed as first item on list\n\n", ret);
      printf ("Action: %s removed from sequence", listPtr->data.name);
    }
    else {
      /* item to remove is not at beginning of list */
      /* start at beginning of list */
      listPtr = ( * firstPtr) -> next;  /* the current node to search */
      prevPtr =  *firstPtr;          /* the node behind listPtr */

      while ( listPtr && ret != listPtr -> UID) {
        prevPtr = listPtr;
        listPtr = prevPtr -> next;
      }
             
      if (listPtr) {
        /* remove item from list */
        prevPtr -> next = listPtr -> next;
        printf ("Node:   %u deleted from list\n", ret);
        printf ("Action: %s removed from sequence", listPtr -> data.name);
        free (listPtr);
      }
      else {
        printf ("Node: %u not found on list\n\n", ret);
      }
    } /* end processing of UID in ret */
  }
  else {
    printf ("List is empty - no deletions are possible\n");
  } 
}

void print (struct node * first){
  /* pre-condition:  first designates the first node of a list 
     post-condition:  The items on the list are printed from first to last
     the list itself is unchanged
  */    
  struct node * listElt = first;
  printf ("The actions on the list are:\n\n");

  while (listElt) {
    printf ("UID:      %u\t\tAction:  %s\n", 
            listElt -> UID, 
            listElt -> data.name); 
    listElt = listElt -> next;
  }

  printf ("\nEnd of List\n\n");
  sleep(3);
}

void printLast (struct node * first) {
  /* pre-condition:  first designates the first node of a list 
     post-condition:  the last item on the list is printed; 
     the list itself is unchanged
  */
  printf ("Function printLast is not implemented at present\n\n");
}

void printReverse (struct node * first) {
  /* pre-condition:  first designates the first node of a list 
     post-condition:  The items on the list are printed from last to first
     the list itself is unchanged
  */
  printf ("Function printReverse is not implemented at present\n\n");
}

void putFirst (struct node ** firstPtr) {
  /* pre-condition:  first designates the first node of a list 
     post-condition:  an action is read, located on the list,
     and placed at the beginning of the list
  */
  printf ("Function putFirst is not implemented at present\n\n");
}

/* Movement wrapper functions.  These are all void functions returning
   nothing so they fit into the actionData structure */
void 
mforward (void)
{ rForward (1, 2); }

void
mbackward (void)
{ rBackward (1, 2); }

void
mleft (void)
{ rTurnLeft (1, 1); }

void
mright (void)
{ rTurnRight (1, 1); }

void
donothing (void) {};

/* string constants for actions */

const char * fwd = "forward";
const char * bwd = "backward";
const char * lft = "left";
const char * rgt = "right";
const char * not = "do nothing";

/* createAction returns an actionData structure which contains the 
   appropriate data based on the option specified.
   1 - mforward
   2 - mbackward
   3 - mleft
   4 - mright
   other - donothing
*/
struct actionData 
createAction (int option)
{
  struct actionData a;
  switch (option) {
  case 1: //move forward 
    return a.fp = mforward, a.name = fwd, a;
  case 2: //move backward
    return a.fp = mbackward, a.name = bwd, a;
  case 3: //turn left
    return a.fp = mleft, a.name = lft, a;
  case 4: //turn right
    return a.fp = mright, a.name = rgt, a;
  default://do nothing
    printf ("Warning: invalid option, adding a blank node..\n");
    return a.fp = donothing, a.name = not, a;
    break;

  }
}


/* executeActions takes a node and calls all the functions in the data
   members of all the connected nodes in order. */
void
executeActions (struct node * first)
{
  if( ! first)
    return (void) 
      printf("The action list is empty. No commands to execute.\n\n"); 
  

  printf ("Connecting to robot... ");
  rConnect ("/dev/rfcomm0");
  
  printf ("Executing action list..");
  while (first) {
    first -> data.fp();
    first = first -> next;
    printf ("\n..");
  }
  printf (" done!\n");

  printf ("Closing connection to robot....");
  rDisconnect();
  printf (" finished.\n\n");
}

