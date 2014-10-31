#include <stdio.h>

void func (int m, int *c, int a[]) {
  printf ("Initial addresses and values in function\n");
  printf ("              m:       %12u\t  %12d\n", &m, m);
  printf ("              c:       %12u\t  %12u\t    %12d\n", &c, c, *c);
  printf ("  array base address:  %12u\t  %12d\n", a, *a);
  printf ("              a[0]:    %12u\t  %12d\n", &a[0], a[0]);
  printf ("              a[1]:    %12u\t  %12d\n", &a[1], a[1]);
  printf ("              a[2]:    %12u\t  %12d\n", &a[2], a[2]);
  printf ("              a[3]:    %12u\t  %12d\n", &a[3], a[3]);

  /* change parameter values */
  m = -2000;
  *c = -200;
  int i;
  for (i = 0; i < 4; i++)
    a[i] = -a[i] - 50;

  printf ("Final addresses and values in function\n");
  printf ("                  m:   %12u\t  %12d\n", &m, m);
  printf ("                  c:   %12u\t  %12u\t    %12d\n", &c, c, *c);
  printf ("  array base address:  %12u\t  %12d\n", a, *a);
  printf ("                a[0]:  %12u\t  %12d\n", &a[0], a[0]);
  printf ("                a[1]:  %12u\t  %12d\n", &a[1], a[1]);
  printf ("                a[2]:  %12u\t  %12d\n", &a[2], a[2]);
  printf ("                a[3]:  %12u\t  %12d\n", &a[3], a[3]);

}

int main () 
{ 
  int thou;
  int hund;
  int arr[4];
  int i;

  printf ("           variable        address\t        value\t       referenced value\n");

  printf ("Addresses and uninitialized values in main\n");
  printf ("                thou:  %12u\t  %12d\n", &thou, thou);
  printf ("                hund:  %12u\t  %12d\n", &hund, hund);
  printf ("  array base address:  %12u\t  %12d\n", arr, *arr);
  printf ("              arr[0]:  %12u\t  %12d\n", &arr[0], arr[0]);
  printf ("              arr[1]:  %12u\t  %12d\n", &arr[1], arr[1]);
  printf ("              arr[2]:  %12u\t  %12d\n", &arr[2], arr[2]);
  printf ("              arr[3]:  %12u\t  %12d\n", &arr[3], arr[3]);

  /* initialize values */
  thou = 1000;
  hund = 100;
  for (i = 0; i < 4; i++)
    arr[i] = 10000 * i;

  printf ("Addresses and values after initialization in main\n");
  printf ("                thou:  %12u\t  %12d\n", &thou, thou);
  printf ("                hund:  %12u\t  %12d\n", &hund, hund);
  printf ("  array base address:  %12u\t  %12d\n", arr, *arr);
  printf ("              arr[0]:  %12u\t  %12d\n", &arr[0], arr[0]);
  printf ("              arr[1]:  %12u\t  %12d\n", &arr[1], arr[1]);
  printf ("              arr[2]:  %12u\t  %12d\n", &arr[2], arr[2]);
  printf ("              arr[3]:  %12u\t  %12d\n", &arr[3], arr[3]);

  func (thou, &hund, arr);

  printf ("Values after call to function in main\n");
  printf ("              thou:    %12u\t  %12d\n", &thou, thou);
  printf ("              hund:    %12u\t  %12d\n", &hund, hund);
  printf ("  array base address:  %12u\t  %12d\n", arr, *arr);
  printf ("              arr[0]:  %12u\t  %12d\n", &arr[0], arr[0]);
  printf ("              arr[1]:  %12u\t  %12d\n", &arr[1], arr[1]);
  printf ("              arr[2]:  %12u\t  %12d\n", &arr[2], arr[2]);
  printf ("              arr[3]:  %12u\t  %12d\n", &arr[3], arr[3]);

}
