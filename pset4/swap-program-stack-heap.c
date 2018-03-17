#include <stdio.h>
#include <cs50.h>

int swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
  return 0;
}

int main(void)
{
  int a = 1;
  int b = 2;
  printf("integer a before swap: %i\n", a);
  printf("integer b before swap: %i\n", b);
  
  swap(&a, &b);
  
  printf("integer a after: %i\n", a);
  printf("integer b after: %i\n", b);
}
