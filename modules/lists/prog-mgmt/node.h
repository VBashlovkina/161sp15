/* Definition of a List Node */

/* utilize an ifndef/define mechanism, so nodes will be defined exactly once */
#ifndef _NODE_H
#define _NODE_H

/* Maximum length of the names */
#define strMax 20

/* Define the node structure itself */
struct node
{ char data [strMax];
  struct node * next;
};

#endif
