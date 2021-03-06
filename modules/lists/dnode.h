/*** 
 * dnode.h Doubly Linked Lists specification for the module 5 project
 *
 * Author: David Cowden
 * First version:  July-August 2011
 * Major revision: 4 August 2011
 * Revised with simplifications:  November 13-14, 2011  by Henry M. Walker
 * 
 */
#include <stdlib.h>

/* 
 * Define the structure (frequency and duration) for a note.
 */
typedef struct Note {
  int freq;
  double time;
} Note;

/* - Doubly linked list node with fields for 
      - note information
      - id to simplify reference to a node
*/
struct dnode {
  Note note_data;
  int id;
  struct dnode * next;
  struct dnode * prev;
};

typedef struct dnode * dnode_t;

/*********************************************************
 * Procedure prototypes for dnodes   
 *********************************************************/

/* allocates space for a new dnode
 * sets next and prev fields to NULL
 * return a pointer to new node
 */
dnode_t createNode (void);

/* set the contents of node's note_data field to data */
/* pre-condition:  node is not NULL */
void setNodeNote (dnode_t node, Note data);

/* set the contents of node's id field to id */
/* pre-condition:  node is not NULL */
void setNodeID (dnode_t node, int id);

/* insert node into the list after node after. */
/* pre-condition:  node and after are not NULL */
void insertNodeAfter (dnode_t node, dnode_t after);

/* insert node into the list before node before. */
/* pre-condition:  node and before are not NULL */
void insertNodeBefore (dnode_t node, dnode_t before);

/* remove node from list but do not free node. 
   removed node is returned */
dnode_t removeNode (dnode_t node);

/* delete node (free its memory) */
void deleteNode (dnode_t node);
/* ONLY DELETE nodes that have already been REMOVED from your list (with 
 * removeNode) */
/* WARNING, if node is your only reference to your list your entire list 
 * will be lost */

/* search the entire list for a node with an id that matches id */
/* post-condition:  if id matches a node's id, return pointer to node
                    otherwise, return NULL
*/
dnode_t findNodeByID (dnode_t node, int id);

/* return the next node */
/* post-condition:  if node is not NULL, return pointer to next node
                    otherwise, return NULL
*/
dnode_t nextNode (dnode_t node);

/* return the previous node */
/* post-condition:  if node is not NULL, return pointer to previous node
                    otherwise, return NULL
*/
dnode_t prevNode (dnode_t node);

/* return the node's id */
/* post-condition:  if node is not NULL, return pointer to node's id
                    otherwise, return 0
*/
int getNodeID (dnode_t node);

/* return the node's node_data */
/* post-condition:  if node is not NULL, return the node's id
   otherwise, return 0 */
Note getNodeNote (dnode_t node);

/************************************************************
 * Implementations of the dnode functions
 * The project consists of adding correct details to the following
 * functions
 ************************************************************/
/* allocates space for a new dnode
 * sets next and prev fields to NULL
 * return a pointer to new node
 */
dnode_t createNode (void)
{
  /* add details here */
  /* the following line is included so the code will compile 
     (a return value is needed for compilation */
  return NULL; /* replace this line with correct code */
}

/* set the contents of node's note_data field to data */
/* pre-condition:  node is not NULL */
void setNodeNote (dnode_t node, Note data)
{
  /* add details here */
}

/* set the contents of node's id field to id */
/* pre-condition:  node is not NULL */
void setNodeID (dnode_t node, int id)
{
  /* add details here */
}

/* insert node into the list after node after. */
/* pre-condition:  node and after are not NULL */
void insertNodeAfter (dnode_t node, dnode_t after)
{
  /* add details here */
}

/* insert node into the list before node before. */
/* pre-condition:  node and before are not NULL */
void insertNodeBefore (dnode_t node, dnode_t before)
{
  /* add details here */
}

/* remove node from list but do not free node. 
   removed node is returned */
dnode_t removeNode (dnode_t node)
{
  /* add details here */
  /* the following line is included so the code will compile 
     (a return value is needed for compilation */
  return NULL;  /* replace this line with correct code */
}

/* delete node (free its memory) */
void deleteNode (dnode_t node)
{
  /* add details here */
}
/* ONLY DELETE nodes that have already been REMOVED from your list (with 
 * removeNode) */
/* WARNING, if node is your only reference to your list your entire list 
 * will be lost */

/* search the entire list for a node with an id that matches id */
/* post-condition:  if id matches a node's id, return pointer to node
                    otherwise, return NULL
*/
dnode_t findNodeByID (dnode_t node, int id)
{
  /* add details here */
  /* the following line is included so the code will compile 
     (a return value is needed for compilation */
  return NULL;  /* replace this line with correct code */
}

/* return the next node */
/* post-condition:  if node is not NULL, return pointer to next node
                    otherwise, return NULL
*/
dnode_t nextNode (dnode_t node)
{
  /* add details here */
  /* the following line is included so the code will compile 
     (a return value is needed for compilation */
  return NULL;  /* replace this line with correct code */
}

/* return the previous node */
/* post-condition:  if node is not NULL, return pointer to previous node
                    otherwise, return NULL
*/
dnode_t prevNode (dnode_t node)
{
  /* add details here */
  /* the following line is included so the code will compile 
     (a return value is needed for compilation */
  return NULL;  /* replace this line with correct code */
}

/* return the node's id */
/* post-condition:  if node is not NULL, return the node's id
                    otherwise, return 0
*/
int getNodeID (dnode_t node)
{
  /* add details here */
  /* the following line is included so the code will compile 
     (a return value is needed for compilation */
  /* post-condition:  if node is not NULL, return the node's id
     otherwise, return 0 */
  return 0;  /* replace this line with correct code */
}

/* return the node's note_data */
/* pre-condition:  node is not NULL */
Note getNodeNote (dnode_t node)
{
  /* add details here */
  /* the following code constructs a note and returns it,
   * so program will compile */
  /* the following 4 lines are included so the code will compile 
     (a return Note is needed for compilation */
  Note * data = malloc(sizeof(Note));  /* replace these */
  data->freq=880;                      /* lines with */
  data->time=0.75;                     /* code that */
  return *data;                        /* functions properly */
}

