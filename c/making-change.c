/* program to determine number of bills needed to make change
 * Cost of shopping and amount paid specified in initial variables
 * pre-conditions:
 *    cost >= 0.00; paid >= 0.00
 *    paid >= cost
 * post-conditions:
 *    number of twenties, tens, fives and ones printed for change
 *    fewest number of bills determined
 */

#include <stdio.h>

int main ()
{
  /* identify initial values */
  double cost = 55.55;
  double paid = 100.00;
  int billsNeeded = int (paid - cost);
  double coinsNeeded = paid - cost - billsNeeded;

  /* compute twenties */
  int twenties = billsNeeded / 20;
  billsNeeded = billsNeeded % 20;

  /* compute tens */
  int tens = billsNeeded / 10;
  billsNeeded = billsNeeded % 10;

  /* compute fives */
  int fives = billsNeeded / 5;

  /* compute ones */
  int ones = billsNeeded % 5;


  printf ("cost:  %.2lf\n", cost);
  printf ("paid:  %.2lf\n", paid);

  if (twenties == 1)
    printf ("1 twenty\n");
  else
    printf ("%d twenties\n", twenties);


  return 0;
}
