/* interface for a list abstract data type 
   based on a list node type */

#include "node.h"

/* function prototypes, listed in alphabetical order */

void addName(struct node ** firstPtr);
/* pre-condition:  firstPtr points to the pointer designating the head of a list
  post-condition:  a name is read and
                   inserted into the list at a designated place
*/

void countList (struct node * first);
/* pre-condition:  first designates the first node of a list 
  post-condition:  the number of items on the lsit is counted and printed
                   the list itself is unchanged
*/

void deleteName(struct node ** firstPtr);
/* pre-condition:  firstPtr points to the pointer designating the head of a list
  post-condition:  a name is read and
                   that name is deleted from the list
*/

void print(struct node * first);
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
                   Printing includes initial yitle
*/

void putFirst (struct node ** firstPtr);
/* pre-condition:  first designates the first node of a list 
  post-condition:  a name is read, located on the list,
                   and placed at the beginning of the list
*/

