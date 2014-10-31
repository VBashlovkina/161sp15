/* example to show decoding numbers within command-line arguments */

#include <stdio.h>
#include <string.h>   /* includes strlen  */
#include <stdlib.h>   /* includes strtod, atoi  */
/* atoi and atof convert string to integer and double, respectively
   however, these do not detect errors, but return 0 for invalid input

   strtod converts string to a double
   second parameter tells location of last character coverted
   if second parameter points to NULL, entire string has been converted
*/

#include <ctype.h>    /* includes isdigit */

#define line_size 500

int isInt (char str [])
{ /* determines if str is string version of an integer */
  /* assumes str is a valid C string */
  int i;
  /* check if sign in first character */
  if (str[0] == '+' || str[0] == '-')
    i = 1; /* digits start in position 1 */
  else
    i = 0; /* digits start in position 0 */

  do
    { /* check subsequent characters are digits */
      if (!isdigit(str[i]))
        return 0;
      i++;
    }
  while (i < strlen(str));
  return 1;
}

int main(int argc, char *argv [])
{
  printf ("this program adds all numbers on the command line,\n");
  printf ("ignoring items on the command line that are not numbers.\n");

  double sum = 0;
  int i = 1;
  while (i < argc)
    {
      printf ("\tparameter %2d:   %s", i, argv[i]);

      if (isInt(argv[i]))
        { /* convert alphanumeric string to integer */
          printf ("\t--- integer\n");
          int i_value = atoi(argv[i]);
          sum += i_value;
        }
      else
        { /* try converting string to double */
          char* endptr;
          double d_value = strtod (argv[i], &endptr);
          if (*endptr != 0)
            {
              printf ("\t--- not a number\n");
            }
          else
            {
              printf ("\t--- double precision number\n");
            sum += d_value;
            }
        }
      i++;
    }
  

  printf ("\nthe sum of the command line arguments is %lf\n", sum);

  return 0;
}
