/* A program shell  to maintain a linked list of names */

/* library for standard I/O */
#include <stdio.h>

/* library for memory allocation */
#include <stdlib.h>

/* Maximum length of names */
#define strMax 20

struct node
{ char data [strMax];
  struct node * next;
};

/* function prototypes, listed in alphabetical order */

void addName(struct node ** firstPtr);
/* pre-condition:  firstPtr points to the pointer
                   designating the head of a list
  post-condition:  a name is read and
                   inserted into the list at a designated place
*/

void print(struct node * first);
/* pre-condition:  first designates the first node of a list 
  post-condition:  The items on the list are printed from first to last
                   the list itself is unchanged
*/

void addNamesFromFile (struct node ** first);
/* pre-condition:  first designates the first node of a list 
  post-condition:  the program asks the user for a file name
                   names from individual lines of the file are inserted
                   at the beginning of the original list
*/

void removeDuplicates (struct node * first);
/* pre-condition:  first designates the first node of a list 
  post-condition:  each name on the list appears only once (no duplicate names)
                   when duplicates occur on the original list,
                      only the first occurence remains after processing
*/

void duplicate (struct node * firstPtr);
/* pre-condition:  first designates the first node of a list 
  post-condition:  each node is duplicated, with the new node inserted
                   after the original node
*/

int main (void) {
  /* program to coordinate the menu options and calls the requested function */

  struct node * first = NULL;   /* pointer to the first list item */
  char option[strMax];          /* user response to menu selection */

  printf ("Program to Maintain a List of Names\n");

  while (1) {
    /* print menu options */
    printf ("Options available\n");
    printf ("I - Insert a name (from the keyboard) into the list\n");
    printf ("P - Print the names on the list\n");
    printf ("F - Read a sequence of names from a file onto the list\n");
    printf ("R - Remove duplicate names (leaving only the first occurence)\n");
    printf ("D - Duplicate each node\n");
    printf ("Q - Quit\n");

    /* determine user selection */
    printf ("Enter desired option: ");
    scanf ("%s", option);
    
    switch (option[0])
      { case 'I':
        case 'i': 
          addName(&first);
          break;
        case 'P':
        case 'p': 
          print(first);
          break;
        case 'F':
        case 'f': 
          addNamesFromFile(&first);
          break;
        case 'R':
        case 'r': 
          removeDuplicates(first);
          break;
        case 'D': 
        case 'd': 
          duplicate(first);
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
   scanf ("%s", newNode->data);

   if (*firstPtr == NULL) {
     /* insert name's node at start of list */
     newNode->next = *firstPtr;
     *firstPtr = newNode;
   }
  
   else {
     printf ("Enter old name which new name should preceed, \n");
     printf ("or enter ? if new name should be placed last\n");
     scanf ("%s", oldName);

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

void print(struct node * first){
/* pre-condition:  first designates the first node of a list 
  post-condition:  The items on the list are printed from first to last
                   the list itself is unchanged
*/    
  struct node * listElt = first;
  printf ("The names on the list are:\n\n");

  while (listElt) {
    printf ("%s\n", listElt->data);
    listElt = listElt->next;
  }

  printf ("\nEnd of List\n\n");
}

void addNamesFromFile (struct node ** first){
/* pre-condition:  first designates the first node of a list 
  post-condition:  the program asks the user for a file name
                   names from individual lines of the file are inserted
                   at the beginning of the original list
*/
  char fileName [50];
  printf ("Function to insert names from a file to the end of the list\n");
  printf ("  Enter file name:  ");
  scanf ("%s",fileName);

  printf ("   Function to add names from file '%s' not implemented at present\n\n",
          fileName);
}

void removeDuplicates (struct node * first) {
/* pre-condition:  first designates the first node of a list 
  post-condition:  each name on the list appears only once (no duplicate names)
                   when duplicates occur on the original list,
                      only the first occurence remains after processing
*/
  printf ("   Function removeDuplicates is not implemented at present\n\n");
}

void duplicate (struct node * firstPtr)
/* pre-condition:  first designates the first node of a list 
  post-condition:  each node is duplicated, with the new node inserted
                   after the original node
*/
{
  printf ("   Function duplicate is not implemented at present\n\n");
}

