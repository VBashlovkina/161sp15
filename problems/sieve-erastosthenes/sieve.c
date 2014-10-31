/* this program compares methods for determining the number of non-trivial
   factors for each integer in a range 2..M, for various values of M

   method 1:  Sieve of Erastosthenes
   method 2:  examine each number smaller than a given integer/2

   Time for each method is recorded

   Results of the two methods are compared to help check correctness
   Results of the first 100 integers are printed

   Integers with the three largest counts are printed
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


/* precondition:  arr is an array of size M+1
   postcondition: arr[i] contains the number of non-trivial factors 
                    of integer i
*/
void computeFactors1 (int arr[], int M)
{
  int i, j;
  /* initialize counts */
  for (i = 2; i <= M; i++)
    {
      arr[i] = 0;
    }

  /* apply the sieve; variable i gives the base number
                      variable j records multiples of j
  */
  for (i = 2; i <= M/2; i++)
    for (j = 2*i; j <= M; j+= i)
      arr[j]++;
}

/* precondition:  arr is an array of size M+1
   postcondition: arr[i] contains the number of non-trivial factors 
                    of integer i
*/
void computeFactors2 (int arr[], int M)
{
  int i, j;
  /* initialize counts */
  for (i = 2; i <= M; i++)
    {
      arr[i] = 0;
    }

  /* find non-trivial factors integer-by-integer 
                    variable i gives number to be checked
                    variable j represents possible factors
  */
  for (i = 2; i <= M; i++)
    for (j = 2; j < i; j++)
      {
        if (i % j == 0)
          arr[i]++;
      }
}

/* pre-conditions:  none
   post-conditions: three methods for computing integers factors 
                       are utilized, timed, and compared
                    timings given for M = 1000, 10000, 100000, 1000000
                    three numbers with highest counts are printed
                    counts for the first 100 integers are printed
*/                

int arr1 [10000001];
int arr2 [10000001];
int arr3 [10000001];

int main ()
{
  int i;
  clock_t start_time, end_time;
  double elapsed_time;

  /* print table titles */
  printf ("timing to determine number of non-trivial integer factors\n");
  printf ("             Sieve     All Factors Arrays");
       printf ("       3 integers with the largest counts\n");
  printf ("      M      Method       Method    Agree");
       printf ("    max1:count1::   max2:count2::   max3:count3\n\n");

  int M;
  for (M = 10; M <= 1000000; M*= 10)
    {
      printf ("%8d", M);

      /* Use Sieve of Erastosthenes */
      start_time = clock ();
      computeFactors1 (arr1, M);
      end_time = clock();

      elapsed_time = (end_time - start_time) / (double) CLOCKS_PER_SEC;
      printf (" %10.3lf", elapsed_time);


      /* Examine each number smaller than a given integer/2 */
      start_time = clock ();
      computeFactors2 (arr2, M);
      end_time = clock();

      elapsed_time = (end_time - start_time) / (double) CLOCKS_PER_SEC;
      printf (" %12.3lf", elapsed_time);

      /* check the two arrays have same counts */
      int diff = 0;
      for (i = 2; i <= M; i++)
        {
          if (arr1[i] != arr2[i])
            {
              diff = 1;
              break;
            }
        }
      if (diff == 0)
        printf ("     yes  ");
      else
        printf ("      no  ");

      /* find 3 integers with largest counts */
      int maxint1 = 4;
      int maxint2 = 3;
      int maxint3 = 2;

      for (i = 5; i <= M; i++)
        {
          if (arr1[maxint1] < arr1[i])
            {  /* count i larger than all previous */
              maxint3 = maxint2;
              maxint2 = maxint1;
              maxint1 = i;
            }
          else if (arr1[maxint2] < arr1[i])
            {  /* count i larger than smaller 2 maximums */
              maxint3 = maxint2;
              maxint2 = i;
            }
          else if (arr1[maxint3] < arr1[i])
            {  /* count i larger than third-largest maximum */
              maxint3 = i;
            }
        }     

      printf ("%7d:%-4d  ::%7d:%-4d  ::%7d:%-4d\n", maxint1, arr1[maxint1], 
              maxint2, arr1[maxint2], maxint3, arr1[maxint3]);
          
      printf ("\n");

    }

     /* printf first 100 numbers and their counts */
      printf ("\n\ncounts for the first several integers\n");
      for (i = 2; (i <= M) && (i <= 100); i++)
        { 
          printf ("%6d:%-6d ", i, arr1[i]);
          if (i % 8 == 1)
            printf ("\n");
        }
      printf ("\n\n");


  return 0;
}


/*
Output:
timing to determine number of non-trivial integer factors
             Sieve     All Factors Arrays       3 integers with the largest counts
      M      Method       Method    Agree    max1:count1::   max2:count2::   max3:count3

      10      0.000        0.000     yes        6:2     ::      8:2     ::     10:2   

     100      0.000        0.000     yes       60:10    ::     72:10    ::     84:10  

    1000      0.000        0.000     yes      840:30    ::    720:28    ::    960:26  

   10000      0.000        0.190     yes     7560:62    ::   9240:62    ::   5040:58  

  100000      0.000       19.330     yes    83160:126   ::  98280:126   ::  55440:118 

 1000000      0.300     1931.290     yes   720720:238   :: 831600:238   :: 942480:238 



counts for the first several integers
     2:0           3:0           4:1           5:0           6:2           7:0           8:2           9:1      
    10:2          11:0          12:4          13:0          14:2          15:2          16:3          17:0      
    18:4          19:0          20:4          21:2          22:2          23:0          24:6          25:1      
    26:2          27:2          28:4          29:0          30:6          31:0          32:4          33:2      
    34:2          35:2          36:7          37:0          38:2          39:2          40:6          41:0      
    42:6          43:0          44:4          45:4          46:2          47:0          48:8          49:1      
    50:4          51:2          52:4          53:0          54:6          55:2          56:6          57:2      
    58:2          59:0          60:10         61:0          62:2          63:4          64:5          65:2      
    66:6          67:0          68:4          69:2          70:6          71:0          72:10         73:0      
    74:2          75:4          76:4          77:2          78:6          79:0          80:8          81:3      
    82:2          83:0          84:10         85:2          86:2          87:2          88:6          89:0      
    90:10         91:2          92:4          93:2          94:2          95:2          96:10         97:0      
    98:4          99:4         100:7      


 */


