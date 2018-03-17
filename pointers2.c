#include <stdio.h>
#include <cs50.h>

int main( int argc, char *argv[])
{
  (void)argc;
  (void)argv;

  int k = get_int("Enter a value for int k: ");
  int *pk = &k;
  printf("setting the value of *pk to the address of k\n");
  printf("int k: %i\n", k);
  printf("*pk: %i\n\n", *pk);

  *pk = get_int("Enter a new value for int *pk: ");
  printf("int k: %i\n", k);

  int *pk2 = &k;
  int *pk3 = &k;
  int *pk4 = &k;

  k = get_int("Enter a new value for int k: ");
  printf("int *pk: %i\n", *pk);
  printf("int *pk2: %i\n", *pk2);
  printf("int *pk3: %i\n", *pk3);
  printf("int *pk4: %i\n\n", *pk4);


  k = get_int("Enter a new value for int *pk3: ");
  printf("int *pk: %i\n", *pk);
  printf("int *pk2: %i\n", *pk2);
  printf("int *pk3: %i\n", *pk3);
  printf("int *pk4: %i\n", *pk4);

  printf("\n---\n");

  int m = get_int("enter a value for int m: ");
  int *pm = &m;

  printf("*pm = &m; \n int address of m: %i\n", *pm);
}
