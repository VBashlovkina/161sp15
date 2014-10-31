#include <stdio.h>

/* Supplemental Problem 2 Sample Code
   this program performs a computation and prints the results,
   based on data in arrays
*/

/* function computes results based on value and n */
/* pre-conditions:  value is a double
                    n is an int
   post-conditions: double is returned
*/
double compute_neg_power (double value, int n);

/* function computes results based on 3 parameters */
/* pre-conditions:  ann rate and amt are doubles
                    years is an int
   post-conditions: double is returned
*/
double compute_payment (double annRate, int years, double amt);

/* three parameters are used to compute a result */
/* pre-conditions:  ann Rate is a double
                    years is an int
                    amt is a double
   post-conditions: double is returned
*/
double total_paid(double annRate, int years, double amt);

/* the main procedure starts here */
int main ()
{
  int numCases = 4;  /* declared int variable numCases is set to 4 */
  /* double array is declared and initialized */
  double annualRate[] = {   8.75,     5.35,      5.35,     4.35 };
  int    years []     = {   25  ,    30   ,     30   ,     35   };
  /* double array is declared and initialized */
  double amount []    = {26000.0, 90000.00,  90000.00,  90000.00};

  /* printf writes "Mortgate Payment Table" as a line of output */
  printf ("Mortgage Payment Table\n");
  /* printf statement writes another line of output */
  printf ("annual rate  years    amount  monthly payment   total paid\n");

  int i;  /* i declared as an int */
  /* for loop with i starting at 0
              continuing until i < numCases
              incrementing i by 1 after each iteration */
  for (i = 0; i < numCases; i++)
    {
      /* payment declared as a double and given the value of a function */
      double payment = compute_payment (annualRate[i], years[i], amount[i]);
      /* total dclared as a function and given result after function call */
      double total = total_paid (annualRate[i], years[i], amount[i]);
      /* printf of 1 double, followed by an int, followed by 3 doubles */
      printf ("%8.2lf %7d %12.2lf% 11.2lf %16.2lf\n",
              annualRate[i], years[i], amount[i], payment, total);
    }
  /* return the value 0 */
  return 0;
}

/* function computes results based on value and n */
/* pre-conditions:  value is a double
                    n is an int
   post-conditions: double is returned
*/
double compute_neg_power (double value, int n)
{
  /* comments on the right used here for variety */
  double result = 1.0;      /* double initialized to 1.0 */
  int i;                    /* i declared as an int */
  for (i = 1; i <= n; i++)  /* for loop starts at 1, tests i <= n,
                               and increments by 1 each iteration */
    result *= value;        /* result multiplied by value */
  return 1.0 / result;      /* return 1.0 divided by result */
}

/* function computes results based on 3 parameters */
/* pre-conditions:  ann rate and amt are doubles
                    years is an int
   post-conditions: double is returned
*/
double compute_payment (double annRate, int years, double amt)
{
  /* variable monthlyRate declared as a double and initialized */
  double monthlyRate = annRate / 1200.0;
  /* computation involving addition, subtraction, multiplication, 
     and division made.  computation also involves a function call
     result is returned */
    return amt * monthlyRate / 
                (1.0 - compute_neg_power((1 + monthlyRate), (12*years)));
}

/* three parameters are used to compute a result */
/* pre-conditions:  ann Rate is a double
                    years is an int
                    amt is a double
   post-conditions: double is returned
*/
double total_paid(double annRate, int years, double amt)
{
  /* variable PaymentInCents initialized after function call and computations */
  int paymentInCents = 
              (int) (compute_payment (annRate, years, amt) * 100.0 + 0.5);
  /* value returned is 12 times years times paymentInCents divided by 100.0 */
  return 12 * years * paymentInCents / 100.0;
}
