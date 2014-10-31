/**
 * array-queue.c
 * Citation: Taken from Sam Rebelsky.
 *   Array based queues.
 */

// +---------+--------------------------------------------------------
// | Headers |
// +---------+

#include <stdlib.h>     // For malloc

#include "linear.h"     // Signatures of the methods we provide.


// +-------+----------------------------------------------------------
// | Types |
// +-------+

struct linear
  {
    char **contents;    // The contents of the queue
    int front;          // The front of the queue
    int back;           // The back of the queue
    int size;           // The size of the queue
    int capacity;       // The capacity of the queue
  };


// +---------+--------------------------------------------------------
// | Helpers |
// +---------+


// +----------------------------+-------------------------------------
// | Constructors & Destructors |
// +----------------------------+

struct linear *
construct (int minimum_capacity)
{
  // Allocate the enclosing structure
  struct linear *linear = (struct linear *) malloc (sizeof (struct linear));
  if (linear == NULL)
    return NULL;

  // Allocate the array of strings
  linear->contents = calloc (minimum_capacity, sizeof (char *));
  if (linear->contents == NULL)
    {
      free (linear);
      return NULL;
    }

  // Fill in the fields.  (Note that calloc zeroes memory, so we don't
  // have to set things to 0.)
  linear->capacity = minimum_capacity;
  linear->size = 0;
  linear->front = 0;
  linear->back = 0;

  // And we're done
  return linear;
} // construct

