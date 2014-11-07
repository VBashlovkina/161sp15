/* library for Myro functions */
#include "MyroC.h"

/* library for standard I/O */
#include <stdio.h>

/* library including memory allocation */
#include <stdlib.h>

typedef struct node * movieList;

typedef struct node {
  Picture pic;
  movieList next;
} movieNode;

/* ----------------  function prototypes -------------------*/

/* add a given picture to the end of the movieList specified by first 
   algorithm:
      a new node is created
         the pic field of the node is set to frame
         the next field is set to NULL
      if first is NULL, first is changed to point to the new node
      otherwise, the next field of the last node is set to the new node
*/
void addPicture (movieList * first, Picture frame);

/* the movie is printed from first item to last, with a short delay
   between successive frames */
void printForward (movieList first);

/* the movie is printed from last item to first, with a short delay
   between successive frames */
void printReverse (movieList first);

/* -------------------  main program ----------------------*/
 
int main (void) {
  /* program that takes a movie*/ 
  printf ("Starting program:  ");
  rConnect ("/dev/rfcomm0");
  rSetForwardness("fluke-forward");

  printf ("program asking Scribbler 2 to take and display pictures\n");
  /* determine how many pictures */

  movieList movie = NULL;  /* the initial movie list contains no pictures */
  int numPics = 0; /* counter for the number of pictures */

  /* take pictures until program aborted */
  while (1) 
    {
      /*take picture and turn left a little */
      Picture frame = rTakePicture();
      rTurnLeft (0.3, 0.3);

      /* add frame to movie */
      addPicture (&movie, frame);
      numPics++;

      /* display move forward and backward every 10 frames */
      if (numPics % 10 == 0)
        {
          printForward (movie);
          printReverse (movie);
        }
    }

  /* the following lines look good, but are never executed, 
     because the main loop does not terminate */
  printf ("Closing connection to robot....");
  rDisconnect();
  printf (" finished.\n\n");
}
 
/* ------------------  function details --------------------*/

/* add a given picture to the end of the movieList specified by first 
   algorithm:
      a new node is created
         the pic field of the node is set to frame
         the next field is set to NULL
      if first is NULL, first is changed to point to the new node
      otherwise, the next field of the last node is set to the new node
*/
void addPicture (movieList * first, Picture frame)
{
  printf ("not yet implemented\n");
}

/* the movie is printed from first item to last, with a short delay
   between successive frames */
void printForward (movieList first)
{
  printf ("not yet implemented\n");
}

/* the movie is printed from last item to first, with a short delay
   between successive frames */
void printReverse (movieList first)
{
  printf ("not yet implemented\n");
}
