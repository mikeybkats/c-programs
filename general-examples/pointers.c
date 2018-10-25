#include <stdio.h>
#include <cs50.h>

int main( int argc, char *argv[])
{
  (void)argc;
  (void)argv;

  int k = 5;
  int *pk = &k;

  printf("k is an integer that equals: %i\n", k);
  printf("&k is set to the address of k.\n");
  printf("Printing the value of *&k reveals: %i\n", *&k);
  printf("*pk = &k lets us change the value of k.\n\n");

  int l = get_int("Now enter a new integer, we will call it int l:");
  
  printf("Let's change k (%i) to the value of int l (%i).\n", k, l);
  printf("In other words *pk = l\n"); 

  *pk = l;

  printf("\n\nThe magic:\n\nint k = 5;\nint *pk = &k;\nint l = %i;\n*pk = l;\nk = %i;\n\n", l, l);

  /*printf("&k goes to the address of k and *pk lets us set a new value to the address: %i\n\n", *pk);*/
  
  /*int m = get_int("Now enter a new integer for int m:");*/
  
  /**pk = m;*/
  /*printf("The value of int m:  %i\n", m);*/
  /*printf("The value of the pointer *pk: %i\n", *pk);*/

}
