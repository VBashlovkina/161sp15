/* This program demonstrates formatted integer input*/

#include <stdio.h>

int A, B;						

main ()				
   {printf ("Test of d format\n");
    printf ("Enter two digits  ");
    scanf  ("%1d %1d",&A,&B);
    printf ("The digits in reverse order are %1d%1d\n", B,A);
    }	

