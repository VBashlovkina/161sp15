#ifndef _NOTENODE_H
#define _NOTENODE_H

typedef struct noteNode * noteNode_t;

typedef struct noteNode {
  int arrInd;
  double duration;
  noteNode_t next;
} noteNode;

#endif
