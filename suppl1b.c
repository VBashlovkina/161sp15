#include <stdio.h>

int main ()
{
  int pounds = 17;
  double pence = 32.85;
  double exchange_rate = 1.69759;  // dollars per pound

  //use cents for computations
  int dollars_and_cents = (100*pounds+pence)*exchange_rate;
  printf ("%d pounds %.2lf pence translates to $%.2lf\n", 
          pounds, pence, dollars_and_cents/100.0);

  int twenty_bills = dollars_and_cents / 2000;
int amount_left = dollars_and_cents % 2000;

return 0;
}
