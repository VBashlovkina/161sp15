/* program to read 10 integers from "integer.file"       *
 *             and 10 real numbers from "real.file"      */

#include <stdio.h>

int main (void)
{  FILE *intfile, *realfile;

   int i;
   double r;

   /* read integer values from "integer.file" */
   printf ("The integers from 'integer.file' follow:\n");
   intfile = fopen ("integer.file", "r");  /* open file for reading */

   while (fscanf (intfile, "%d", &i) != EOF) 
      /* continue until scanf returns EOF */
      { printf ("%10d\n", i); 
      }

   fclose (intfile);

   printf ("Integer file processed\n");

   /* read real values from "real.file" */
   printf ("The real numbers from 'real.file' follow:\n");

   realfile = fopen ("real.file", "r");

   while(fscanf (realfile, "%lf", &r) != EOF) {
     printf ("%10.5f\n", r);
   }

   fclose (realfile);

   printf ("Real file processed\n");

   return 0;
}
