/*  Program to play a modified game of Scrabble
    Details of the problem are given at
       http://www.cs.grinnell.edu/~walker/courses/161.sp14/suppl-prob.shtml#4

    Approach 2:
       input using getchar for text, scanf for numbers
       much work done in main
       auxiliary procedures:
         check_horizontal:  determine if word fits horizontally at given place
         check_vertical:  determine if word fits verticaly at given place

       notes:  for random placement, all candidates checked and one selected
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int num_words_added = 0;   // number of words currently inserted into board

/* check if the given word can be added horizontally at the given location
   pre-conditions
      row is a valid row location within the grid
      col is a valid column location within the grid
      word is a valid string
      num_rows is the total number of rows in the grid
      num_cols is the total number of columns in the grid
      grid is the two-dimensional array representing the grid
      uses global variable num_words_added to determine if grid empty
   post-conditions
      returns true (i.e., 1) if the word can be added to the grid
              horizontally with the first letter at the given row and col
      returns false (i.e., 0) otherwise
      the grid is NOT changed
*/
int check_horizontal (char * word, int row, int col, 
                      int num_rows, int num_cols, char grid[num_rows][num_cols])
{
  if ((0 <= row) && (row < num_rows) &&
      (0 <= col) && (col+strlen(word) < num_cols))
    {
      int count_overlap = 0;
      int i;
      for (i = 0; i < strlen(word); i++)
        {
          if (grid[row][col+i] == word[i])
            count_overlap++;
          else if (grid[row][col+i] != ' ')
            return 0;
        }
      return (num_words_added == 0) || (count_overlap > 0);
    }
  else
    return 0;   // word does not fit horizontally in grid at given point
}

/* check if the given word can be added horizontally at the given location
   pre-conditions
      row is a valid row location within the grid
      col is a valid column location within the grid
      word is a valid string
      num_rows is the total number of rows in the grid
      num_cols is the total number of columns in the grid
      grid is the two-dimensional array representing the grid
      uses global variable num_words_added to determine if grid empty
   post-conditions
      returns true (i.e., 1) if the word can be added to the grid
              vertically with the first letter at the given row and col
      returns false (i.e., 0) otherwise
      the grid is NOT changed
*/
int check_vertical (char * word, int row, int col, 
                      int num_rows, int num_cols, char grid[num_rows][num_cols])
{
  if ((0 <= row) && (row+strlen(word) < num_rows) &&
      (0 <= col) && (col < num_cols))

    {
      int count_overlap = 0;
      int j;
      for (j = 0; j < strlen(word); j++)
        {
          if (grid[row+j][col] == word[j])
            count_overlap++;
          else if (grid[row+j][col] != ' ')
            return 0;
        }
      return (num_words_added == 0) || (count_overlap > 0);
    }
  else
    return 0;   // word does not fit vertically in grid at given point
}

/* procedure to control overall processing
 */
int main ()
{
  printf ("program to play a simplified game of Scrabble\n");
  int num_rows, num_cols;
  printf ("enter size of board (rows columns):\n");
  scanf ("%d %d", &num_rows, &num_cols);

  /* declare and initialize variables */
  char grid[num_rows][num_cols];  // game board
  int i, j;
  for (i = 0; i < num_rows; i++)
    for (j = 0; j < num_cols; j++)
      grid[i][j] = ' ';
  printf ("working with a %d by %d board\n", num_rows, num_cols);

  /* remove any characters remaining on line, include '\n' */
  while (getchar() != '\n');

  char word[num_rows + num_cols]; // word to be added to board
  int row, col;                   // where word to be placed, if known

  /* set up random number generator */
  srand (time ((time_t *) 0) );

  /* main loop to read new words and placements */
  while (1)
    {
      printf ("enter word, mode (H, V, R), and row, column, as needed\n");
      char mode;  // mode:  H (horizontal), V (vertical), R (random)
      /* read first word from input and convert word to upper case */
      i = 0;
      while (isalpha(word[i] = toupper(getchar())))
        i++;
      word[i] = 0;  // add null at end of word

      // if QUITQUIT entered, no need for further processing
      if (strcmp (word, "QUITQUIT") == 0)
        break;

      /* read next non-white-space character as mode (H, V, R) */
      while (isspace(mode = toupper(getchar())));

      if (mode == 'H')
        {/* horizontal processing */
          scanf ("%d %d", &row, &col);
          printf ("checking horizontal insertion of %s at (%d, %d)\n", word, row, col);
          /* check if word fits letters on board */
          if (check_horizontal (word, row, col, num_rows, num_cols, grid))
            {
              for (i = 0; i < strlen(word); i++)
                grid[row][col+i] = word[i];
              num_words_added++;
            }
          else
            printf ("word conflicts with board at row/col\n");
        }

      else if (mode == 'V')
        {/* vertical processing */
          scanf ("%d %d", &row, &col);
          printf ("checking vertical insertion of %s at (%d, %d)\n", word, row, col);
          /* check if word fits letters on board */
          if (check_vertical (word, row, col, num_rows, num_cols, grid))
            {
              for (j = 0; j < strlen(word); j++)
                grid[row+j][col] = word[j];
              num_words_added++;
            }
          else
            printf ("word conflicts with board at row/col\n");
        }

      else if (mode == 'R')
        {/* random processing */
          /* find all possible places for word insertion and chose one */
          /* store choices in an array of structs */
          struct {
            int row;
            int col;
            char mode;
          } choices [num_rows*num_cols];
          int num_choices = 0;
          /* check horizontal choices */
          for (i = 0; i < num_rows; i++)
            for (j = 0; j < num_rows - strlen(word); j++)
              if (check_horizontal (word, i, j, num_rows, num_cols, grid))
                {
                  choices[num_choices].row = i;
                  choices[num_choices].col = j;
                  choices[num_choices].mode = 'H';
                  num_choices++;
                }
          /* check vertical choices */
          for (i = 0; i < num_rows - strlen(word); i++)
            for (j = 0; j < num_rows; j++)
              if (check_vertical (word, i, j, num_rows, num_cols, grid))
                {
                  choices[num_choices].row = i;
                  choices[num_choices].col = j;
                  choices[num_choices].mode = 'V';
                  num_choices++;
                }
          if (num_choices == 0)
            printf ("word cannot be placed in grid\n");
          else
            {
              int rand_choice = rand () % num_choices;
              if (choices[rand_choice].mode == 'H')
                { /* insert horizontally */
                  row = choices[rand_choice].row;
                  col = choices[rand_choice].col;
                  for (i = 0; i < strlen(word); i++)
                    grid[row][col+i] = word[i];
                }
              else
                { /* insert vertically */
                  row = choices[rand_choice].row;
                  col = choices[rand_choice].col;
                  for (j = 0; j < strlen(word); j++)
                    grid[row+j][col] = word[j];
                }
              num_words_added++;
            }
        }
      /* print current state of board */
      printf ("current state of the Scrabble board:\n   ");
      for (i = 0; i < num_rows; i++)
        {
          for (j = 0; j < num_cols; j++)
            printf (" %c", grid[i][j]);
          printf ("\n   ");
        }

      /* remove any characters remaining on line, include '\n' */
      while (getchar() != '\n');
         
   } /* end main processing loop */

  printf ("game over with %d words inserted\n\n", num_words_added);

  return 0;
}
