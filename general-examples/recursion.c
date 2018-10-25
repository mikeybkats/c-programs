#include <stdio.h>
#include <cs50.h>

int reduce(int *value)
{
  printf("Reducing %i by 1.\n", *value);
  *value = *value - 1;

  if(*value > 0)
  {
    reduce(value);
  }

  return 0;
}

int main(void)
{
  int redNum = get_int("Enter a number to recursively reduce: ");  
  
  reduce(&redNum);

  printf("Final value: %i\n", redNum);
}
