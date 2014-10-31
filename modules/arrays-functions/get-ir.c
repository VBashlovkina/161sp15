/* * * * *
 * get-ir.c
 *
 * This program contains a function getIRParam which returns the values of
 * left and right IR sensors into the parameters passed to it.  Information 
 * about the values of the different variables is printed as well.
 *
 * Authors: David Cowden, Dilan Ustek
 *
 * Date created: 7 July 2011
 * Date revised: 21 July 2011 by Erik Opavsky
 */

#include "MyroC.h"
#include <stdio.h>

/***
 * Function declaration
 * getIRParam returns the value of the IR reading for the left and right sensor
 * into the parameters left and right.
 */
void getIRParam (int *left, int *right);

int
main ()
{
  // Connect to robot
  rConnect ("/dev/rfcomm0");

  printf ("\n- - - Inside main() - - -\n");

  // Make variables for the value from the left and right IR sensors
  int leftSensor  = 2;
  int rightSensor = 2;
  

  /* Print the values and the addresses of leftSensor and rightSensor */

  printf ("leftSensor =\t%d\t\trightSensor =\t%d\n", leftSensor, rightSensor);
  printf ("&leftSensor:\t%p\t&rightSensor:\t%p\n", &leftSensor, &rightSensor);

  /* Call the function getIRParam function giving it the _address_ of the int
   * variables leftSensor and rightSensor */
  // code here!

  // --

  

  printf ("\n- - - Inside main() - - -\n");

  // Print the result..
  printf ("leftSensor =\t%d\t\trightSensor =\t%d\n", leftSensor, rightSensor);
  // Print the address of leftSensor and rightSensor variables (the result)
  printf ("&leftSensor:\t%p\t&rightSensor:\t%p\n", &leftSensor, &rightSensor);
  
  // Disconnect from robot
  rDisconnect();
  
  return 0;
} // main


void 
getIRParam (int *left, int *right) 
{
  printf ("\n- - - Inside getIRParam() - - -\n");

  /* Print the values of left and right */
  printf ("left =\t\t%p\tright =\t\t%p\n", left, right);

  /* Print the addresses of left and right */
  printf ("&left:\t\t%p\t&right:\t\t%p\n", &left, &right);

  printf ("\n\tBefore left and right are set..\n");
  printf ("*left:\t\t%d\t\t*right:\t\t%d\n", *left, *right);


  // Store the value of the left sensor in the location referenced by left
  // code here!

  // --


  // Store the value of the right sensor in the location referenced by right
  // code here!

  // --



  // Print the values again..
  printf ("\tAfter left and right are set..\n");
  printf ("*left:\t\t%d\t\t*right:\t\t%d\n", *left, *right);


  return; // Return nothing..
} // getIRParam
