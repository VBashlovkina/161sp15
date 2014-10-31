#include <stdio.h>

int
main()
{
  int i; // counter variables initialized to 0

  int array3[2][2] = {{5, 3}, {2, 1}};
  int array1[][3] = {{4, 5, 3}, {5, 3, 5}, {5, 2, 8}};
  int array2[][5] = {{3, 4, 1}, {6, 3, 2, 4, 1}, {3, 5}};
  //int array4[3][] = {{2, 4, 3}, {4, 4, 1}, {1, 2, 3}};
  //int array5[][] = {{3, 2, 1}, {4, 3, 2}, {2, 4, 6}};

  printf ("array1 size = %d\n", sizeof(array1)); 
  for (i = 0; i < 3; i++)
    printf ("\tsize of row %d:  %d\n", i, sizeof(array1[i]));
  printf("\n");

  printf ("array2 size = %d\n", sizeof(array2)); 
  for (i = 0; i < 3; i++)
    printf ("\tsize of row %d:  %d\n", i, sizeof(array2[i]));
  printf("\n");

  printf ("array3 size = %d\n", sizeof(array3)); 
  for (i = 0; i < 3; i++)
    printf ("\tsize of row %d:  %d\n", i, sizeof(array3[i]));
  printf("\n");



} // main
