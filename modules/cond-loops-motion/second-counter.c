#include <stdio.h>
#include <stdlib.h>

int
main()
{
  /* declare the seconds as an integer */
  int seconds;

  /* generate a random integer and call it seconds */
  srand(time(0));
  seconds = rand()%10 ;

  /*tell me how many up to how many seconds we will count */
  printf("I will count to %d seconds....\n", seconds);

  /* make different cases to tell the program what to print in any case */
  switch (seconds)
    {
    case 1:
      printf("One Mississippi!\n");
      break;
    case 2:
      printf("One Mississippi! Two Mississippi!\n");	
      break;
      case 3:
      printf("One Mississippi! Two Mississippi! Three Mississippi!\n");
      break;
    case 4:
      printf("One Mississippi! Two Mississippi! Three Mississippi! Four Mississippi!\n");
      break;
    case 5:
      printf("One Mississippi! Two Mississippi! Three Mississippi! Four Mississippi! Five Mississippi!\n");
      break;
    default:
      printf("Oh Susanna, oh don't you cry for me. I come from Alabama with a banjo on my knee!\n");
      break;
    }

  return 0;
}
