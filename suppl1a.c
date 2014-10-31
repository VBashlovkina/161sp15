#include <stdio.h>

int main ()
{
  int pounds = 17;
  double pence = 32.85;
  double exchange_rate = 1.69759;  // dollars per pound

  double dollars_and_cents = (pounds+pence/100.0)*exchange_rate; //could use cents (int) or dollars (double)?
  printf ("%d pounds %.2lf pence translates to $%.2lf\n", 
          pounds, pence, dollars_and_cents);

  // determine integer amount to be given in bills
  int bills = dollars_and_cents;

  int twenty_bills = bills / 20;
  int amount_left = bills % 20;



  int cents = 100*dollars_and_cents - 100*bills;
  return 0;
}
