/* program to write 10 random integers to "integer.file"          *
 *              and 10 random real numbers to "real.file"         */


#include <stdio.h>  /* library for both keyboard and keyboard I/O */

#include <stdlib.h> /* libraries for the random number generator  */
#include <time.h>
/*   time, from time.h,  returns a value based upon the time of day         *
 *   rand , from stdlib.h, returns a random integer between 0 and MaxRandInt*
 *      the value of MaxRandInt is machine dependent:                       *
 *          2^32-1 = 2147483647 for SparkStations,                          * 
 *          2^15-1 = 32767 for IBM Xstation 140s and HP 712/60s             */
#define MaxRandInt  32767

int main (void)
{  FILE  *file1, *file2;	/* output files */
   int i;
   int ival;
   double rval;
   double MaxRandReal = (double) MaxRandInt;  /* make MaxRandInt a real */
   
   /* initialize random number generator                                *
    * change seed to the random number generator, based on time of day  */
   printf ("initializing random number generator\n");
   srand (time ((time_t *) 0) );

   /* place integer values on first file */
   printf ("generating file of integers\n");
   file1 = fopen ("integer.file", "w"); /* open file for writing */

   for (i = 1; i <= 10; i++)
       { ival = rand ();   		/* two lines could be abbreviated */
         fprintf (file1, "%d\n", ival);}
   fclose (file1);

   /* place real values on second file */
   printf ("generating file of reals\n");
   file2 = fopen ("real.file", "w");

   for (i = 1; i <= 10; i++)
       { fprintf (file2, "%f\n", rand() / MaxRandReal);}
   fclose (file2);

   printf ("writing of files completed\n");
   return 0;
}
