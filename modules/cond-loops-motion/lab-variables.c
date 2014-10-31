#include <stdio.h>
/* program for Part 1 of lab-types-variables.shtml */

int main ()
{ /* step 1 */
  int a = 5;
  int b = 6;
  int c = a/b;
  int d = b/a;
  int e = (a + b) / 10;
  int f = (a + b) % 10;
  double x = (a + b) / 10;
  double y = (a + b) / 10.0;
  printf ("a=%d, b=%d, c=%d, d=%d, e=%d, f=%d, x=%lf, y=%lf\n", a, b, c, d, e, f, x, y);

  /* step 2 */
  int k = 5.0;
  int m = 7.7;
  double n = 5;
  int p = k/m;
  double q = k/m;
  printf ("k = %d, m=%d, n=%lf, p=%d, q=%lf\n", k, m, n, p, q);
  double r = (double) (k/m);
  double s = (double) k / m;
  double t = k / (double) m;
  double u = (double) k / (double) m;
  printf ("r=%lf, s=%lf, t=%lf, u=%lf\n", r, s, t, u);

  double days = 7;
  days++;
  printf ("days = %lf\n", days);
}
