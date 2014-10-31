/* A program shell to maintain a linked list of names */
/* author:  Henry M. Walker */ 

/* program based on a node definition and list interface definition */
#include "node.h"
#include "list-proc.h"

/* library for standard I/O */
#include <stdio.h>

int main (void) {
  /* program to coordinate the menu options and calls the requested function */

  struct node * first = NULL;   /* pointer to the first list item */

  printf ("Program to Maintain a List of Names\n");
 
  while (1) {
    char option;         /* user response to menu selection */
    
    /* print menu options */
    printf ("Options available\n");
    printf ("I - Insert a name into the list\n");
    printf ("D - Delete a name from the list\n");
    printf ("C - Count the number of items on the list\n");
    printf ("F - Move an item to the front of the list\n");
    printf ("L - Print the last item on the list\n");
    printf ("P - Print the names on the list\n");
    printf ("R - Print the names in reverse order\n");
    printf ("Q - Quit\n");

    /* determine user selection */
    printf ("Enter desired option: ");
    scanf (" %c", &option);
    
    switch (option)
      { case 'I':
        case 'i': 
          addName(&first);
          break;
        case 'D':
        case 'd': 
          deleteName(&first);
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
        
