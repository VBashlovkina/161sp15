#include <stdio.h>

/* Supplemental Problem 2 Sample Code
   Program computes the monthly total and total amount paid for 
      mortgages of varying loan amounts, years, and percentage rates
   Results are displayed as a table
*/

/* computes a number, raised to a negative power */
/* pre-conditions:  value is nonzero
                    n is a positive integer
   post-conditions:  returns (value) ^ (-n)
*/
double compute_neg_power (double value, int n);

/* computes the monthly payment for a mortgage */
/* pre-conditions:  annRate is a positive annual rate (given as a percentage)
                    years is the duration of the mortgage (assumed positive)
                    amt is the amount of the loan (assumed positive)
   pre-conditions:  returns the monthly payment 
                            computed to several decimal places
*/
double compute_payment (double annRate, int years, double amt);

/* computes the total amount paid for a mortgage over its lifetime */
/* pre-conditions:  annRate is a positive annual rate (given as a percentage)
                    years is the duration of the mortgage (assumed positive)
                    amt is the amount of the loan (assumed positive)
   pre-conditions:  total cost of the loan is based upon the
                          monthly payment, rounded to the nearest penny
*/
double total_paid(double annRate, int years, double amt);

/* coordinate processing of mortgage table */
int main ()
{
  /* numCases indicates number of mortgages in table
     parallel arrays indicate the terms for each mortgage */
  int numCases = 4;
  double annualRate[] = {   8.75,     5.35,      5.35,     4.35 };
  int    years []     = {   25  ,    30   ,     30   ,     35   };
  double amount []    = {26000.0, 90000.00,  90000.00,  90000.00};

  /* print table headers */
  printf ("Mortgage Payment Table\n");
  printf ("annual rate  years    amount  monthly payment   total paid\n");

  /* print successive lines of the table */
  int i;
  for (i = 0; i < numCases; i++)
    {  /* gather amounts for one line and print in column format */
      double payment = compute_payment (annualRate[i], years[i], amount[i]);
      double total = total_paid (annualRate[i], years[i], amount[i]);
      printf ("%8.2lf %7d %12.2lf% 11.2lf %16.2lf\n",
              annualRate[i], years[i], amount[i], payment, total);
    }
  return 0; /* program ran without error */
}

/* computes a number, raised to a negative power */
/* pre-conditions:  value is nonzero
                    n is a positive integer
   post-conditions:  returns (value) ^ (-n)
*/
double compute_neg_power (double value, int n)
{
  /* accumulate value ^ n by successive multiplications of value */
  double result = 1.0;
  int i;
  for (i = 1; i <= n; i++)
    result *= value;
  /* negative power is 1 / positive power */
  return 1.0 / result;
}

/* computes the monthly payment for a mortgage */
/* pre-conditions:  annRate is a positive annual rate (given as a percentage)
                    years is the duration of the mortgage (assumed positive)
                    amt is the amount of the loan (assumed positive)
   pre-conditions:  returns the monthly payment 
                            computed to several decimal places
*/
double compute_payment (double annRate, int years, double amt)
{
  /* compute monthly interest rate as a decimal (from the given percentage)
     and return monthly payment
  */
  double monthlyRate = annRate / 1200.0;
  return amt * monthlyRate / 
                (1.0 - compute_neg_power((1 + monthlyRate), (12*years)));
}


/* computes the total amount paid for a mortgage over its lifetime */
/* pre-conditions:  annRate is a positive annual rate (given as a percentage)
                    years is the duration of the mortgage (assumed positive)
                    amt is the amount of the loan (assumed positive)
   pre-conditions:  total cost of the loan is based upon the
                          monthly payment, rounded to the nearest penny
*/
double total_paid(double annRate, int years, double amt)
{
  /* monthly payment rounded to the nearest penny */
  int paymentInCents = 
              (int) (compute_payment (annRate, years, amt) * 100.0 + 0.5);
  /* total cost of the mortgage returned to the nearest penny */
  return 12 * years * paymentInCents / 100.0;
}
